## Project Description

Class Management System (CMS)

- Add student
  - Student ID
  - student name
  - Grades
- Display student record
  - Grade for each subject
  - GWA
- Search
  - Displays the student record.
- Data stored to a text file (CSV)

***

### What is a CSV File?

A CSV (Comma-Separated Values) file is a simple text-based file format used to store tabular data. In a CSV file, each line represents a row of data, with fields separated by commas (or other delimiters like semicolons or tabs). - ChatGPT

***

### Parts

The program has **4 phases**.
Phase 3 has 3 parts.
So, all in all, there are **6 parts**.

### Phase 1: Creates the data file if it does not exist

### Phase 2: Reads all students data from the data file

- Stores the data to an array.
- Tutorial: https://www.youtube.com/watch?v=rbVt5v8NNe8

### [3] Displays student records and options

- Use a loop for this part so that the program
  continues until exited by the user.
- 4 options:

```
[1] Add Student
[2] Display student record
[3] Search
[4] Exit
```

#### Phase 3.A: Add Student Option

- Input student data and grades
  - Last name, first name, ID
  - MATH101, CMPSC113, COMM01, MATH01, NSTP02, MATH16, PATHFIT2 grades
- Compute the GWA
- Store all of these to the student struct in the array

#### Phase 3.B: Display student record

- Make the user select one student
- and then display the data and grades of the student

#### Phase 3.C: Search

- Let the user search for students
  based on the keyword/s inputted
- If the search matches multiple students, ask again which specific student whose data and grades will be shown
- Display the data and grades of the selected student

### Phase 4: Stores data to the data back to the data file

- Tutorial: https://www.youtube.com/watch?v=7ZFgphYJvUA
