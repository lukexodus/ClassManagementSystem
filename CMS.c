// ------------------------------------------------
// --           CLASS MANAGEMENT SYSTEM          --
// ------------------------------------------------

// --    Project Description    --
//
// - Add student
//   - Student no./ID
//   - Student name
//   - Grades
// - Display student record
//   - Grade for each subject
//   - GWA
// - Search
//   - Displays the student record
//
// - Data stored to a text file (CSV)

// --    What is a .CSV file?    --
//
// A CSV (Comma-Separated Values) file is a simple text-based
// file format used to store tabular data. In a CSV file, each
// line represents a row of data, with fields separated by
// commas (or other delimiters like semicolons or tabs).

// A .csv file will be used as the database of this program.

#include <stdio.h>

// To be able to use `bool` type
#include <stdbool.h>

// To be able to use the `exit` and `atof` functions
#include <stdlib.h>

// To be able to use string functions (`strcpy`, `strstr`, etc.)
#include <string.h>

// To be able to use the `tolower` function
#include <ctype.h>

#define TEXT_MAX_NUM 50     // Text fields max length
#define ID_NUM 15           // Student ID max length
#define MAX_RECORDS 100     // maximum number of records to store
#define MAX_FIELD_LENGTH 50 // Maximum length of each field in the CSV file

// Structure representing a student
typedef struct
{
    char studentID[ID_NUM];
    char lastName[TEXT_MAX_NUM];
    char firstName[TEXT_MAX_NUM];
    double cmpsc100;
    double cmpsc111;
    double socsc02;
    double sts01;
    double engl01;
    double hum12;
    double nstp01;
    double pe01;
    double GWA;
} Student;

void printStudentRecords(int recordsNum, Student students[100]);

int main(void)
{
    // ----------------------------
    // --    Global Variables    --
    // ----------------------------

    const char *dataFilePath = "CMS_Data.csv"; // Filename of the .csv file (database file)
    int recordsNum = 0;                        // Counter for the number of records read

    // Variable that tracks if there are students added
    // during the execution of the program
    bool isThereAdded = false;

    // Variable of the index of the student to be added.
    // To be incremented.
    int index = -1;

    // ----------------------------------------------------------------
    // --    [Phase 1] Creates the data file if it does not exist    --
    // ----------------------------------------------------------------

    // Open the file in append mode. If it does not exist, it will be created.
    FILE *dataFile = fopen(dataFilePath, "a"); // "a" is for append mode
    if (!dataFile)
    { // Check if the file was not opened/created successfully
        printf("Error creating the data file.\n");
        exit(EXIT_FAILURE); // Exit the program if the file could not be opened
    }
    fclose(dataFile); // Close the file

    // ----------------------------------------------------------------
    // --    [Phase 2] Reads all students data from the data file    --
    // ----------------------------------------------------------------
    //  - Stores the data to an array.
    //  - Increments `recordsNum` by one for every record read

    // Array where the Student structs will be stored.
    // This will also be the content of the .csv file.
    Student students[MAX_RECORDS];

    FILE *file; // A pointer to a file opened for reading.

    // Open the file for reading
    file = fopen(dataFilePath, "r"); // "r" is for read mode
    if (file == NULL)
    { // If the file cannot be read, exits the program
        fprintf(stderr, "Error opening file %s\n", dataFilePath);
        return 1;
    }

    char line[MAX_FIELD_LENGTH * 2]; //  A buffer to hold each line read from the file.

    // Read data from the file line by line.
    // The loop continues as long as lines are read successfully
    // and the number of records is less than MAX_RECORDS.
    while (fgets(line, sizeof(line), file) != NULL && recordsNum < MAX_RECORDS)
    {

        // Tokenize the line based on comma separator
        char *token = strtok(line, ",");

        // When no more tokens are found, `strtok` returns NULL.
        if (token == NULL)
            continue;

        // Tokenizing a string means breaking it down into smaller pieces,
        // or tokens, based on specified delimiters.

        // The `strtok` function modifies the original string
        // by replacing the delimiters with '\0' (null character)
        // to terminate tokens and maintains internal state
        // between calls to retrieve subsequent tokens.

        // Copy the student ID field
        strncpy(students[recordsNum].studentID, token, sizeof(students[recordsNum].studentID) - 1);
        students[recordsNum].studentID[sizeof(students[recordsNum].studentID) - 1] = '\0'; // ensure null-termination

        // Copy the last name field to the student structure
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;

        strncpy(students[recordsNum].lastName, token, sizeof(students[recordsNum].lastName) - 1);
        students[recordsNum].lastName[sizeof(students[recordsNum].lastName) - 1] = '\0'; // ensure null-termination

        // Copy the first name field
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strncpy(students[recordsNum].firstName, token, sizeof(students[recordsNum].firstName) - 1);
        students[recordsNum].firstName[sizeof(students[recordsNum].firstName) - 1] = '\0'; // Ensure null-termination

        // Parse the remaining double fields (grades)
        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].cmpsc100 = atof(token);

        // `atof` function converts a string (ASCII) to a float
        // (ASCII to Float) or `atof`

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].cmpsc111 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].socsc02 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].sts01 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].engl01 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].hum12 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].nstp01 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].pe01 = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        students[recordsNum].GWA = atof(token);

        // Increment the student records number if all fields are successfully parsed
        recordsNum++;
        index++;
    }

    // Close file
    fclose(file);

    // Print number of records read
    printf("Number of records read: %d\n", recordsNum);

    // ----------------------------------------------------------------
    // --       [Phase 3] Displays student records and options       --
    // ----------------------------------------------------------------
    //  - Use a loop so that the program
    //    continues until exited by the user.

    // Initialize option value
    int option = 1;

    while (option >= 1 && option <= 4) // 1, 2, 3, 4 are the valid ranges.
    {
        // Show options
        printf("Select Option:\n");
        printf("[1] Add Student\n[2] Display student record\n[3] Search\n[4] Display all student records\n[5] Exit\n\n> ");

        // Input number of the option (functionality) to run
        scanf("%d", &option);

        if (option == 1)
        {
            // ----------------------------------------------------------------
            // --               [Phase 3.A] Add Student Option               --
            // ----------------------------------------------------------------
            //  - Input student data and grades.
            //    - Last name, first name, ID,
            //    - CMPSC100, NSTP01, STS01, CMPSC111, HUM12, SOCSC02, & ENGL01 grades
            //  - Computes the GWA.
            //  - Stores all of these to the student struct in the array.

            double sum = 0; // To be used in computing the GWA

            index++; // This started from -1 earlier

            printf("ID of student: ");
            scanf(" %[^\n]s", students[index].studentID);
            printf("Last name of student: ");
            scanf(" %[^\n]s", students[index].lastName);
            printf("First name of student: ");
            scanf(" %[^\n]s", students[index].firstName);

            printf("Grade for CMPSC100: ");
            scanf("%lf", &students[index].cmpsc100);
            printf("Grade for CMPSC111: ");
            scanf("%lf", &students[index].cmpsc111);
            printf("Grade for SOCSC02: ");
            scanf("%lf", &students[index].socsc02);
            printf("Grade for STS01: ");
            scanf("%lf", &students[index].sts01);
            printf("Grade for ENGL01: ");
            scanf("%lf", &students[index].engl01);
            printf("Grade for HUM12: ");
            scanf("%lf", &students[index].hum12);
            printf("Grade for NSTP01: ");
            scanf("%lf", &students[index].nstp01);
            printf("Grade for PE01: ");
            scanf("%lf", &students[index].pe01);

            // Computes the GWA
            sum = students[index].cmpsc100 * 3 + students[index].cmpsc111 * 3 + students[index].socsc02 * 3 + students[index].sts01 * 3 + students[index].engl01 * 3 + students[index].hum12 * 3 + students[index].nstp01 * 3 + students[index].pe01 * 2;
            students[index].GWA = sum / 23;

            recordsNum++; // Increments the record number

            isThereAdded = true; // If there are changes, the .csv file needs to be updated

            printf("\n");
        }
        else if (option == 2)
        {
            // ----------------------------------------------------------------
            // --     [Phase 3.B] Select and display one student record        --
            // ----------------------------------------------------------------
            //  - Make the user select one student
            //  - and then displays the data and grades of the student

            // Print the list of students to choose from
            printf("\nSelect a student:\n");
            for (int i = 0; i < recordsNum; i++)
            {
                printf("[%d] %s, %s (%s)\n", i + 1, students[i].lastName, students[i].firstName, students[i].studentID);
            }

            // Prompt the user to choose a student
            int choice;
            printf("\nEnter the number of the student: ");
            scanf("%d", &choice);

            // Validate the user input
            if (choice >= 1 && choice <= recordsNum)
            {
                // Display the selected student's record
                int index = choice - 1; // Adjust for zero-based indexing
                printf("\n-- Student Record --\n");
                printf("Last Name: %s\n", students[index].lastName);
                printf("First Name: %s\n", students[index].firstName);
                printf("Student ID: %s\n", students[index].studentID);
                printf("Grades:\n");
                printf("CMPSC100: %.2lf\n", students[index].cmpsc100);
                printf("CMPSC111: %.2lf\n", students[index].cmpsc111);
                printf("SOCSC02: %.2lf\n", students[index].socsc02);
                printf("STS01: %.2lf\n", students[index].sts01);
                printf("ENGL01: %.2lf\n", students[index].engl01);
                printf("HUM12: %.2lf\n", students[index].hum12);
                printf("NSTP01: %.2lf\n", students[index].nstp01);
                printf("PE01: %.2lf\n", students[index].pe01);
                printf("GWA: %.2lf\n\n", students[index].GWA);
            }
            else
            {
                printf("Invalid choice. Please enter a number between 1 and %d.\n\n", recordsNum);
            }
        }
        else if (option == 3)
        {
            // Prompt the user for the search option
            printf("Search Option:\n");
            printf("1. Search by keyword\n");
            printf("2. Search by student number\n");
            printf("3. Search for highest and lowest GWA\n");
            printf("Enter your choice: ");
            int searchOption;
            scanf("%d", &searchOption);

            if (searchOption == 1)
            {
                // ----------------------------------------------------------------
                // --  [Phase 3.C] Search students by keyword    --
                // ----------------------------------------------------------------
                //  - Let the user search for students
                //    based on the keyword/s inputted
                //  - If the search matches multiple students,
                //    ask again which specific student whose
                //    data and grades will be shown
                //  - Displays the data and grades of the selected student
                // Inputs keyword for the search
                char keyword[TEXT_MAX_NUM];
                printf("\nEnter keyword: ");
                scanf(" %[^\n]s", keyword);
                int matches[MAX_RECORDS]; // array to store indices of matching students
                int numMatches = 0;       // counter for number of matches
                // Convert keyword to lowercase, (so that the search is case-insensitive)
                for (int i = 0; keyword[i]; i++)
                {
                    keyword[i] = tolower(keyword[i]);
                }
                // Search for students matching the keyword (case-insensitive)
                for (int i = 0; i < recordsNum; i++)
                {
                    // Converts first name, last name, and student number to lowercase
                    char firstNameLower[TEXT_MAX_NUM];
                    char lastNameLower[TEXT_MAX_NUM];
                    char studentIDLower[TEXT_MAX_NUM];
                    strcpy(firstNameLower, students[i].firstName);
                    strcpy(lastNameLower, students[i].lastName);
                    strcpy(studentIDLower, students[i].studentID);
                    for (int j = 0; firstNameLower[j]; j++)
                    {
                        firstNameLower[j] = tolower(firstNameLower[j]);
                    }
                    for (int j = 0; lastNameLower[j]; j++)
                    {
                        lastNameLower[j] = tolower(lastNameLower[j]);
                    }
                    for (int j = 0; studentIDLower[j]; j++)
                    {
                        studentIDLower[j] = tolower(studentIDLower[j]);
                    }
                    // Checks if keyword is present in either the first name, last name, or student number
                    if (strstr(firstNameLower, keyword) != NULL || strstr(lastNameLower, keyword) != NULL || strstr(studentIDLower, keyword) != NULL)
                    {
                        matches[numMatches] = i; // Store the index of the matching student
                        numMatches++;            // Increment the counter
                    }
                }
                if (numMatches == 0)
                {
                    printf("No matching students found.\n\n");
                }
                else if (numMatches == 1)
                {
                    // If only one match found, display the student record
                    int matchIndex = matches[0];
                    printf("-- Matching student found --\n");
                    printf("Last Name: %s\n", students[matchIndex].lastName);
                    printf("First Name: %s\n", students[matchIndex].firstName);
                    printf("Student ID: %s\n", students[matchIndex].studentID);
                    printf("Grades:\n");
                    printf("CMPSC100: %.2lf\n", students[matchIndex].cmpsc100);
                    printf("CMPSC111: %.2lf\n", students[matchIndex].cmpsc111);
                    printf("SOCSC02: %.2lf\n", students[matchIndex].socsc02);
                    printf("STS01: %.2lf\n", students[matchIndex].sts01);
                    printf("ENGL01: %.2lf\n", students[matchIndex].engl01);
                    printf("HUM12: %.2lf\n", students[matchIndex].hum12);
                    printf("NSTP01: %.2lf\n", students[matchIndex].nstp01);
                    printf("PE01: %.2lf\n", students[matchIndex].pe01);
                    printf("GWA: %.2lf\n\n", students[matchIndex].GWA);
                }
                else
                {
                    // If multiple matches are found, asks user to select a specific student
                    printf("Multiple matching students found. Select a student:\n");
                    for (int i = 0; i < numMatches; i++)
                    {
                        int matchIndex = matches[i];
                        printf("[%d] %s, %s (%s)\n", i + 1, students[matchIndex].lastName, students[matchIndex].firstName, students[matchIndex].studentID);
                    }
                    int selection;
                    printf("\nEnter selection: ");
                    scanf("%d", &selection);
                    if (selection >= 1 && selection <= numMatches)
                    {
                        int matchIndex = matches[selection - 1];
                        printf("Selected student:\n");
                        printf("Last Name: %s\n", students[matchIndex].lastName);
                        printf("First Name: %s\n", students[matchIndex].firstName);
                        printf("Student ID: %s\n", students[matchIndex].studentID);
                        printf("Grades:\n");
                        printf("CMPSC100: %.2lf\n", students[matchIndex].cmpsc100);
                        printf("CMPSC111: %.2lf\n", students[matchIndex].cmpsc111);
                        printf("SOCSC02: %.2lf\n", students[matchIndex].socsc02);
                        printf("STS01: %.2lf\n", students[matchIndex].sts01);
                        printf("ENGL01: %.2lf\n", students[matchIndex].engl01);
                        printf("HUM12: %.2lf\n", students[matchIndex].hum12);
                        printf("NSTP01: %.2lf\n", students[matchIndex].nstp01);
                        printf("PE01: %.2lf\n", students[matchIndex].pe01);
                        printf("GWA: %.2lf\n\n", students[matchIndex].GWA);
                    }
                    else
                    {
                        printf("Invalid selection.\n\n");
                    }
                }
            }
            else if (searchOption == 2)
            {
                // ----------------------------------------------------------------
                // --  [Phase 3.C] Search students by student number    --
                // ----------------------------------------------------------------
                //  - Let the user search for students
                //    based on the student number inputted
                //  - Displays the data and grades of the selected student
                // Inputs student number for the search
                char studentNumber[TEXT_MAX_NUM];
                printf("\nEnter student number: ");
                scanf(" %[^\n]s", studentNumber);
                int matchIndex = -1; // index of the matching student
                // Search for student matching the student number
                for (int i = 0; i < recordsNum; i++)
                {
                    if (strcmp(students[i].studentID, studentNumber) == 0)
                    {
                        matchIndex = i; // Store the index of the matching student
                        break;
                    }
                }
                if (matchIndex == -1)
                {
                    printf("No matching student found.\n\n");
                }
                else
                {
                    // Display the student record
                    printf("-- Matching student found --\n");
                    printf("Last Name: %s\n", students[matchIndex].lastName);
                    printf("First Name: %s\n", students[matchIndex].firstName);
                    printf("Student ID: %s\n", students[matchIndex].studentID);
                    printf("Grades:\n");
                    printf("CMPSC100: %.2lf\n", students[matchIndex].cmpsc100);
                    printf("CMPSC111: %.2lf\n", students[matchIndex].cmpsc111);
                    printf("SOCSC02: %.2lf\n", students[matchIndex].socsc02);
                    printf("STS01: %.2lf\n", students[matchIndex].sts01);
                    printf("ENGL01: %.2lf\n", students[matchIndex].engl01);
                    printf("HUM12: %.2lf\n", students[matchIndex].hum12);
                    printf("NSTP01: %.2lf\n", students[matchIndex].nstp01);
                    printf("PE01: %.2lf\n", students[matchIndex].pe01);
                    printf("GWA: %.2lf\n\n", students[matchIndex].GWA);
                }
            }
            else if (searchOption == 3)
            {
                // ----------------------------------------------------------------
                // --  [Phase 3.C] Search for highest and lowest GWA             --
                // ----------------------------------------------------------------
                double highestGWA = students[0].GWA;
                double lowestGWA = students[0].GWA;
                int highestIndex = 0;
                int lowestIndex = 0;

                for (int i = 1; i < recordsNum; i++)
                {
                    if (students[i].GWA > highestGWA)
                    {
                        highestGWA = students[i].GWA;
                        highestIndex = i;
                    }
                    if (students[i].GWA < lowestGWA)
                    {
                        lowestGWA = students[i].GWA;
                        lowestIndex = i;
                    }
                }

                printf("\nHighest GWA:\n");
                printf("Last Name: %s\n", students[highestIndex].lastName);
                printf("First Name: %s\n", students[highestIndex].firstName);
                printf("Student ID: %s\n", students[highestIndex].studentID);
                printf("Grades:\n");
                printf("CMPSC100: %.2lf\n", students[highestIndex].cmpsc100);
                printf("CMPSC111: %.2lf\n", students[highestIndex].cmpsc111);
                printf("SOCSC02: %.2lf\n", students[highestIndex].socsc02);
                printf("STS01: %.2lf\n", students[highestIndex].sts01);
                printf("ENGL01: %.2lf\n", students[highestIndex].engl01);
                printf("HUM12: %.2lf\n", students[highestIndex].hum12);
                printf("NSTP01: %.2lf\n", students[highestIndex].nstp01);
                printf("PE01: %.2lf\n", students[highestIndex].pe01);
                printf("GWA: %.2lf\n", students[highestIndex].GWA);

                printf("\nLowest GWA:\n");
                printf("Last Name: %s\n", students[lowestIndex].lastName);
                printf("First Name: %s\n", students[lowestIndex].firstName);
                printf("Student ID: %s\n", students[lowestIndex].studentID);
                printf("Grades:\n");
                printf("CMPSC100: %.2lf\n", students[lowestIndex].cmpsc100);
                printf("CMPSC111: %.2lf\n", students[lowestIndex].cmpsc111);
                printf("SOCSC02: %.2lf\n", students[lowestIndex].socsc02);
                printf("STS01: %.2lf\n", students[lowestIndex].sts01);
                printf("ENGL01: %.2lf\n", students[lowestIndex].engl01);
                printf("HUM12: %.2lf\n", students[lowestIndex].hum12);
                printf("NSTP01: %.2lf\n", students[lowestIndex].nstp01);
                printf("PE01: %.2lf\n", students[lowestIndex].pe01);
                printf("GWA: %.2lf\n\n", students[lowestIndex].GWA);
            }
            else
            {
                printf("Invalid choice. Please enter a number between 1 and 3.\n\n");
            }
        }
        else if (option == 4)
        {
            // Prints all the student records
            printStudentRecords(recordsNum, students);
        }
    }

    // ----------------------------------------------------------------
    // --   [Phase 4] Stores data to the data back to the data file  --
    // ----------------------------------------------------------------

    // If there are students added, updates the data stored in the .csv file
    // Otherwise, leave the contents of the .csv file unchanged.
    if (isThereAdded)
    {
        FILE *outputFile;

        file = fopen(dataFilePath, "w"); // "w" is for write mode, overwrites the file

        for (int i = 0; i < recordsNum; i++)
        {
            fprintf(file,
                    "%s,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n",
                    students[i].studentID,
                    students[i].lastName,
                    students[i].firstName,
                    students[i].cmpsc100,
                    students[i].cmpsc111,
                    students[i].socsc02,
                    students[i].sts01,
                    students[i].engl01,
                    students[i].hum12,
                    students[i].nstp01,
                    students[i].pe01,
                    students[i].GWA);

            if (ferror(file))
            {
                // Exits if there is an error writing to the file
                printf("Error writing to file.\n");
                return 1;
            }
        }

        fclose(file); // Close the file
    }

    return 0;
}

void printStudentRecords(int recordsNum, Student students[100])
{
    // Headers for the grades
    printf("CMPSC100 | CMPSC111 | SOCSC02 | STS01 | ENGL01 | HUM12 | NSTP01 | PE01 | GWA\n\n");

    // Prints the grade of each student
    for (int i = 0; i < recordsNum; i++)
    {
        printf("[%d] %s, %s (%s)\n", i + 1, students[i].lastName, students[i].firstName, students[i].studentID);

        printf("%8.2lf | %8.2lf | %7.2lf | %5.2lf | %6.2lf | %5.2lf | %6.2lf | %4.2lf | %3.2lf\n\n",
               students[i].cmpsc100,
               students[i].cmpsc111,
               students[i].socsc02,
               students[i].sts01,
               students[i].engl01,
               students[i].hum12,
               students[i].nstp01,
               students[i].pe01,
               students[i].GWA);
    }
}
