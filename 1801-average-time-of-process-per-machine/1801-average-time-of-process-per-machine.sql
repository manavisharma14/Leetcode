# Write your MySQL query statement below

select s.machine_id, 
round(avg(e.timestamp - s.timestamp), 3) as processing_time
from activity s
join activity e
on s.machine_id = e.machine_id
and s.process_id = e.process_id
where s.activity_type = "start" and e.activity_type = "end"
group by machine_id;