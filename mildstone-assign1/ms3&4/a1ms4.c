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


int main(void)
{
    // Declare variables here:
    struct Contact contact = {{{0}}};

    // Create a variable of type Contact and call it something self-describing like "contact"
    // - HINT: Be sure to initialize the values to 0 and empty C strings

    // Display the title
    printf("Contact Management System\n");
    printf("-------------------------\n");

    // Call the Contact function getName to store the values for the Name member
    getName(&contact.nm);

    // Call the Contact function getAddress to store the values for the Address member
    getAddress(&contact.adr);

    // Call the Contact function getNumbers to store the values for the Numbers member
    getNumbers(&contact.num);

    // Display Contact summary details
    printf("\nContact Details\n");
    printf("---------------\n");

    void printName(struct Name *nm); //this module is used for printing
    void printAddress(struct Address *adr); //this module is used for printing
    void printNumber(struct Numbers *num); //this module is used for printing

    printName(&contact.nm); //print the value from the module of get
    printf("\n");
    printAddress(&contact.adr); //print the value from the module of get
    printf("\n");
    printNumber(&contact.num); //print the value from the module of get

    // Display Completion Message
    printf("\nStructure test for Contact using functions done!\n");
    
    return 0;
}

void printName(struct Name *nm){ //this module is used for printing
  printf("Name Details\n");
  printf("First name: %s\n", nm->firstName);
  printf("Middle initial(s): %s\n", nm->middleInitial);
  printf("Last name: %s\n", nm->lastName);
}

void printAddress(struct Address *adr){ //this module is used for printing
  printf("Address Details\n"); 
  printf("Street number: %d\n", adr->streetNumber);
  printf("Street name: %s\n", adr->street);
  printf("Apartment: %d\n", adr->apartmentNumber);
  printf("Postal code: %s\n", adr->postalCode);
  printf("City: %s\n", adr->city);
}

void printNumber(struct Numbers *num){ //this module is used for printing
  printf("Phone Numbers:\n");
  printf("Cell phone number: %s\n", num->cell);
  printf("Home phone number: %s\n", num->home);
  printf("Business phone number: %s\n", num->business);
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