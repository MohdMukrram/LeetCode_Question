# Write your MySQL query statement below
select c.class
from Courses c
group by c.class
having count(c.class) >=5;