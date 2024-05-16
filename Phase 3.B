//LIBRARIES

#include <stdio.h>
/*This line includes the Standard Input Output library, which is necessary for using functions 
like printf and scanf for input and output operations.*/

#include <stdlib.h>
/*This line includes the Standard Library, which provides functions like malloc, free, exit, etc. 
In this code, exit is used for terminating the program.*/

#include <string.h>
/*This line includes the String library, which provides functions for manipulating strings, such as strcpy, strcat, strcmp, etc. 
In this code, functions like strcspn are used for handling string operations.*/


//CONSTANT

#define MAX_NAME_LENGTH 50
/*This line defines a constant MAX_NAME_LENGTH which represents the maximum length for a student's name. 
This ensures that arrays storing names have a consistent size.*/

#define MAX_SUBJECTS 7
/*This line defines a constant MAX_SUBJECTS which represents the number of subjects for which grades will be entered. 
It is used to size arrays that hold grades.*/

#define MAX_STUDENTS 10
/*This line defines a constant MAX_STUDENTS which represents the maximum number of students that the program can handle. 
It is used to size the array that holds Student structures.*/


	/*void displayStudents(Student students[], int count):Declares a function named 
	displayStudents that takes an array of Student structures 
	and an integer count (the number of students) as parameters.*/
	
	
	
	
	
//displayStudents Function
void displayStudents(Student students[], int count) {
	
	 // Prints the header for the list of students
    printf("List of students:\n");
    
    // Loops through the array of students
    //A loop that iterates over the students array from 0 to count - 1.
    for (int i = 0; i < count; i++) {
    	 // Prints each student's number, first name, and last name
    	 // i + 1 is used to start the numbering from 1 instead of 0
        printf("%d. %s %s\n", i + 1, students[i].firstName, students[i].lastName);
    }
}



//Declares a function named displayStudentData that takes a single Student structure as a parameter.
void displayStudentData(Student student) {
	
    printf("\nStudent ID: %d\n", student.id); //Prints the student's ID with a newline before it.
    
    printf("Student Name: %s %s\n", student.firstName, student.lastName); //Prints the student's first name and last name.
    
    printf("Grades:\n"); //Prints the header "Grades:".
    
    //Declares and initializes an array of strings containing the names of the subjects.
    const char *subjects[MAX_SUBJECTS] = {"MATH101", "CMPSC113", "COMM01", "MATH01", "NSTP02", "MATH16", "PATHFIT2"};
    
    for (int i = 0; i < MAX_SUBJECTS; i++) {//A loop that iterates over the array of subjects.
    
        printf("%s: %d\n", subjects[i], student.grades[i]);//Prints each subject name and the corresponding grade from the student.grades array.
    }
    printf("GWA: %.2f\n", student.gwa);//Prints the student's General Weighted Average (GWA) to two decimal places.
}





/*Declares a function named calculateGWA that takes an array of integers grades and an integer count (the number of grades)
 as parameters and returns a floating-point number. */
float calculateGWA(int grades[], int count) {
	
    int sum = 0;//Initializes an integer variable sum to 0 to hold the sum of all grades.
    
    for (int i = 0; i < count; i++) {//A loop that iterates over the array of grades.
    
        sum += grades[i];//Adds each grade to the sum
    }
    return (float)sum / count;
    /*Calculates the General Weighted Average (GWA) by dividing the sum of grades by the count of grades and returns#
	 the result as a floating-point number.*/
}
