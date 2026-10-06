# Write your MySQL query statement below
SELECT Employee.name , Bonus.bonus From Employee left join Bonus ON Employee.empID = Bonus.empID
where bonus < 1000 OR Bonus is NULL;