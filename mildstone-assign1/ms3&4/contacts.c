/* -------------------------------------------
Name: Hwisun Bae
Student number: 128835170
Email: hwisunbae.hb@gmail.com
Section: IPC 144 SMM
Date: 2018-03-13
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:

void ClearLineFromButter(){
    while ( getchar() != '\n');
}

void getName(struct Name *nm){
    char opt = 0;
    
	printf("Please enter the contact's first name: ");
	scanf("%s", nm->firstName); //nm points firstName
	
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &opt);
    ClearLineFromButter();
	if (opt == 'y' || opt == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", nm->middleInitial); //nm points middleInitial
	}
	
	printf("Please enter the contact's last name: ");
	scanf("%s", nm->lastName); //nm points lastName
}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address * adr){
    char opt = 0;
    
	printf("Please enter the contact's street number: ");
	scanf("%u",&adr->streetNumber);
	
	printf("Please enter the contact's street name: ");
	scanf("%40s[^\n]", adr->street); //"[^\n]"used for regular expression to get space in between letters
	
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &opt);
	if (opt == 'y' || opt == 'Y'){
	    printf("Please enter the contact's apartment number: ");
		scanf("%u", &adr->apartmentNumber); //adr points to apartmentNumber
	}
	
	ClearLineFromButter();
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s", adr->postalCode); //"[^\n]"used for regular expression
	
	printf("Please enter the contact's city: ");
	scanf("%s", adr->city); //adr points to city
}


// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers * num){
    char opt = 0;
    
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf(" %c", &opt);
	if (opt == 'y' || opt == 'Y'){
	    printf("Please enter the contact's cell phone number: ");
		scanf("%s", num->cell); //num points to cell
	}
	
	printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c", &opt);
    if (opt == 'y' || opt == 'Y'){
        printf("Please enter the contact's home phone number: ");
        scanf(" %s", num->home); //num points to home
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &opt);
    if (opt == 'y' || opt == 'Y'){
        printf("Please enter the contact's business phone number: ");
        scanf(" %s", num->business); //num points to business
    }
}


/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Wilma
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Dino
Please enter the contact's last name: Flintstone

Please enter the contact's street number: 100
Please enter the contact's street name: Bedrock
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 14
Please enter the contact's postal code: Z8Z 7R7
Please enter the contact's city: Markham

Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 647-505-5555
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 905-222-3333
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-491-5050

Contact Details
---------------
Name Details
First name: Wilma
Middle initial(s): Dino
Last name: Flintstone

Address Details
Street number: 100
Street name: Bedrock
Apartment: 14
Postal code: Z8Z 7R7
City: Markham

Phone Numbers:
Cell phone number: 647-505-5555
Home phone number: 905-222-3333
Business phone number: 416-491-5050

Structure test for Contact using functions done!
*/