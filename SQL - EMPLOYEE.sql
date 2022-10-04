CREATE DATABASE EMPLOYEE_ASHFAQ;
USE EMPLOYEE_ASHFAQ;

/*CREATE TABLE department(
DEP_ID INT PRIMARY KEY,
DEP_NAME VARCHAR(20),
DEP_LOCATION VARCHAR(15)
);*/

INSERT INTO department VALUES
(101, 'Sales', 'abc'),
(102, 'Production', 'def'),
(103, 'Service', 'ghi'),
(104, 'Accounting', 'jkl'),
(105, 'Management', 'mno'),
(106, 'Furniture', 'pqr'),
(107, 'Purchasing', 'stu'),
(108, 'Technology', 'vwx'),
(109, 'Marketing', 'abcde'),
(110, 'Finance', 'xyz');

/*CREATE TABLE salary_grade(
grade INT PRIMARY KEY NOT NULL,
min_salary INT,
max_salary INT
);*/

INSERT INTO salary_grade VALUES
(1, 65000, 150000),
(2, 60000, 130000),
(3, 57000, 120000),
(4, 55000, 115000),
(5, 52000, 110000),
(6, 50000, 108000),
(7, 48000, 105000),
(8, 45000, 100000),
(9, 45000, 95000),
(10, 40000, 90000);

CREATE TABLE employees(
emp_id INT PRIMARY KEY NOT NULL,
emp_name VARCHAR(15),
job_name VARCHAR(10),
manager_id INT,
hire_date DATE,
salary DECIMAL(10,2),
commission DECIMAL(7,2),
dep_id INT FOREIGN KEY REFERENCES department(DEP_ID)
);

INSERT INTO employees VALUES
(201, 'Rahul', 'Mechanic', 301, '2016-09-24', 40000, 6000, 101),
(202, 'Ram', 'Recruiter', 302, '2014-04-07', 45000, 7000, 102),
(203, 'Shayam', 'Locksmith', 303, '2014-08-07', 48000, 8000, 103),
(204, 'Naveen', 'Assistant', 304, '2017-11-17', 50000, 9000, 104),
(205, 'Raghav', 'Translator', 305, '2018-12-11', 52000, 10000, 105),
(206, 'Shariya', 'Paralegal', 306, '2010-10-10', 55000, 11000, 106),
(207, 'Yukti', 'Bankteller', 307, '2011-01-02', 60000, 12000, 107),
(208, 'Prachi', 'F_Incharge', 308, '2019-06-09', 62000, 14000, 108),
(209, 'Aurthor', 'Security', 309, '2020-12-04', 64000, 16000, 109),
(210, 'Peter', 'S_Incharge', 310, '2022-01-03', 65000, 18000, 110);

SELECT * FROM department; SELECT * FROM salary_grade; SELECT * FROM employees;