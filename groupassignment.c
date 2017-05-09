/*******************************************************************************
List of header files - do NOT use any other header files. Note that stdlib and
cstring are included in case you want to use any of the functions in there.
However the task can be achieved with stdio only.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
List preprocessing directives - you may define your own.
*******************************************************************************/
/* Maximum length of the string - student name. Note that all strings in C are
NULL terminated i.e. '\0' at the end of the string. Hence the length of the
actual name can be 10 characters at most*/
#define MAX_NAME_SIZE 201
/* Static file name of the text file where student list is stored */
#define DB_FILE_NAME "database"


/*******************************************************************************
List structs - you may define struct date and struct student only. Each struct
definition should have only the fields mentioned in the assignment description.
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

/*******************************************************************************/
/*******************************************************************************/

struct student {

   name_t fullName;
   int studentNumber;
   char gender;
   date_t birthday;
   condition_t medicalCondition;
   contact_t emergencyContact;
   struct student* nextp;

};

typedef struct student student_t;

/*******************************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
*******************************************************************************/

void printMenu(void);



/*******************************************************************************
Main
*******************************************************************************/


int main(void) {

   /* initialise the list array that will store the students */

   student_t* headp = NULL;
   headp = (student_t*) malloc(sizeof(student_t));

   int selection = 0;
   int exitCondition = 0;

   while (exitCondition == 0){


      printMenu();

/* Request the selection wanted by the user and save it to int selection to be
used */

      scanf("%d", &selection );


      if (selection == 1) {

    } else if (selection == 2) {

    } else if (selection == 3) {

    } else if (selection == 4) {

/* change the exit condition to cause the program to exit */

      exitCondition = 1;

    } else {

      printf("Invalid choice.\n" );

    }

  }

	return 0;
}


void printMenu(void)
{
	printf("\n\n"
	"1. Add student\n"
	"2. Search students\n"
	"3. Print a student list\n"
	"4. Exit the program\n"
	"Enter your choice>");
}
