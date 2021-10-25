#ifndef _HW2_H
#define _HW2_H

/**
* (A brief description of what the program does)
*
* Completion time: (the time it took you to complete the assignment)
*
* @author (Your Name), (anyone elses name who's code you used... ie Acuna)
* @version (a version number or date)
*
*/

////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

////////////////////////////////////////////////////////////////////////////////
// MACROS: CONSTANTS
#define MAX_STUDENT_NAME_LENGTH 20
#define MAX_COURSE_NAME_LENGTH 10
#define MAX_TEACHER_NAME_LENGTH 20
#define MAX_COMMENT_LENGTH 20
#define MAX_ASSIGN_NAME_LENGTH 20
#define MAX_FILENAME_LENGTH 30

////////////////////////////////////////////////////////////////////////////////
//DATA STRUCTURES

// Academic level struct
typedef enum AcademicLevel {
    Freshman = 1,
    Suphomore = 2,
    Junior = 3,
    Senior = 4
} AcademicLevel;
// score struct
typedef struct ScoreStruct {
    int assignID;
    int studentID;
    double persent;
    char comment[MAX_COMMENT_LENGTH];
} ScoreStruct;
// assignment struct
typedef struct Assign {
    int ID;
    char name[MAX_ASSIGN_NAME_LENGTH];
} Assign;
// student struct
typedef struct Student {
    int ID;
    char name[MAX_STUDENT_NAME_LENGTH];
    AcademicLevel academicLevel;
} Student;
// course struct
typedef struct Course {
    int ID;
    char name[MAX_COURSE_NAME_LENGTH];
    char instructorName[MAX_TEACHER_NAME_LENGTH];
    int numAssignments;
    Assign* assignments;
    ScoreStruct* scores;
} Course;

////////////////////////////////////////////////////////////////////////////////
//GLOBAL VARIABLES
//place to store student information
Student* students = NULL;
//place to store course information
Course* courses = NULL;
int numCourses, numStudents;

////////////////////////////////////////////////////////////////////////////////
//FORWARD DECLARATIONS

// the following should be used to read student/course data in from the file
void readFile(char* filename);
void readString(FILE* file, char** dst, int max_length);
Student* readStudents(FILE* file);
Course* readCourses(FILE* file);
Assign* readAssigns(FILE* file, int numAssigns);
ScoreStruct* readScores(FILE* file, int numAssigns);

// the following should be used to free all heap data allocated during the programs runtime
// and handle dangling pointers
void terminate();
void studentsDestructor();
void coursesDestructor();
void assignsDestructor(Assign** assigns, int numAssign);
void scoresDestructor(ScoreStruct*** scores, int numAssigns);

// the following should be used to cleanly print the data used in the program
void printStudents();
void printAssigns(Assign* assigns, int numAssigns);
void printGrades(ScoreStruct** scores, int numAssigns);
void printCourse(Course course);

// the following are mostly complete functions that define and
// control the CLI menu associated with the program
void mainMenu();
void mainMenuBranch(int option);
void subMenu(Course course);
void subMenuBranch(int option, Course course); 

// these are the 'special' functions that you are being asked to implement
void studentMenu(Course course);
void getStudentScores(Course course, int studentNo);
void assignmentMenu(Course course);
void getAssignmentScore(Course course, int assignmentNo);

// this is an optional function that parses and executes instructions defined in an input file
void performInstructions(char* iFile);

// this is a utility function to be called when input filenames are invalid
void printUsage();

/////////////////////////////////////////////////////////////////////////////////
//IMPLEMENTATION

/**
* Loads data from student/course data file
* @param filename is the name of the file
*/
void readFile(char* filename) {
    FILE* file = fopen(filename, "r");

	// read students from file
    readStudents(file);
    // read courses from file
    readCourses(file);

    fclose(file);
}
Student* readStudents(FILE* file){
    fscanf(file, "%d", &numStudents);
    // allocate memory to students pointer with size of total students.
    students = (Student*)calloc(numStudents, sizeof(Student));
    Student temp;

	// reading all students data
    for(int i=0; i<numStudents; i++){
    	int temp2;
        fscanf(file, "%d", &temp.ID);
        fscanf(file, "%s", temp.name);
        fscanf(file, "%d", &temp2);
        
        temp.academicLevel = temp2;
        
        students[i] = temp;
    }
}
Course* readCourses(FILE* file){
    fscanf(file, "%d", &numCourses);
    // allocate memory to courses pointer with size of total courses.
    courses = (Course*)calloc(numCourses, sizeof(Course));
    Course temp;

	// reading all courses data
    for(int i=0; i<numCourses; i++){
        fscanf(file, "%d", &temp.ID);
        fscanf(file, "%s", temp.name);
        fscanf(file, "%s", temp.instructorName);
        fscanf(file, "%d", &temp.numAssignments);

        temp.assignments = readAssigns(file, temp.numAssignments);
        temp.scores = readScores(file, temp.numAssignments);
        courses[i] = temp;
    }
}
Assign* readAssigns(FILE* file, int numAssigns){
	// allocate memory to assignments for a specific course
    Assign *assignments = (Assign*)calloc(numAssigns, sizeof(Assign));

	// reading assignments data
    for(int i=0; i<numAssigns; i++){
        fscanf(file, "%d", &assignments[i].ID);
        fscanf(file, "%s", assignments[i].name);
    }

    return assignments;
}
ScoreStruct* readScores(FILE* file, int numAssigns){
    // allocate memory to scores for a speific course
	ScoreStruct *scores = (ScoreStruct*)calloc(numAssigns*numStudents, sizeof(ScoreStruct));

	// reading score data
    for(int i=0; i<numAssigns*numStudents; i++){
        fscanf(file, "%d", &scores[i].assignID);
        fscanf(file, "%d", &scores[i].studentID);
        fscanf(file, "%lf", &scores[i].persent);
        fscanf(file, "%s", scores[i].comment);
    }

    return scores;
}


// helper function to return academic level name using its key.
const char* getAcademicLevel(AcademicLevel al){
	switch(al){
		case Suphomore: return "Suphomore";
		case Junior: return "Junior";
		case Senior: return "Senior";
		case Freshman: return "Freshman";
	}
}

// studnet menu to navigate user
void studentMenu(Course course){
	int option;
    printf("\nPlease choose from the following students: \n");

    for(int i=0; i<numStudents; i++)
        printf("  %d %s (%s) \n", i+1, students[i].name, getAcademicLevel(students[i].academicLevel));
    
	printf("  0 RETURN TO PREVIOUS MENU \n");
    printf("Please enter your choice ---> ");
    scanf("%d", &option);

    printf("\n%s's assignment specific grades were: \n\n", students[option-1].name);
    printf(" Assign Name \tScore \t\tComment \n");
    printf("----------------------------------------- \n");
    
    double total;
    for(int i=0; i<course.numAssignments; i++){
    	printf(" %s ", course.assignments[i].name);
    	
    	for(int j=0; j<course.numAssignments*numStudents; j++){
    		if(course.scores[j].assignID == course.assignments[i].ID && course.scores[j].studentID == students[option-1].ID){
    			printf("\t\t%.2lf \t%s \n",course.scores[j].persent, course.scores[j].comment);
    			total += course.scores[j].persent;
			}
		}
	}   	
	printf("\n%s's final grade was %.2lf \n\n", students[option-1].name, total/course.numAssignments);
}
// assignment memnu to navigate user
void assignmentMenu(Course course){
	int option;
	printf("\nPlease choose from the following assignments:");
	
	for(int i=0; i<course.numAssignments; i++)
		printf("\n  %d %s", i+1, course.assignments[i].name);
	
	printf("\n  0 RETURN TO PREVIOUS MENU \n");
    printf("Please enter your choice ---> ");
    scanf("%d", &option);
    
    double total;
    for(int i=0; i<course.numAssignments*numStudents; i++){
    	if(course.assignments[option-1].ID == course.scores[i].assignID)
    		total += course.scores[i].persent;
	}
	
	printf("\nThe average grade on %s was %.2lf \n",course.assignments[option-1].name, total/course.numAssignments );
}
// print the course received in parameter
void printCourse(Course course){
	printf("\nCourse ID: %d \n", course.ID);
	printf("Course name: %s \n", course.name);
	printf("Teacher: %s \n", course.instructorName);
	
	printf("Assigns: \n");
	for(int i=0; i<course.numAssignments; i++)
		printf("  %d %s \n", i+1, course.assignments[i].name);
	
	printf("Grade Data: \n");
	for(int i=0; i<course.numAssignments*numStudents; i++)
		printf("  %d %d %.2lf %s \n", course.scores[i].assignID, course.scores[i].studentID, course.scores[i].persent, course.scores[i].comment);
}

/**
* Implements main menu functionality, which allows user to select a course to interact with
*/
void mainMenu() {
    int input_buffer;
    printf("Course Searcher");
    do {
        printf("\n-----------------------------------\n");
        printf("Course Options");
        printf("\n-----------------------------------\n");
        int i;
        for (i = 0; i < numCourses; i++) {
            printf("   %d %s\n", courses[i].ID, courses[i].name);
        }
        printf("   0 REPEAT OPTIONS\n");
        printf("  -1 TERMINATE PROGRAM\n");
        printf("Please enter your choice ---> ");
        scanf(" %d", &input_buffer);
        mainMenuBranch(input_buffer);
    } while (1);
}

/**
* Handles menu options of main menu
* @param option is the chosen operation's option #
*/
void mainMenuBranch(int option) {
    if (option < -1 || option > numCourses) {
        printf("Invalid input. Please try again...\n");;
        while (option < -1 || option > numCourses) {
            printf("Please enter a valid option ---> ");
            scanf(" %d", &option);
        }
    }
    if (option == -1) {
        printf("Terminating program...\n");
        terminate();
    }
    else if (option == 0) {
        printf("Repeating options...\n");
    }
    else {
        Course course = courses[option - 1];
        printf("Course with name %s selected.\n", course.name);
        subMenu(course);
    }
}

/**
* Implements sub menu functionality, which allows users to select how they want to interact with course
* @course is the course to be queried
*/
void subMenu(Course course) {
    int input_buffer;
    do {
        printf("\n-----------------------------------\n");
        printf("Menu Options");
        printf("\n-----------------------------------\n");
        printf("   1 Get a student's final grades in the course\n");
        printf("   2 Get the average grade of an assignment in the course\n");
        printf("   3 Print all course data\n");
        printf("   0 REPEAT OPTIONS\n");
        printf("  -1 RETURN TO PREVIOUS MENU\n");
        printf("  -2 TERMINATE PROGRAM\n");
        printf("Please enter your choice ---> ");
        scanf(" %d", &input_buffer);
        subMenuBranch(input_buffer, course);
    } while (input_buffer != -1);
}

/**
* Handles menu options of submenu
* @param option is the chosen operation's option #
* @param course is the course struct to be queried
*/
void subMenuBranch(int option, Course course) {
    if (option < -2 || option > 3) {
        printf("Invalid input. Please try again...\n");;
        while (option < -2 || option > 3) {
            printf("Please enter a valid option ---> ");
            scanf(" %d", &option);
        }
    }
    if (option == -2) {
        printf("Terminating program...\n");
        terminate();
    }
    else if (option == -1) {
        printf("Returning to previous menu...\n");
    }
    else if (option == 0) {
        printf("Repeating options...\n");
    }
    else if (option == 1) {
       studentMenu(course);
    }
    else if (option == 2) {
        assignmentMenu(course);
    }
    else if (option == 3) {
        for(int i=0; i<numCourses; i++)
        	printCourse(courses[i]);
    }
}


/**
* Prints basic usage instructions for the program to the command line
*/
void print_usage() {
    printf("USAGE:\n./LastNameCourseReader -d <data_file_name(char*)> -c <instruction_file_name(char*)>\n");
    printf("-d refers to the required input data file containing student & course information; this must be a valid .txt file\n");
    printf("-i refers to the optionally supported 'instruction file' that provides directions for how the program should execute without CLI input; \n\t must be a valid .txt.file\n");
}

// function to free the memory allocated to students and courses.
void terminate() {	
    // free the memory allocated to students. 
    free(students);
    // free the memory allocated to courses.
    free(courses);
    
    exit(1);
}

int main(int argc, char* argv[]) {
    char* datafile = NULL;
    char* instructionfile = NULL;
    int opt;
    while ((opt = getopt(argc, argv, ":d:i:")) != -1) {
        switch (opt) {
        case 'd':
            datafile = optarg;
            break;
        case 'i':
            instructionfile = optarg;
            break;
        case ':':
            printf("option needs a value\n");
            break;
        case '?':
            printf("unknown option: %c\n", optopt);
            break;
        }
    }
    for (; optind < argc; optind++) {
        printf("Given extra arguments: %s\n", argv[optind]);
    }

    int dflen;
    if (datafile != NULL) {
        dflen = strlen(datafile);
        if (dflen >= 5
            && (strcmp(&datafile[dflen - 4], ".txt") == 0)
            && (access(datafile, F_OK) != -1)) {
            printf("Importing data from %s\n\n", datafile);
            readFile(datafile);
        }
        else {
            printf("Data file has an invalid name or does not exist.\n");
            print_usage();
            exit(1);
        }
    }
    else {
        printf("No data file name provided. This is a required field.\n");
        print_usage();
        exit(1);
    }

    int iflen;
    int ifval;
    if (instructionfile != NULL) {
        iflen = strlen(instructionfile);
        if (iflen >= 5
            && (strcmp(&instructionfile[iflen - 4], ".txt") == 0)
            && (access(instructionfile, F_OK) != -1)) {
            printf("Performing instructions defined in %s:\n", instructionfile);
            //uncomment below if doing this optional part of the assignment
            //performInstructions(instructionfile);
        }
        else {
            printf("Instruction file has an invalid name or does not exist.\n");
            print_usage();
            exit(1);
        }
    }
    else {
        printf("No instruction file provided. Using CLI:\n");
        mainMenu();
    }
    return 0;
}

#endif

