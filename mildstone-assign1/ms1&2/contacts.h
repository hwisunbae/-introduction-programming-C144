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

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #1 here...
struct Address {
	unsigned streetNumber;
	char street[41];
	unsigned apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #1 here...
struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};