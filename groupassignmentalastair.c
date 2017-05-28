#include "groupassignment.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printStudentList(student_t* headp){

   student_t* currentp = headp -> nextp;

   while(currentp != NULL)
   {
      printf("\n\n\tFirst Name>       %s\n\tLast Name>        %s\n",
         currentp -> fullName.firstName, currentp -> fullName.lastName );
      printf("\tgender>           %c\n", currentp -> gender);
      printf("\tstudent Number>   %d\n", currentp -> studentNumber);
      printf("\tbirthday>         %d/%d/%d\n", currentp -> birthday.day,
         currentp -> birthday.month, currentp -> birthday.year);
      currentp = currentp -> nextp;
   }

}


int addStudent(student_t* headp){

   char firstName[MAX_NAME_SIZE];
   char lastName[MAX_NAME_SIZE];
   char gender;
   int studentNumber;
   int birthDay;
   int birthMonth;
   int birthYear;



   printf("Enter First Name>");
   scanf("%s", firstName);

   printf("Enter Last Name>");
   scanf("%s", lastName);

   printf("Enter letter of their gender>");
   scanf(" %c", &gender);

   printf("Please enter their student number>");
   scanf(" %d", &studentNumber);

   printf("Please enter their birth day in the form dd mm yyyy>");
   scanf(" %d %d %d", &birthDay, & birthMonth, &birthYear);

   append1(firstName, lastName, gender, studentNumber, birthDay, birthMonth,
      birthYear, headp);

   writedatabase(headp);

   return 0;

}


void append1(char firstName[], char lastName[], char gender, int studentNumber,
   int birthDay, int birthMonth, int birthYear, student_t* headp)
{
   student_t* currentp = headp;
   while(currentp -> nextp != NULL)
   {
    currentp = currentp->nextp;
   }

   currentp -> nextp = (student_t*)malloc(sizeof(student_t));

   strcpy(currentp -> nextp -> fullName.firstName, firstName);
   strcpy(currentp -> nextp -> fullName.lastName, lastName);
   currentp -> nextp -> gender = gender;
   currentp -> nextp -> studentNumber = studentNumber;
   currentp -> nextp-> birthday.day = birthDay;
   currentp -> nextp -> birthday.month = birthMonth;
   currentp -> nextp -> birthday.year = birthYear;

   #ifdef DEBUG

   printf("\nError mode for Append function\n");

   printf("F name in list>%s\n", currentp -> nextp -> fullName.firstName );
   printf("L name in list>%s\n", currentp -> nextp -> fullName.lastName );
   printf("Gender in list>%c\n", currentp -> nextp -> gender );

   #endif

   currentp -> nextp -> nextp = NULL;
}


int writedatabase(student_t* headp){

/* open the database to write */

   FILE * fp = NULL;

   fp = fopen(DB_FILE_NAME, "w");

/* determine if it was able to open the file */

   if (fp == NULL)
   {
      printf("file error\n" );
      return 1;
   }

/* for each of the current students in the linked list print them to the
database as readable text */

   student_t* currentp = headp -> nextp;

   int count = 0;

   while(currentp != NULL)
   {
      count++;
      currentp = currentp -> nextp;
   }

   fprintf(fp, "%d\n", count);

   currentp = headp -> nextp;

   while(currentp != NULL)
   {
      fprintf(fp, "%s\n%s\n",
         currentp -> fullName.firstName, currentp -> fullName.lastName );
      fprintf(fp, "%c\n", currentp -> gender);
      fprintf(fp, "%d\n", currentp -> studentNumber);
      fprintf(fp, "%d/%d/%d\n", currentp -> birthday.day,
         currentp -> birthday.month, currentp -> birthday.year);
      fprintf(fp, "\n" );
      currentp = currentp -> nextp;
   }

/* close the database */

   fclose(fp);


   return 0;

}

/* not yet correct*/

int importDatabase(student_t* headp){

   #ifdef DEBUG
   printf("\nError mode for importing the database\n");
   #endif

   int count = 0;
   int i;

   char firstName[MAX_NAME_SIZE] = "\0";
   char lastName[MAX_NAME_SIZE] = "\0";
   char gender;
   int studentNumber;
   int birthDay;
   int birthMonth;
   int birthYear;

   FILE * fp = NULL;
   fp = fopen(DB_FILE_NAME, "r");

   if (fp == NULL)
   {
      printf("file error\n" );
      return 1;
   }

   fscanf(fp, "%d", &count );

   printf("\nYou have %d students", count);

   for ( i = 0; i < count; i++) {



      fscanf(fp, "%s", firstName);
      #ifdef DEBUG
      printf("\nis this the right name>%s\n", firstName);
      #endif

      fscanf(fp, " %s", lastName);
      fscanf(fp, " %c", &gender);

      #ifdef DEBUG
      printf("Is this the right gender>%c\n", gender);
      #endif

      fscanf(fp, " %d", &studentNumber);

      #ifdef DEBUG
      printf("Is this the right student number>%d\n", studentNumber);
      #endif

      fscanf(fp, "%d/%d/%d%*c", &birthDay, & birthMonth, &birthYear);

      append1(firstName, lastName, gender, studentNumber, birthDay, birthMonth,
         birthYear, headp);

   }



   fclose(fp);



   return 0;
}
