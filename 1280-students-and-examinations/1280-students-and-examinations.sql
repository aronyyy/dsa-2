SELECT
    ST.student_id,
    ST.student_name,
    SU.subject_name,
    COUNT(E.student_id) AS attended_exams
FROM Students ST
CROSS JOIN Subjects SU
LEFT JOIN Examinations E
ON (ST.STUDENT_ID = E.STUDENT_ID AND SU.SUBJECT_NAME = E.SUBJECT_NAME)
GROUP BY
    ST.student_id,
    ST.student_name,
    SU.subject_name
ORDER BY
    ST.student_id,
    SU.subject_name;