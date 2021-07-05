CREATE TABLE students(
	id INT AUTO_INCREMENT PRIMARY KEY,
    first_name varchar(50) NOT NULL
);

CREATE TABLE papers(
	title varchar(50),
    grade int,
    student_id int,
    FOREIGN KEY(student_id) REFERENCES students(id)
);

INSERT INTO students (first_name) VALUES 
('Caleb'), 
('Samantha'), 
('Raj'), 
('Carlos'), 
('Lisa');

INSERT INTO papers (student_id, title, grade ) VALUES
(1, 'My First Book Report', 60),
(1, 'My Second Book Report', 75),
(2, 'Russian Lit Through The Ages', 94),
(2, 'De Montaigne and The Art of The Essay', 98),
(4, 'Borges and Magical Realism', 89);

SELECT students.first_name, papers.title, papers.grade
FROM students
JOIN papers
ON students.id = papers.student_id
ORDER BY papers.grade DESC;

SELECT students.first_name, 
	IFNULL(papers.title, 'MISSING') AS title, 
	IFNULL(papers.grade, 0) AS grades
FROM students
LEFT JOIN papers
ON students.id = papers.student_id;

SELECT 
	first_name, 
	IFNULL(CAST(AVG(grade) AS CHAR(6)), 0) AS average, 
		CASE
			WHEN AVG(grade) >= 75 	THEN 'PASSING'
            WHEN AVG(grade) IS NULL THEN 'FAILING'
			ELSE 'FAILING'
		END AS passing_status
FROM students
LEFT JOIN papers
ON students.id = papers.student_id
GROUP BY first_name
ORDER BY grade DESC;