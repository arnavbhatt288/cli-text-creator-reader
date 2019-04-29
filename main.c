/*
* Program: Basic CLI text file creator and reader
*	
* Module: main.c
*	
* Purpose: Main code.
*/

#include "header.h"

char name[MAX_NAME_LIMIT];
char sentence[MAX_CHAR_LIMIT];

void printError(char errorString[])
{
	printf("Error! - %s The program will now exit...\n", errorString);
}

int readEngine(void)
{
	FILE *fptr;
	
	printf("Enter the name of the text file that you want to read -\n");
	scanf("%s", &name);
	fptr = fopen(name, "r");
	
	if(fptr == NULL)
	{
		printError("File not found!");
		exit(1);
	}
	
	printf("\e[1;1H\e[2J");
	
	while(fgets(sentence, MAX_CHAR_LIMIT, fptr))
	{
		printf("%s", sentence);
	}
	
	if(feof(fptr))
	{
		printf("\nYou have reached at the end of file.\n");
		fclose(fptr);
		exit(0);
	}
	
	return 0;
}

int writeEngine(void)
{
	FILE *fptr;

	printf("Enter the name of the text file you want.\n");
	printf("After writing press Ctrl + C to exit the program -\n");
	scanf("%s", &name);
	fptr = fopen(name, "w");
	
	printf("\e[1;1H\e[2J");
	
	for(int i = 0; i <= MAX_LINE_LIMIT; i++)
	{
		fflush(fptr);
		fgets(sentence, MAX_CHAR_LIMIT, stdin);
		fprintf(fptr, "%s", sentence);
	}
	
	fclose(fptr);
	return 0;
}

int main()
{
	int choice;
	
	printf("\e[1;1H\e[2J");
	
	printf("+----------------------------+\n");
	printf("|                            |\n");
	printf("| Text creator and editor    |\n");
	printf("|                            |\n");
	printf("| Copyleft 2019 Arnav Bhatt  |\n");
	printf("|                            |\n");
	printf("+----------------------------+\n");

	printf("Choose the option below -\n");
	printf("1. Read the text file\n");
	printf("2. Create a new text file and write something in it\n\n");
	scanf("%i", &choice);
	
	if(choice == 1)
	{
		readEngine();
	}
	
	else if(choice == 2)
	{
		writeEngine();
	}
	
	else
	{
		printError("Wrong choice!");
		exit (1);
	}
	
	return 0;
}
