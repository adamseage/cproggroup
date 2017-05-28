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
		return 2;
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
	printf("\n\n\nWelcome to the student database!\n");
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
			printf("The password is correct");
			return 1;
		}
		else
		{
			printf("wrong password, please try again\n");
			enteredHash = getpassword();
		}
	}
	printf("You have entered a wrong password too many times, please try again later.\n" );
	return 0;
}
