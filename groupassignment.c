#include "groupassignment.h"

int main(void) {

   /* initialise the list array that will store the students */

   student_t* headp = NULL;
   headp = (student_t*) malloc(sizeof(student_t));
   headp -> nextp = NULL;

   int selection = 0;
   int exitCondition = 0;
   int entryConfirmation;

   entryConfirmation = verify();

   if (entryConfirmation == 0) {
      return 0;
   }

   else if (entryConfirmation == 1) {
      if (importDatabase(headp) == 1) {
         printf("Unfortunately the database import failed, please try reopening the program\n");
         return 0;
      }
   }

   while (exitCondition == 0){

      printMenu();

/* Request the selection wanted by the user and save it to int selection to be
used */

      scanf("%d", &selection );

      if (selection == 1) {

      addStudent(headp);

    } else if (selection == 2) {

      /*searchStudents();*/

    } else if (selection == 3) {

      printStudentList(headp);

    } else if (selection == 4) {

/* save thedatabase to confirm the data is the latest */
      writedatabase(headp);

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
