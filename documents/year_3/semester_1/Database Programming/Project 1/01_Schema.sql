-- A. Database Creation (DDL)
-- CREATE DATABASE IF NOT EXISTS ProjectMgmtDB;
USE ProjectMgmtDB;

-- Drop tables in reverse order of creation to avoid foreign key errors
DROP TABLE IF EXISTS Tasks;
DROP TABLE IF EXISTS Projects;
DROP TABLE IF EXISTS Employees;
DROP TABLE IF EXISTS TempNotes; -- For DROP TABLE demo

-- Employees table
-- Stores all employee records
CREATE TABLE Employees (
    emp_id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    job_title VARCHAR(50),
    hire_date DATE NOT NULL DEFAULT (CURRENT_DATE)
);

-- Projects table
-- Stores all project records
CREATE TABLE Projects (
    project_id INT AUTO_INCREMENT PRIMARY KEY,
    project_name VARCHAR(150) NOT NULL UNIQUE,
    project_description TEXT, -- For FULLTEXT index demo
    start_date DATE,
    due_date DATE,
    manager_id INT, -- This links to an employee
    
    -- Add FOREIGN KEY constraint
    FOREIGN KEY (manager_id) REFERENCES Employees(emp_id)
);

-- Tasks table
-- Stores individual tasks, linking projects and employees
CREATE TABLE Tasks (
    task_id INT AUTO_INCREMENT PRIMARY KEY,
    project_id INT NOT NULL,
    assignee_id INT, -- Can be NULL if unassigned
    task_name VARCHAR(200) NOT NULL,
    status VARCHAR(20) DEFAULT 'To Do',
    priority VARCHAR(10) DEFAULT 'Medium',
    
    -- FOREIGN KEY constraints
    FOREIGN KEY (project_id) REFERENCES Projects(project_id),
    FOREIGN KEY (assignee_id) REFERENCES Employees(emp_id),
    
    -- CHECK constraints
    CHECK (status IN ('To Do', 'In Progress', 'Done', 'Testing')),
    CHECK (priority IN ('High', 'Medium', 'Low'))
);

-- ALTER TABLE by adding a new column
ALTER TABLE Projects
ADD COLUMN budget DECIMAL(12, 2) DEFAULT 0.00;

-- DROP TABLE
-- Create a temporary table to be dropped
CREATE TABLE TempNotes (
    note_id INT PRIMARY KEY,
    note_text VARCHAR(100)
);

DROP TABLE TempNotes;