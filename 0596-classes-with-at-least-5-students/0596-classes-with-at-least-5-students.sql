# Write your MySQL query statement below

with class_count as(
    select class,count(*) as c_count
    from Courses group by class
)
select class from class_count where c_count >= 5;