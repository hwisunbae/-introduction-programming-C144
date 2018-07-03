/* -------------------------------------------
Name: Hwisun Bae
Student number: #128835170
Email: hwisunbae.hb@gmail.com
Section: IPC 144 SMM
Date: 2018/04/05         
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	int c;
	while ((c = getchar()) != '\n'); 
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	printf("\n");
}

// getInt:
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

// getIntInRange:
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

// yes:
int yes(void)
{
	int result = 0, flag = 1;
	char blank = 0, Y_N ;

	scanf(" %c%c", &Y_N, &blank);

	while (flag == 1) { // check if input is correct
		if ( blank != '\n' || !(Y_N == 'Y' || Y_N == 'y' || Y_N == 'N' || Y_N == 'n')) {
			
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			scanf(" %c%c", &Y_N, &blank);
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

// menu:
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
		printf("0. Exit\n\n");
		printf("Select an option:> ");

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

// ContactManagerSystem:
void ContactManagerSystem(void)
{
	int number;
	int flag = 1;
	char Y_N, blank = 0;
	struct Contact contact[MAXCONTACTS] = {
		{ { "Rick",{ '\0' }, "Grimes" },
		{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },

		{ { "Maggie", "R.", "Greene" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },

		{ { "Morgan", "A.", "Jones" },
		{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		{ "7051112222", "7052223333", "7053334444" } },
		{ { "Sasha",{ '\0' }, "Williams" },
		{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9052223333", "9052223333", "9054445555" } },
	};

	do {
		number = menu();
		if (number == 1){
			printf("\n");
			displayContacts(contact, MAXCONTACTS);
			pause();
		} else if (number == 2){
			printf("\n");
			addContact(contact, MAXCONTACTS);
			pause();
		} else if (number == 3){
			printf("\n");
			updateContact(contact, MAXCONTACTS);
			pause();
		} else if (number == 4){
			printf("\n");
			deleteContact(contact, MAXCONTACTS);
			pause();
		} else if (number == 5){
			printf("\n");
			searchContacts(contact, MAXCONTACTS);
			pause();
		} else if (number == 6){
			printf("\n");
			sortContacts(contact, MAXCONTACTS);
			pause();
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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contact[], int size, const char cellNum[]){
	int i;
	for (i = 0; i < size ; i ++){
		if (strcmp(contact[i].numbers.cell, cellNum) == 0){
			return i;
		} 
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void){
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int total){
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", total);
}

// displayContact:
void displayContact(const struct Contact * contact){
	printf(" %s",contact->name.firstName);
	if (strlen(contact->name.middleInitial) == 0)
		;
	else {
		printf(" %s",contact->name.middleInitial);
	}
	printf(" %s\n",contact->name.lastName); 
	// line 1: for name 

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business); 
	// line 2: for numbers

	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0){
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
	// line 3: for contact address
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size){
	displayContactHeader();
	int total = 0, i;
	for (i = 0 ; i < size ; i++){
		if (strlen(contact[i].numbers.cell) == 10) {
			displayContact(&contact[i]);
			total++;
		}
	}
	displayContactFooter(total);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size){
	char telNum[11];
	int indexNumber;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);

	indexNumber = findContactIndex(contact, size, telNum);

	if ( indexNumber != -1){
		printf("\n");
		displayContact(&(contact[indexNumber]));
		printf("\n");
	} else {
		printf("*** Contact NOT FOUND ***");
	}
}

// addContact:
void addContact(struct Contact contact[], int size){
	int i, total = 0;
	for(i = 0 ; i < size ; i++){
		if (strlen(contact[i].numbers.cell) == 0){
			getContact(&contact[i]);

			printf("--- New contact added! ---\n");
		} else {
			total++;
		}
	}
//clearKeyboard();
	if (total == size){
		printf("*** ERROR: The contact list is full! ***\n");
	}
}

// updateContact:
void updateContact(struct Contact contact[], int size){

	char telNum[11];
	int Y_N, indexNumber;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);

	indexNumber = findContactIndex(contact, size, telNum);

	if ( indexNumber != -1){
		printf("\nContact found:\n");
		displayContact(&(contact[indexNumber]));

		printf("\nDo you want to update the name? (y or n): ");
		Y_N = yes();
		if (Y_N == 1){
			getName(&contact[indexNumber].name);
		}

		printf("Do you want to update the address? (y or n): ");
		Y_N = yes();
		if (Y_N == 1){
			getAddress(&contact[indexNumber].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		Y_N = yes();
		if (Y_N == 1){
			getNumbers(&contact[indexNumber].numbers);
		}

		printf("--- Contact Updated! ---\n");
	} else {
		printf("*** Contact NOT FOUND ***\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contact[], int size){
	char telNum[11];
	int indexNumber, Y_N ;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telNum);

	indexNumber = findContactIndex(contact, size, telNum);

	if ( indexNumber != -1){
		printf("\nContact found:\n");
		displayContact(&(contact[indexNumber]));

		printf("\nCONFIRM: Delete this contact? (y or n): ");
		Y_N = yes();
		if (Y_N == 1){
			contact[indexNumber].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		} 
		while (Y_N == 0){
			break;
		}
	} else {
		printf("*** Contact NOT FOUND ***\n");
	}
}
// sortContacts:
void sortContacts(struct Contact contact[], int size){

}
