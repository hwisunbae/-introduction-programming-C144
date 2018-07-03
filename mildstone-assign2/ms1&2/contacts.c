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

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"


// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:



// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name * name){
	char opt = 0, found = 0;
	
	printf("Please enter the contact's first name: ");
	scanf("%s", name->firstName); //nm points firstName
	
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &opt);

	found = yes();
	if (found == 1){
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", name->middleInitial); //nm points middleInitial
	}
	
	printf("Please enter the contact's last name: ");
	scanf("%s", name->lastName); //nm points lastName
}

// getAddress:
void getAddress(struct Address * address){
	int opt = 0, found;
	
	printf("Please enter the contact's street number: ");
	scanf("%u", &address->streetNumber);
	address->streetNumber = getInt();
	
	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]s", address->street); //"[^\n]"used for regular expression to get space in between letters
	
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%d", &opt);
	found = yes();
	if (found == 1){
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);
		address->apartmentNumber = getInt();
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]s", address->postalCode); //"[^\n]"used for regular expression
	
	printf("Please enter the contact's city: ");
	scanf("%s", address->city); //adr points to city
}

// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers * numbers){
	char opt = 0;
	
	printf("Please enter the contact's cell phone number: ");
	scanf("%s", numbers->cell);

	
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &opt);
	if (opt == 'y' || opt == 'Y'){
		printf("Please enter the contact's home phone number: ");
        scanf(" %s", numbers->home); //num points to home
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &opt);
    if (opt == 'y' || opt == 'Y'){
    	printf("Please enter the contact's business phone number: ");
        scanf(" %s", numbers->business); //num points to business
    }
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact * contact){
	getName(&(*contact).name);
	getAddress(&(*contact).address);
	getNumbers(&(*contact).numbers);
}
