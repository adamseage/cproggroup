#include "groupassignment.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void search(student_t* headp)
{
	/*Decide whether the user want to seach by SN or by name (first or last)*/
	int selection = 0;
	printsearchmenu();
	while(selection < 1 || selection > 3)
   {
   	scanf("%d", &selection);
   	if(selection < 1 || selection > 3)
   	{
   		printf("\nInvalid choice\n");
   		printsearchmenu();
   	}
   }
   /*If user chose to seach by name, call the searchbyname funcion*/
   if(selection == 1)
   	searchbyname(headp);
   /*if the user chose to seach by number, call that fuction*/
   else if(selection == 2)
	{
   	searchbynumber(headp);
	}
	/*
	If the user chose to go back to main menu of if the seach functions have
	conculded, just let the function end
	*/
}


void searchbynumber(student_t* headp)
{
	int number = 0;
	printf("Enter the student number of the student you wish to find>");
	scanf("%d", &number);
	student_t* currentp = headp;
	if(headp -> nextp ==NULL)
	{
		printf("\nThere are no students in the database!");
	}
	else
	{
		while(currentp -> nextp != NULL)
		{
			if(number == currentp -> nextp -> studentNumber)
			{
				studentfound(headp, currentp);
			}
		}
		if(currentp -> nextp == NULL)
		printf("\nStudent not found");
	}
}

void searchbyname(student_t* headp)
{
	char name[MAX_NAME_SIZE];
	printf("Enter the first or last name of the student you wish to find>");
	scanf("%s", name);
	student_t* currentp = headp;
	if(headp -> nextp ==NULL)
	{
		printf("\nThere are no students in the database!");
	}
	else
	{
		while(currentp -> nextp != NULL)
		{
			if(strcmp(currentp -> nextp -> fullName.lastName, name) == 0)
			{
				studentfound(headp, currentp);
				break;
			}
			if(strcmp(currentp -> nextp -> fullName.firstName, name) == 0)
			{
				studentfound(headp, currentp);
				break;
			}
		}
		if(currentp -> nextp == NULL)
		printf("\nStudent not found");
	}
}

int studentfound(student_t* headp, student_t* previousp)
{
	student_t* foundp = previousp -> nextp;
	int selection = 0;
	/*state the student searched for has be located, display students info*/
	printf("\nStudent found:\n");
	printf("\n\nFirst Name> %s\nLast Name> %s\n", foundp -> fullName.firstName,
   foundp -> fullName.lastName );
   printf("Gender> %c\n", foundp -> gender);
   printf("Student Number> %d\n", foundp -> studentNumber);
   printf("Birthday> %d/%d/%d\n", foundp -> birthday.day,
   foundp -> birthday.month, foundp -> birthday.year);
   printf("\n" );

   /*present a menu - what would you like to do? delete, edit or leave*/
   printstudentmenu();
   while(selection < 1 || selection > 3)
   {
   	scanf("%d", &selection);
   	if(selection < 1 || selection > 3)
   	{
   		printf("\nInvalid choice\n");
   		printstudentmenu();
   	}
   }
   if(selection == 1)
   	deletestudent(previousp);
   else if(selection == 2)
	{
   	editstudent(foundp); /*TODO*/
	}
   return 1;
}

void deletestudent(student_t* previousp)
{
	/*Connect the node before the student to be deleted, to the node after*/
	previousp -> nextp = previousp -> nextp -> nextp;
	/*TODO is this a memory leak? ask tutor or beeshanga*/
}

void editstudent(student_t* foundp)
{
	/*mostly taken from al's section*/

   char firstName[MAX_NAME_SIZE];
   char lastName[MAX_NAME_SIZE];
   char gender;
   int birthDay;
   int birthMonth;
   int birthYear;

   printf("Enter New First Name>");
   scanf("%s", firstName);

   printf("Enter New Last Name>");
   scanf("%s", lastName);

   printf("Enter New letter of their gender>");
   scanf(" %c", &gender);

   printf("Please enter their new birth day in the form dd mm yyyy>");
   scanf(" %d %d %d", &birthDay, & birthMonth, &birthYear);

   strcpy(foundp -> fullName.firstName, firstName);
   strcpy(foundp -> fullName.lastName, lastName);
   foundp -> gender = gender;
   foundp -> birthday.day = birthDay;
   foundp -> birthday.month = birthMonth;
   foundp -> birthday.year = birthYear;

   printf("Student info has be updated");
}

void printstudentmenu(void)
{
	printf("\nSelect the command you wish to do:");
	printf("\n1. Delete student");
	printf("\n2. Edit Studnet");
	printf("\n3. Back to main menu\n");
}

void printsearchmenu(void)
{
	printf("\nSelect the command you wish to do:");
	printf("\n1. Search by name");
	printf("\n2. Seach by student number");
	printf("\n3. Return to main menu\n");
}
