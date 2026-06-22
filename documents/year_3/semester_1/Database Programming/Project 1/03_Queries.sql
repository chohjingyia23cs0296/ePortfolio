USE ProjectMgmtDB;

-- C. Data Retrieval (DQL / SELECT)

-- 1. Filtering (WHERE, AND, OR, NOT, BETWEEN, LIKE, NULL)

-- Find 'High' priority tasks that are 'In Progress' OR 'To Do' (AND, OR)
SELECT task_name, status, priority
FROM Tasks
WHERE priority = 'High'
  AND (status = 'In Progress' OR status = 'To Do');

-- Find all employees who are NOT 'Junior Developer' (NOT)
SELECT first_name, last_name, job_title
FROM Employees
WHERE NOT job_title = 'Junior Developer';

-- Find all projects starting BETWEEN 2024-01-01 and 2024-06-30 (BETWEEN)
SELECT project_name, start_date
FROM Projects
WHERE start_date BETWEEN '2024-01-01' AND '2024-06-30';

-- Find all tasks with 'database' in the name (LIKE)
SELECT task_name, project_id
FROM Tasks
WHERE task_name LIKE '%database%';

-- Find all unassigned tasks (IS NULL)
SELECT task_name, status, priority
FROM Tasks
WHERE assignee_id IS NULL;

-- 2. Sorting (ORDER BY, LIMIT)

-- Get all employees, sorted by hire date (newest first) (ORDER BY)
SELECT first_name, last_name, hire_date
FROM Employees
ORDER BY hire_date DESC;

-- Get the 5 most recently hired employees (ORDER BY, LIMIT)
SELECT first_name, last_name, hire_date
FROM Employees
ORDER BY hire_date DESC
LIMIT 5;

-- 3. Aggregation (COUNT, SUM, AVG, MAX, MIN)

-- Get the total number of employees, total project budget (SUM), and avg budget (AVG)
SELECT
    COUNT(*) AS total_employees
FROM Employees;

SELECT
    SUM(budget) AS total_all_budgets,
    AVG(budget) AS average_project_budget
FROM Projects;

-- Get the earliest project start date (MIN) and latest due date (MAX)
SELECT
    MIN(start_date) AS first_project_start,
    MAX(due_date) AS last_project_due
FROM Projects;

-- 4. Grouping and filtering groups (GROUP BY, HAVING)

-- Count of tasks per project (GROUP BY)
SELECT project_id, COUNT(task_id) AS number_of_tasks
FROM Tasks
GROUP BY project_id;

-- Show employees who are assigned MORE THAN 2 tasks (GROUP BY, HAVING)
SELECT assignee_id, COUNT(task_id) AS task_count
FROM Tasks
WHERE assignee_id IS NOT NULL
GROUP BY assignee_id
HAVING task_count > 2;

-- 5. Numeric and string functions (ROUND, TRUNCATE, UPPER, LENGTH, CONCAT, SUBSTR)

-- Show average project budget, rounded to 2 decimal places (ROUND)
SELECT ROUND(AVG(budget), 2) AS rounded_avg_budget
FROM Projects;

-- Show average project budget, truncated (TRUNCATE)
SELECT TRUNCATE(AVG(budget), 0) AS truncated_avg_budget
FROM Projects;

-- Get employee full names in uppercase (CONCAT, UPPER)
SELECT UPPER(CONCAT(first_name, ' ', last_name)) AS full_name, job_title
FROM Employees;

-- Get the length of each project's name (LENGTH)
SELECT project_name, LENGTH(project_name) AS name_length
FROM Projects;

-- Get the email domain for each employee (SUBSTR, INSTR)
SELECT email, SUBSTR(email, INSTR(email, '@') + 1) AS email_domain
FROM Employees;

-- 6. Conditional logic (CASE WHEN)

-- Categorize tasks by priority level ('Urgent' or 'Normal')
SELECT task_name, priority,
    CASE
        WHEN priority = 'High' THEN 'Urgent'
        WHEN priority = 'Medium' THEN 'Normal'
        ELSE 'Low Priority'
    END AS priority_level
FROM Tasks;

-- 7. Subqueries (single-row, multiple-row, correlated)

-- (Single-row) Find tasks that are in the same project as task_id 10
SELECT task_name, project_id
FROM Tasks
WHERE project_id = (
    SELECT project_id
    FROM Tasks
    WHERE task_id = 10
);

-- (Multiple-row - NOT IN) Find employees who are NOT project managers
SELECT first_name, last_name, job_title
FROM Employees
WHERE emp_id NOT IN (
    SELECT DISTINCT manager_id
    FROM Projects
    WHERE manager_id IS NOT NULL
);

-- (Correlated) Find projects that have at least one 'High' priority task
SELECT p.project_name
FROM Projects p
WHERE EXISTS (
    SELECT 1
    FROM Tasks t
    WHERE t.project_id = p.project_id AND t.priority = 'High'
);

-- 8. Set operations (UNION, NOT EXISTS)

-- Get a combined list of all Employee names and Project names (UNION)
SELECT first_name FROM Employees
UNION
SELECT project_name FROM Projects;

-- (NOT EXISTS - alternative to subquery) Find employees with ZERO assigned tasks
SELECT e.first_name, e.last_name
FROM Employees e
WHERE NOT EXISTS (
    SELECT 1
    FROM Tasks t
    WHERE t.assignee_id = e.emp_id
);

-- 9. Joins (NATURAL, INNER, LEFT OUTER, SELF)

-- (INNER JOIN - 3 Tables) Get a full report: Employee, Task, and Project
SELECT
    e.first_name,
    e.last_name,
    t.task_name,
    t.status,
    p.project_name
FROM Employees e
JOIN Tasks t ON e.emp_id = t.assignee_id
JOIN Projects p ON t.project_id = p.project_id
ORDER BY e.first_name;

-- (LEFT OUTER JOIN) List ALL employees and the number of tasks they have
-- (Employees with 0 tasks will show 0)
SELECT
    e.first_name,
    e.last_name,
    COUNT(t.task_id) AS task_count
FROM Employees e
LEFT JOIN Tasks t ON e.emp_id = t.assignee_id
GROUP BY e.emp_id, e.first_name, e.last_name
ORDER BY task_count DESC;

-- (SELF JOIN) Find pairs of employees who have the same job title
SELECT
    a.first_name AS emp1_first, a.last_name AS emp1_last,
    b.first_name AS emp2_first, b.last_name AS emp2_last,
    a.job_title
FROM Employees a
JOIN Employees b ON a.job_title = b.job_title AND a.emp_id < b.emp_id
ORDER BY a.job_title;

-- (NATURAL JOIN)
-- NOTE: NATURAL JOIN is generally avoided, but required.
-- We create dummy tables to demonstrate it safely.
CREATE TABLE T1 (id INT, name VARCHAR(10));
CREATE TABLE T2 (id INT, value VARCHAR(10));
INSERT INTO T1 VALUES (1, 'A'), (2, 'B');
INSERT INTO T2 VALUES (1, 'X'), (3, 'Y');

-- This will join T1 and T2 on the common 'id' column
SELECT * FROM T1 NATURAL JOIN T2; -- Result should be (1, 'A', 'X')

DROP TABLE T1;
DROP TABLE T2;


-- D. Indexing and Optimization

-- 1. BTREE Index (for numeric/date columns)

-- Query to analyze: Find employees hired in a specific year.
-- Run this BEFORE creating the index to see the "Full Table Scan".
EXPLAIN SELECT * FROM Employees WHERE hire_date BETWEEN '2022-01-01' AND '2022-12-31';

-- Create the BTREE index (MySQL's default)
CREATE INDEX idx_btree_hire_date ON Employees(hire_date);

-- Run this AFTER creating the index to see the plan change.
-- It should now use the index ("idx_btree_hire_date")
EXPLAIN SELECT * FROM Employees WHERE hire_date BETWEEN '2022-01-01' AND '2022-12-31';

-- Clean up the index
DROP INDEX idx_btree_hire_date ON Employees;


-- 2. TEXT Index (for text search)

-- Query to analyze (Before): Using LIKE on a TEXT column is slow.
-- Run this BEFORE the index. It will show a "Full Table Scan".
EXPLAIN SELECT project_id, project_description FROM Projects WHERE project_description LIKE '%database%';

-- Create the FULLTEXT index
CREATE FULLTEXT INDEX idx_text_description ON Projects(project_description);

-- Query (After): Use the MATCH...AGAINST syntax.
-- Run this AFTER the index. It will show a "Full-text search".
EXPLAIN SELECT project_id, project_description
FROM Projects
WHERE MATCH(project_description) AGAINST('database' IN NATURAL LANGUAGE MODE);

-- This is the actual query to get results:
SELECT project_id, project_name, project_description
FROM Projects
WHERE MATCH(project_description) AGAINST('database' IN NATURAL LANGUAGE MODE);

-- Clean up the index
DROP INDEX idx_text_description ON Projects;