create database giraffe;
use giraffe;
show tables;
desc employee;
show warnings;

SELECT * FROM branch;
INSERT INTO branch 	 VALUES (3, 'stamford', NULL, '1998-02-09');
UPDATE branch
SET mgr_id = 106
WHERE branch_id = 3;
CREATE TABLE branch(
	branch_id		INT			 AUTO_INCREMENT	PRIMARY KEY,
    branch_name		VARCHAR(20)
);
ALTER TABLE branch
ADD COLUMN mgr_id 	INT;
ALTER TABLE branch
ADD FOREIGN KEY(mgr_id)	REFERENCES employee(emp_id) ON DELETE SET NULL; 

SELECT * FROM employee;
INSERT INTO employee VALUES (110, 'IBRAHIM', 'ARIF', '2000-05-31', 'm', 710000, 106, 3);
UPDATE employee
SET branch_id = 1
WHERE emp_id = 100;
CREATE TABLE employee(
	emp_id			INT 		 AUTO_INCREMENT	PRIMARY KEY,
    first_name		VARCHAR(10)  NOT NULL,
    last_name		VARCHAR(10)  NOT NULL,
    birth_date  	date,
    sex				CHAR(1)		 DEFAULT NULL, check(sex='m' or sex='f'),
    salary			INT,
    super_id		INT,		 FOREIGN KEY(super_id)  REFERENCES employee(emp_id) ON DELETE SET NULL,
    branch_id		INT,		 FOREIGN KEY(branch_id) REFERENCES branch(branch_id) ON DELETE SET NULL
);

SELECT * FROM client;
INSERT INTO client VALUES(406, 'fedEx', 2);
CREATE TABLE client(
	client_id		INT 		 PRIMARY KEY,
    client_name		VARCHAR(20)	 NOT NULL,
    branch_id		int,		 FOREIGN KEY(branch_id) REFERENCES branch(branch_id) ON DELETE SET NULL
);

SELECT * FROM works_with;
INSERT INTO works_with VALUES (105, 406, 130000);
CREATE TABLE works_with(
	emp_id			INT,		 FOREIGN KEY(emp_id)	REFERENCES employee(emp_id) ON DELETE CASCADE,
    client_id		INT,		 FOREIGN KEY(client_id) REFERENCES client(client_id) ON DELETE CASCADE,
    total_sales		INT,
    PRIMARY KEY(emp_id, client_id)
);

SELECT * FROM branch_supplier;
INSERT INTO branch_supplier VALUES (3, 'stamford forms', 'forms');
CREATE TABLE branch_supplier(
	branch_id		INT,		 FOREIGN KEY(branch_id)	REFERENCES branch(branch_id) ON DELETE CASCADE,
    supplier_name	VARCHAR(20),
    supply_type		VARCHAR(20),
    PRIMARY KEY(branch_id, supplier_name)
);

SELECT COUNT(branch_id), branch_id
FROM employee
GROUP BY branch_id;

SELECT *
FROM branch_supplier
WHERE supplier_name LIKE '%form%'
ORDER BY supplier_name DESC;

SELECT branch_name, branch_id
FROM branch
UNION
SELECT client_name, client_id
FROM client;

SELECT employee.first_name , client.client_name, works_with.total_sales
FROM   employee
JOIN   works_with
ON     employee.emp_id = works_with.emp_id
JOIN   client
ON     works_with.client_id = client.client_id;

SELECT client.client_id, client.client_name, client.branch_id
FROM client
WHERE branch_id IN (
	SELECT branch.branch_id
	FROM branch
	WHERE branch.mgr_id = 102
);

SELECT employee.first_name, branch.branch_name
FROM employee
JOIN branch
ON employee.branch_id = branch.branch_id;

SELECT * FROM new_logs;
CREATE TABLE new_logs(
	message		varchar(30),
    emp_id		int,
    time		DATETIME
);
dept
DELIMITER $$
CREATE TRIGGER new_logs BEFORE 
INSERT ON employee
FOR EACH ROW BEGIN
INSERT INTO new_logs VALUES('new employee addeed', new.emp_id, NOW());
END$$
DELIMITER ;


select concat(first_name, ' ', last_name) AS employee_name
from employee;