#include "groupassignment.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"

void printStudentList(student_t* headp){

   student_t* currentp = headp -> nextp;

   while(currentp != NULL)
   {
      printf("\n\nFirst Name> %s\nLast Name> %s\n", currentp -> fullName.firstName,
         currentp -> fullName.lastName );
      printf("gender> %c\n", currentp -> gender);
      printf("student Number> %d\n", currentp -> studentNumber);
      printf("birthday> %d/%d/%d\n", currentp -> birthday.day,
         currentp -> birthday.month, currentp -> birthday.year);
      printf("\n" );
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

   printf("%s\n", currentp -> fullName.firstName );
   printf("%s\n", currentp -> fullName.lastName );
   printf("%c\n", currentp -> gender );

   #endif

   currentp -> nextp -> nextp = NULL;
}

int verify(void){
   return 1;
}
