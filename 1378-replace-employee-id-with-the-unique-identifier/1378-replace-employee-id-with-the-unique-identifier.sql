# Write your MySQL query statement below
SELECT EU.UNIQUE_ID, E.NAME FROM Employees AS E LEFT JOIN EmployeeUNI AS EU 
ON E.ID = EU.ID;
