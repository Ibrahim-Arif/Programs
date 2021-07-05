DROP DATABASE IF EXISTS book_shop;
CREATE DATABASE udemy_practice;
USE udemy_practice; 

CREATE TABLE books 
	(
		book_id INT NOT NULL AUTO_INCREMENT,
		title VARCHAR(100),
		author_fname VARCHAR(100),
		author_lname VARCHAR(100),
		released_year INT,
		stock_quantity INT,
		pages INT,
		PRIMARY KEY(book_id)
	);
SELECT * FROM books;
INSERT INTO books (title, author_fname, author_lname, released_year, stock_quantity, pages)
VALUES
('The Namesake', 'Jhumpa', 'Lahiri', 2003, 32, 291),
('Norse Mythology', 'Neil', 'Gaiman',2016, 43, 304),
('American Gods', 'Neil', 'Gaiman', 2001, 12, 465),
('Interpreter of Maladies', 'Jhumpa', 'Lahiri', 1996, 97, 198),
('A Hologram for the King: A Novel', 'Dave', 'Eggers', 2012, 154, 352),
('The Circle', 'Dave', 'Eggers', 2013, 26, 504),
('The Amazing Adventures of Kavalier & Clay', 'Michael', 'Chabon', 2000, 68, 634),
('Just Kids', 'Patti', 'Smith', 2010, 55, 304),
('A Heartbreaking Work of Staggering Genius', 'Dave', 'Eggers', 2001, 104, 437),
('Coraline', 'Neil', 'Gaiman', 2003, 100, 208),
('What We Talk About When We Talk About Love: Stories', 'Raymond', 'Carver', 1981, 23, 176),
("Where I'm Calling From: Selected Stories", 'Raymond', 'Carver', 1989, 12, 526),
('White Noise', 'Don', 'DeLillo', 1985, 49, 320),
('Cannery Row', 'John', 'Steinbeck', 1945, 95, 181),
('Oblivion: Stories', 'David', 'Foster Wallace', 2004, 172, 329),
('Consider the Lobster', 'David', 'Foster Wallace', 2005, 92, 343);

INSERT INTO books
    (title, author_fname, author_lname, released_year, stock_quantity, pages)
    VALUES ('10% Happier', 'Dan', 'Harris', 2014, 29, 256), 
           ('fake_book', 'Freida', 'Harris', 2001, 287, 428),
           ('Lincoln In The Bardo', 'George', 'Saunders', 2017, 1000, 367);



SELECT UPPER(REVERSE('why does my cat look at me with such hatred?')) AS test;
SELECT REPLACE('why does my cat look at me with such hatred?', ' ', '->') AS TEST;

SELECT CONCAT(SUBSTR(books.title, 1, 10), '...') AS short_title, 
	CONCAT(author_lname, ',', author_fname) AS author,
    CONCAT(stock_quantity, ' in stock') AS quantity
FROM books;

SELECT title, author_lname
from books
where author_lname like '% %';

SELECT title, author_lname
from books
where title like '%\%%';

SELECT COUNT(*) AS count
FROM books
where title LIKE '%the%';

SELECT CONCAT(author_fname, ' ', author_lname) AS Author, sum(pages) AS total_pages
FROM books
GROUP BY author_fname, author_lname;

SELECT released_year, count(*)
FROM books
GROUP BY released_year;

SELECT CONCAT(author_fname,' ', author_lname) AS author
FROM books
WHERE pages IN
	(
		SELECT max(pages) 
        FROM BOOKS
	);
    
SELECT released_year AS year, count(*) AS books, avg(pages) AS avg_pages
FROM books
GROUP BY released_year;