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
#include "contactHelpers.h"
#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name * name){
	char found = 0;
	
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", name->firstName); //nm points firstName
	
	printf("Do you want to enter a middle initial(s)? (y or n): ");

	found = yes();
	if (found == 1){
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", name->middleInitial); //nm points middleInitial
	} 
	
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", name->lastName); //nm points lastName
}
// getAddress:
void getAddress(struct Address * address){
	int opt = 0, found;
	
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	
	printf("Please enter the contact's street name: ");
	scanf(" %35[^\n]", address->street); //"[^\n]"used for regular expression to get space in between letters
	
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%d", &opt);
	found = yes();
	if (found == 1){
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
	} else {
		address->apartmentNumber = 0;
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", address->postalCode);
	
	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", address->city); //adr points to city
}
// getNumbers:
void getNumbers(struct Numbers * numbers){
	char opt = 0;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &opt);
	if (opt == 'y' || opt == 'Y'){
		printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home); //num points to home
    } else {
    	numbers->home[0] = '\0';
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &opt);
    if (opt == 'y' || opt == 'Y'){
    	printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business); //num points to business
    } else {
    	numbers->business[0] = '\0';
    	clearKeyboard();
    }
}
// getContact:
void getContact(struct Contact * contact){
	getName(&(*contact).name);
	getAddress(&(*contact).address);
	getNumbers(&(*contact).numbers);
}
