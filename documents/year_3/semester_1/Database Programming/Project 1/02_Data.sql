USE ProjectMgmtDB;

SET SQL_SAFE_UPDATES = 0;

-- B. Data Manipulation (DML)

-- Insert at least 10 records into Employees
INSERT INTO Employees (first_name, last_name, email, job_title, hire_date) VALUES
('Chew', 'Chiu Xian', 'ali.hassan@comp.com', 'Project Manager', '2022-01-10'),
('Neo', 'Li Xin', 'beth.tan@comp.com', 'Senior Developer', '2022-03-15'),
('Choh', 'Jing Yi', 'chris.lee@comp.com', 'Junior Developer', '2023-05-20'),
('Lau', 'Ya Kai', 'diana.ravi@comp.com', 'QA Analyst', '2022-07-01'),
('Yap', 'Deh Kai', 'evan.wong@comp.com', 'UI/UX Designer', '2022-09-11'),
('Ramah', 'bin Jaafar', 'fara.ahmed@comp.com', 'Project Manager', '2022-02-14'),
('Chong', 'Joe Lim', 'gani.i@comp.com', 'Database Admin', '2023-01-30'),
('Kristen Chang', 'Jing Huan', 'hana.chen@comp.com', 'Senior Developer', '2022-03-16'),
('Javier', 'Kastilanos', 'ian.gomez@comp.com', 'Junior Developer', '2024-01-10'),
('Jia', 'Li', 'jia.li@comp.com', 'QA Analyst', '2023-08-05'),
('Brendan', 'Chia', 'kumar.nair@comp.com', 'Intern', '2024-06-01'),
('Howard', 'Switsland', 'lena.schmidt@comp.com', 'Business Analyst', '2022-04-10');

-- Insert at least 10 records into Projects
INSERT INTO Projects (project_name, project_description, start_date, due_date, manager_id, budget) VALUES
('E-commerce Platform', 'A full-stack online shopping website with payment gateway integration. Focus on database security.', '2024-01-01', '2024-12-31', 1, 150000.00),
('Mobile Banking App', 'Native mobile app for iOS and Android. Requires high security and database optimization.', '2024-03-01', '2025-03-01', 6, 250000.00),
('Internal Wiki', 'A documentation portal for all employees. Built using a standard CMS.', '2024-02-15', '2024-07-30', 1, 30000.00),
('Data Warehouse Migration', 'Migrate all sales data from legacy system to a new cloud-based data warehouse.', '2024-05-01', '2025-05-01', 6, 300000.00),
('Inventory Management Tool', 'A desktop tool for warehouse staff to track stock levels.', '2024-06-15', '2024-11-30', 1, 75000.00),
('Customer Feedback System', 'A web portal for customers to submit feedback. Includes sentiment analysis.', '2024-08-01', '2025-01-31', 6, 90000.00),
('AI Chatbot', 'An AI-powered chatbot for customer service. Uses natural language processing.', '2024-09-01', '2025-04-30', 1, 120000.00),
('Website Redesign', 'Update the corporate website with a new design. Focus on UI/UX.', '2024-10-01', '2025-02-28', 6, 60000.00),
('HR Payroll System', 'A new system for managing employee payroll and leave.', '2024-11-01', '2025-10-31', 1, 200000.00),
('Cancelled Project Alpha', 'This project was cancelled and will be deleted.', '2024-01-01', '2024-01-31', NULL, 1000.00);

-- Insert at least 10 records into Tasks (insert more to make queries interesting)
INSERT INTO Tasks (project_id, assignee_id, task_name, status, priority) VALUES
(1, 2, 'Design database schema', 'Done', 'High'),
(1, 3, 'Develop user login page', 'In Progress', 'Medium'),
(1, 4, 'Write test cases for login', 'To Do', 'Medium'),
(1, 5, 'Create wireframes for homepage', 'Done', 'High'),
(2, 8, 'Setup mobile app repository', 'Done', 'High'),
(2, 9, 'Develop funds transfer module', 'In Progress', 'High'),
(2, 10, 'Test funds transfer security', 'In Progress', 'High'),
(3, 7, 'Install CMS software', 'Done', 'Medium'),
(3, 3, 'Create user documentation page', 'To Do', 'Low'),
(4, 7, 'Analyze legacy database', 'In Progress', 'High'),
(4, 8, 'Develop ETL scripts', 'In Progress', 'High'),
(5, 2, 'API for stock update', 'To Do', 'High'),
(5, 5, 'Design inventory dashboard', 'In Progress', 'Medium'),
(8, 5, 'Finalize new logo design', 'Done', 'Medium'),
(8, 9, 'Implement new CSS styles', 'To Do', 'Medium'),
(1, 2, 'Optimize product search query', 'To Do', 'High'),
(2, 8, 'Refactor authentication code', 'To Do', 'Medium'),
(4, 7, 'Setup cloud database instance', 'In Progress', 'High'),
(10, NULL, 'Initial planning', 'To Do', 'Low'), -- Task for cancelled project
(1, NULL, 'Unassigned bug fix', 'To Do', 'Low'); -- Unassigned task

-- UPDATE with WHERE
-- Update a task's status from 'To Do' to 'In Progress'
UPDATE Tasks
SET status = 'In Progress'
WHERE task_name = 'Write test cases for login';

-- Give all 'Senior Developer' employees a new, higher-priority task
INSERT INTO Tasks (project_id, assignee_id, task_name, status, priority)
SELECT 1, emp_id, 'Code Review - Security Audit', 'To Do', 'High'
FROM Employees
WHERE job_title = 'Senior Developer';

-- DELETE with WHERE
-- Delete the cancelled project.
-- Must delete tasks from child table first due to foreign key constraints.
DELETE FROM Tasks
WHERE project_id = (SELECT project_id FROM Projects WHERE project_name = 'Cancelled Project Alpha');

DELETE FROM Projects
WHERE project_name = 'Cancelled Project Alpha';

SET SQL_SAFE_UPDATES = 1;