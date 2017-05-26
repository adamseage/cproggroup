#include "groupassignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
int main (void)
{
	verify();
		int h;
		printf("lets test!\npassword is letmeout\n");
		h = hashbydivision("letmei");
		printf("here is your hash: %d\n", h);
		printf("\npassword is letmein\n");
		h = hashbydivision("letmein");
		printf("here is your hash: %d\n", h);
		return 0;

	return 1;
}
our user is storing a password in the database, we need to make sure that
it is not readable! we do this by storing a hashed password
*/


int verify(void)
{
	/*if there is no password DB, then create a new one. using write to hashfile
		if there is alread a DB, then check users password hash against the stored
		hash.
			if match then let them in (return 1),
			if no match, then repeat 3 times.
			if still no match then quit.

	*/
	welcome();
	if(checkdatabase() == 0)
	{
		int hash = getpassword();
		writehashtofile(hash);
		printf("database will be created\n");
		return 1;
	}
	else
	{
		if(checkpassword() == 1)
			return 1;
		else
			return 0;
	}
}


void welcome()
{
	printf("Welcome to the student database!\n");
}

int getpassword()
{
	int hash;
	char temp[MAX_LENGTH];
	printf("Enter your password>");
	scanf("%s", temp);
	hash = hashbydivision(temp);
	/*write over temp*/
	return hash;
}

int checkpassword()
{
	int i;
	int storedHash = readhashfromfile();
	int enteredHash = getpassword();
	for(i = 0; i < 3; i++)
	{
		if(storedHash == enteredHash)
		{
			printf("It's a match! you are in, its up to the others now..."
			return 1;
		{
		else
		{
			printf("wrong password, please try again\n");
			enteredHash = getpassword();
		}
	}
	return 0;
}

int hashbydivision(char password[])
{
	int i;
	int hash;
	int prime = 2147483647; /*a "large" prime*/

	for(i = 0; i < strlen(password); i++)
	{
		hash = (hash*256 + (int)password[i]) % prime;
	}
	return hash;
}

int readhashfromfile()
{
	int hashfromfile;
	FILE* fp = NULL;
	fp = fopen(PDB_FILE_NAME, "r");
	if(fp == NULL) /*tests if the file has opened successfully*/
	{
		printf("couldn't read database");
		return 0;
	}
	else
	{

		fscanf(fp, "%d", &hashfromfile);
		return hashfromfile;
	}
}


int writehashtofile(int hashedpword)
{
	FILE* fp = NULL;
	fp = fopen(PDB_FILE_NAME, "w");
	if(fp == NULL) /*tests if the file has opened successfully*/
	{
		printf("couldn't create database");
		return 0;
	}
	else
	{
		fprintf(fp, "%d", hashedpword);
	}
	return 1;
}

int checkdatabase(void)
{
	printf("Checking for database...\n");
	FILE* fp = NULL;
	fp = fopen(PDB_FILE_NAME, "r");
	if(fp == NULL) /*tests if the file has opened successfully*/
	{
		printf("Couldn't find a database! One will be created.");
		return 0;
	}
	else
	{
		printf("database found\n");
		return 1;
	}
}
