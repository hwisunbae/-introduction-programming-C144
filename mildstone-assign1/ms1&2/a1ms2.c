/* -------------------------------------------
Name: Hwisun Bae
Student number: 128835170
Email: hwisunbae.hb@gmail.com
Section: IPC 144 SMM
Date: 03/12/2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

void ClearLindFromReadBuffer (void){
    while(getchar()!='\n');
}

int main (void)
{
// Declare variables here:
	struct Name nm={{0}};
	struct Address adr={0};
	struct Numbers num={{0}};
	char opt = 0;

// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%31s", nm.firstName);
	
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c",&opt);
	if (opt == 'y'|| opt == 'Y') { // optional value for middle initials
		printf("Please enter the contact's middle initial(s): ");
		scanf("%7s", nm.middleInitial);
	} 
	
	printf("Please enter the contact's last name: ");
	scanf("%36s", nm.lastName);

// Contact Address Input:
    printf("Please enter the contact's street number: ");
    scanf("%u", &adr.streetNumber);
    
    printf("Please enter the contact's street name: ");
    scanf("%41s", adr.street);
    
    printf("Do you want to enter an appartment number? (y or n): ");
	scanf(" %c",&opt);
	if (opt == 'y'|| opt == 'Y') { // optional value for appartment number
		printf("Please enter the contact's appartment number: ");
		scanf("%u", &adr.apartmentNumber);
		ClearLindFromReadBuffer();
	} 

    printf("Please enter the contact's postal code: ");
    scanf("%8[^\n]",adr.postalCode); // use regular expression to contain space in a variable

    printf("Please enter the contact's city: ");
    scanf("%41s",adr.city);

// Contact Numbers Input:
    printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c",&opt);
	ClearLindFromReadBuffer();
	if (opt == 'y'|| opt == 'Y') { // optional value for cell phone number
		printf("Please enter the contact's cell phone number: ");
		scanf("%21s", num.cell);
	    ClearLindFromReadBuffer();
	} 

    printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c",&opt);
	ClearLindFromReadBuffer();
	if (opt == 'y'|| opt == 'Y') { // optional value for home phone number
		printf("Please enter the contact's home phone number: ");
		scanf("%21s", num.home);
	    ClearLindFromReadBuffer();
	} 
	
    printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c",&opt);
    ClearLindFromReadBuffer();
	if (opt == 'y'|| opt == 'Y') { // optional value for business phone number
		printf("Please enter the contact's business phone number: ");
		scanf("%21s", num.business);
	    ClearLindFromReadBuffer();
	} 

// Display Contact Summary Details
    printf("\nContact Details\n");
    printf("---------------\n");
    printf("First name: %s\n",nm.firstName);
    printf("Middle initial(s): %s\n",nm.middleInitial);
    printf("Last name: %s\n",nm.lastName);
    printf("\n");
    printf("Address Details\n");
    printf("Street number: %u\n",adr.streetNumber);
    printf("Street name: %s\n",adr.street);
    printf("Apartment: %u\n",adr.apartmentNumber);
    printf("Postal code: %s\n",adr.postalCode);
    printf("City: %s\n",adr.city);
    printf("\n");
    printf("Phone Numbers: \n");
    printf("Cell phone number: %s\n",num.cell);
    printf("Home phone number: %s\n",num.home);
    printf("Business phone number: %s\n",num.business);
    printf("\n");
    printf("Structure test for Name, Address, and Numbers Done!\n");
    
// Display Completion Message
		return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888
Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song
Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto
Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888
Structure test for Name, Address, and Numbers Done!
*/