/*
* Program: Basic CLI text file creator and reader
*	
* Module: header.h
*	
* Purpose: A header file with neccessary headers, prototypes and definations.
*/

#include <stdio.h>
#include <stdlib.h>

void printError(char errorString[]);
int writeEngine(void);
int readEngine(void);
int startEngine(void);

#define MAX_CHAR_LIMIT 1024
#define MAX_LINE_LIMIT 1024
#define MAX_NAME_LIMIT 50