# Write your MySQL query statement below
with info as (
    select e.empid,e.name,b.bonus
    from Employee e left join Bonus b
    on e.empId = b.empId
)
select name,bonus
from info where bonus is null or bonus < 1000;