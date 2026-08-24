# Write your MySQL query statement below
-- select p1.email from Person p1 
-- join Person p2
--     on p1.id <> p2.id
-- where p1.email = p2.email;/

SELECT email
FROM Person
GROUP BY email
HAVING COUNT(email) > 1;

