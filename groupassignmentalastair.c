#include "groupassignment.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"

void printStudentList(student_t* headp){

   student_t* currentp = headp -> nextp;

   while(currentp != NULL)
   {
      printf("\n\nFirst Name:%s Last Name:%s\n", currentp -> fullName.firstName, currentp -> fullName.lastName );
      printf("gender %c\n", currentp -> gender);
      printf("\n" );
      currentp = currentp -> nextp;
   }

}


int addStudent(student_t* headp){

   char firstName[MAX_NAME_SIZE];
   char lastName[MAX_NAME_SIZE];
   char gender;

   printf("Enter First Name>");
   scanf("%s", firstName);

   printf("Enter Last Name>");
   scanf("%s", lastName);

   printf("Enter letter of their gender>");
   scanf(" %c", &gender);

   append(firstName, lastName, gender, headp );

   return 0;

}


void append(char firstName[], char lastName[], char gender, student_t* headp)
{
   student_t* currentp = headp;
   while(currentp -> nextp != NULL)
   {
    currentp = currentp->nextp;
   }

   currentp -> nextp = (student_t*)malloc(sizeof(student_t));

   strcpy(firstName, currentp -> nextp -> fullName.firstName);
   strcpy(lastName, currentp -> nextp -> fullName.lastName);
   currentp -> nextp -> gender = gender;
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
