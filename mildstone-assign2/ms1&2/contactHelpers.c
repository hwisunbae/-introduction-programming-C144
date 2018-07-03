/* -------------------------------------------
Name: Hwisun Bae
Student number: #128835170
Email: hwisunbae.hb@gmail.com
Section: IPC 144 SMM
Date: 2018/03/22           
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#define MIN 100 // set MIN and MAX values
#define MAX 500

#include <stdio.h>
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	int c;
	while ((c = getchar()) != '\n'); 
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	int value, flag = 1;
	char NL = 0;

	scanf("%d%c", &value, &NL);
	do {
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &value, &NL);
		}
		else {
			flag = 0;
		}
	} while (flag == 1); 
	return value; 
}

// getIntInRange function definition goes here:
int getIntInRange(int paramOne, int paramTwo)
{
	int number;
	number = getInt();
	while (paramOne > number || number > paramTwo) { 
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", paramOne, paramTwo);
		scanf("%d", &number);
	}
	return number; 
}

// yes function definition goes here:
int yes(void)
{
	int result = 0, flag = 1;
	char blank = 0, Y_N = 0;

	scanf(" %c%c", &Y_N, &blank);

	while (flag == 1) { // check if input is correct
		if ( blank != '\n' || !(Y_N == 'Y' || Y_N == 'y' || Y_N == 'N' || Y_N == 'n')) {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			scanf("%c%c", &Y_N, &blank);
		}
		else {
			flag = 0;
		}
	}

	if (Y_N == 'Y' || Y_N == 'y')
		result = 1;
	else if (Y_N == 'N' || Y_N == 'n')
		result = 0;
	return result; 
}

// menu function definition goes here:
int menu(void)
{
	int opt, confirm;
	char blank;
	do {
		printf("Contact Management System\n");
		printf("-------------------------\n");
		printf("1. Display contacts\n");
		printf("2. Add a contact\n");
		printf("3. Update a contact\n");
		printf("4. Delete a contact\n");
		printf("5. Search contacts by cell phone number\n");
		printf("6. Sort contacts by cell phone number\n");
		printf("0. Exit\n");
		printf("\nSelect an option:> ");

		confirm = scanf("%d%c", &opt, &blank);
		if (blank == '\n' && (0 <= opt && opt <= 6)){
			break;
		} else if (confirm == 0 || blank != '\n'){
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: "); 
			scanf("%d", &opt);
			clearKeyboard();
		} else {
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: "); 
			scanf("%d", &opt);
			clearKeyboard();
		}
	} while (0 > opt || opt > 6);
	return opt; 
	
}

// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void)
{
	int number;
	int flag = 1;
	char Y_N, blank = 0;
	do {
		number = menu();
		if (number == 1){
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
		} else if (number == 2){
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
		} else if (number == 3){
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
		} else if (number == 4){
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
		} else if (number == 5){
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
		} else if (number == 6){
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
		} else if (number == 0){
			printf("\nExit the program? (Y)es/(N)o: ");
			scanf(" %c%c", &Y_N, &blank);
			printf("\n");
			if (Y_N == 'Y' || Y_N == 'y'){
				printf("Contact Management System: terminated\n");
				flag = 0;
			} 
		} else {
			flag = 0;
		}
	} while (flag == 1);
}