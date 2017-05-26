#include "groupassignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
