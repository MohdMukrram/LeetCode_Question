# Write your MySQL query statement below
select a.actor_id,a.director_id
from ActorDirector as a
group by a.actor_id,a.director_id
having count(*) >= 3;