// Project Description
// Class Management System
// - Add student
//   - student no./ID
//   - student name
//   - grades
// - Display student record
//   - grade for each subject
//   - GWA
// - Search
//   - displays the student record
//
// Data stored to a text file (CSV)

// A CSV (Comma-Separated Values) file is a simple text-based
// file format used to store tabular data. In a CSV file, each
// line represents a row of data, with fields separated by
// commas (or other delimiters like semicolons or tabs). - ChatGPT

#include <stdio.h>

// To be able to use `bool` type
#include <stdbool.h>

#define TEXT_MAX_NUM 50
#define ID_NUM 15

typedef struct
{
    char lastName[TEXT_MAX_NUM];
    char firstName[TEXT_MAX_NUM];
    char studentID[ID_NUM];
    double math101;
    double cmpsc113;
    double comm01;
    double math01;
    double nstp02;
    double math16;
    double cmpsc112;
    double pathfit2;
    double GWA;
} Student;

int main(void)
{
    // The program has 4 phases.
    // Phase 3 has 3 parts.
    // So, all in all, there are 6 parts.

    // Global Variables
    const char *dataFilePath = "CMS_Data.csv";

    // [1] Creates the data file if it does not exist
    //
    //
    // [2] Reads all students data from the data file
    //  - Stores the data to an array.
    //  - Tutorial: https://www.youtube.com/watch?v=rbVt5v8NNe8
    //
    Student students[100];
    //
    // [3] Displays student records and options
    //  - Use a loop for this part so that the program
    //    continues until exited by the user.
    //  - 4 options:
    //    [1] Add Student
    //    [2] Display student record
    //    [3] Search
    //    [4] Exit

    // Phase 3
    // Initialize option value
    int option = 1;
    while (option >= 1 && option <= 3)
    {
        // Print options
        printf("Select Option:\n");
        printf("[1] Add Student\n[2] Display student record\n[3] Search\n[4] Exit\n\n> ");
        scanf("%d", &option);
        int index = -1;
        if (option == 1)
        {
            // [3.A] Add Student Option
            //  - Input student data and grades
            //    - Last name, first name, ID
            //    - MATH101, CMPSC113, COMM01, MATH01, NSTP02, MATH16, PATHFIT2 grades
            //  - Computes the GWA
            //  - Stores all of these to the student struct in the array

            double sum = 0;
            index++;
            printf("Last name of student: ");
            scanf(" %[^\n]s", students[index].lastName);
            printf("First name of student: ");
            scanf(" %[^\n]s", students[index].firstName);
            printf("ID of student: ");
            scanf(" %[^\n]s", students[index].studentID);

            printf("Grade for MATH101: ");
            scanf("%lf", &students[index].math101);
            printf("Grade for MATH01: ");
            scanf("%lf", &students[index].math01);
            printf("Grade for MATH16: ");
            scanf("%lf", &students[index].math16);
            printf("Grade for COMM01: ");
            scanf("%lf", &students[index].comm01);
            printf("Grade for PATHFIT2: ");
            scanf("%lf", &students[index].pathfit2);
            printf("Grade for NSTP02: ");
            scanf("%lf", &students[index].nstp02);
            printf("Grade for CMPSC113: ");
            scanf("%lf", &students[index].cmpsc113);
            printf("Grade for CMPSC112: ");
            scanf("%lf", &students[index].cmpsc112);

            sum = students[index].math101 + students[index].math01 + students[index].math16 + students[index].comm01 + students[index].pathfit2 + students[index].nstp02 + students[index].cmpsc113 + students[index].cmpsc112;

            students[index].GWA = sum / 8;
        }
        else if (option == 2)
        {
            // [3.B] Display student record
            //  - Make the user select one student
            //  - and then displays the data and grades of the student
        }
        else if (option == 3)
        {
            // [3.C] Search
            //  - Let the user search for students
            //    based on the keyword/s inputted
            //  - If the search matches multiple students,
            //    ask again which specific student whose
            //    data and grades will be shown
            //  - Displays the data and grades of the selected student
        }
    }

    // [4] Stores data to the data back to the data file
    //  - Tutorial: https://www.youtube.com/watch?v=7ZFgphYJvUA
}
