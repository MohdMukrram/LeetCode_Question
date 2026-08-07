# Write your MySQL query statement below
select email as Email
from Person p
group by email
having count(distinct id) > 1;