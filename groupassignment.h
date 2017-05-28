/*******************************************************************************
List of header files
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 16
#define PDB_FILE_NAME "passwordHash"
#define MAX 256
/*#define DEBUG*/

/*#ifdef DEBUG
----code------
#endif   */

/*******************************************************************************
List of preprocessing directives
*******************************************************************************/
/* Maximum length of the string - student name. Note that all strings in C are
NULL terminated i.e. '\0' at the end of the string. Hence the length of the
actual name can be 10 characters at most*/
#define MAX_NAME_SIZE 201
/* Static file name of the text file where student list is stored */
#define DB_FILE_NAME "database"


/*******************************************************************************
List structs
*******************************************************************************/

struct date {

   int day;
   int month;
   int year;

};

typedef struct date date_t;

/*******************************************************************************/

struct name {

   char firstName[MAX_NAME_SIZE];
   char middleName[MAX_NAME_SIZE];
   char lastName[MAX_NAME_SIZE];


};

typedef struct name name_t;

/*******************************************************************************/

struct condition {

   char conditionName[MAX_NAME_SIZE];
   char symptoms[MAX_NAME_SIZE];
   char actions[MAX_NAME_SIZE];
   char medicine[MAX_NAME_SIZE];

};

typedef struct condition condition_t;

/*******************************************************************************/

struct contact {

   name_t fullName;
   int contactNumber;
   char relationship[MAX_NAME_SIZE];

};

typedef struct contact contact_t;

/*******************************************************************************
Main student structure
*******************************************************************************/

struct student {

   name_t fullName;
   char gender;
   int studentNumber;
   date_t birthday;
   condition_t medicalCondition;
   contact_t emergencyContact;
   struct student* nextp;

};

typedef struct student student_t;

/*******************************************************************************
Function prototypes
*******************************************************************************/

void printMenu(void);
int  addStudent(student_t* headp);
void printStudentList(student_t* headp);
void append1(char firstName[], char lastName[], char gender, int studentNumber,
   int birthDay, int birthMonth, int birthYear, student_t* headp);
int verify(void);
void welcome(void);
int hashbydivision(char password[]);
int getpassword(void);
int writehashtofile(int hashedpword);
int readhashfromfile(void);
int checkpassword(void);
int checkdatabase(void);
int importDatabase(student_t* headp);
int writedatabase(student_t* headp);
void search(student_t* headp);
void searchbynumber(student_t* headp);
void searchbyname(student_t* headp);
int studentfound(student_t* headp, student_t* previousp);
void deletestudent(student_t* previousp);
void editstudent(student_t* foundp);
void printstudentmenu(void);
void printsearchmenu(void);
