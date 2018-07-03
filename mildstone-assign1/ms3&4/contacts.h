/* -------------------------------------------
Name: Hwisun Bae
Student number: 128835170
Email: hwisunbae.hb@gmail.com
Section: IPC 144 SMM
Date: 2018-03-13
----------------------------------------------
Assignment: 1
Milestone:  3
---------------------------------------------- */

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declarations
// Place your code from Milestone #2 here...
struct Address {
	unsigned streetNumber;
	char street[41];
	unsigned apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #2 here...
struct Numbers {
	char cell[21];
	char home[21];
	char business[21];
};

// Structure type Contact declaration
// Place your code here...
struct Contact {
	struct Name nm;
	struct Address adr;
	struct Numbers num;
} contact;

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name *nm);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address * adr);


// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers * num);
