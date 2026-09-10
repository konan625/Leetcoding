# Write your MySQL query statement below
select e2.name from Employee as e2 join (select managerId,count(*) as directReports from Employee as e group by managerId having count(*)>=5) as e1 on e2.Id=e1.managerId;
