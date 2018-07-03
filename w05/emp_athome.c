/*
Name: Hwisun Bae
Student number: 128835170
Email: hwisunbae.hb@gmail.com
Workshop: workshop 5
Section: IPC 144 SMM
Date: 2/22/2018
*/

#define _CRT_SECURE_NO_WARNINGS

/*********************************** program starting ***********************************/

# include <stdio.h> 
# define SIZE 4 // Define Number of Employees "SIZE" to be 4

/* structure program*/
struct Employee { // Declare Struct Employee
  int idNum, age; // Declare idNum, age
  double salary; // and salary in double data form
};

/* main program */
int main(void) {
  struct Employee emp[SIZE] = { // Declare a struct Employee array "emp" with SIZE elements 
    { 0 } // and initialize all elements to zero
  };

  int opt, i, j = 0, R = 0, I, flag = 0; // Declare opt, i, I, R=0, j=0and falg to 0
  double ReSalary; // Declare ReSalary as double to store value of decimal point
  printf("---=== EMPLOYEE DATA ===---\n"); // printing start of employee data 
  do { // operate coding first and examine later
    printf("\n1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\n"); // print diverse options
    printf("\nPlease select from the above options: "); // print select options
    scanf("%d", &opt); // Capture input to opt variable

    switch (opt) {
      
    case 0: // Exit the program
      printf("\nExiting Employee Data Program. Good Bye!!!\n");
      break;

    case 1: // Display Employee Data
      printf("\nEMP ID  EMP AGE EMP SALARY");
      printf("\n======  ======= ==========\n");
      for (i = 0; i < j; i++) { // The loop construct will be run for SIZE times and will only display Employee data 
        if (emp[i].idNum > 0 && emp[i].age > 0 && emp[i].salary > 0) { //where the EmployeeID is > 0
          printf("%6d%9d%11.2lf\n", emp[i].idNum, emp[i].age, emp[i].salary); // Use "%6d%9d%11.2lf" formatting in a printf statement to display employee id, age and salary of all  employees using a loop construct
        }
      }
      break;

    case 2: // Adding Employee
      printf("\nAdding Employee");
      printf("\n===============");
      if (j < SIZE) { // Check for limits on the array and add employee data accordingly
        printf("\nEnter Employee ID: "); //Id
        scanf("%d", &emp[j].idNum); // Prompt id
        printf("Enter Employee Age: ");
        scanf("%d", &emp[j].age); // Prompt age
        printf("Enter Employee Salary: ");
        scanf("%lf", &emp[j].salary); // Prompt salary
        j++;
      }
      else {
        printf("\nERROR!!! Maximum Number of Employees Reached\n"); // If arrays can hold more, it shows error message
      }
      break;

    case 3: // Update value
      printf("\nUpdate Employee Salary");
      printf("\n======================\n");
      do {
        printf("Enter Employee ID: ");
        scanf("%d", &R); // Prompt employee ID
        for (i = 0; i < j; i++) { // Iterate emp.idNum
          if (R == emp[i].idNum) { // so that the input is the same value as in arrays
            I = i; // the way to put the same elements in emp.salary
            flag = 1; // method to stop iteration
          }
        }
      } while (flag == 0); // If input is not the same in arrays, it runs contineuosly
      printf("The current salary is %.2lf\nEnter Employee New Salary: ", emp[I].salary);
      scanf("%lf", &ReSalary); // Update emp[I.salary] to the value of Resalary
      emp[I].salary = ReSalary;
      break;

    case 4: // Remove value
      printf("\nRemove Employee");
      printf("\n===============\n");
      do {
        printf("Enter Employee ID: ");
        scanf("%d", &R); // Prompt employee ID
        for (i = 0; i < j; i++) { // Iterate emp.idNum
          if (R == emp[i].idNum) { // so that the input is the same value as in arrays
            I = i; // the way to put the same elements in emp.salary
            flag = 1; // method to stop iteration
          }
        }
      } while (flag == 0); // If input is not the same in arrays, it runs contineuosly
      printf("Employee %d will be removed\n", R);
      for (i = I; i < j; i++) { // pull the next value down one-by-one
        emp[i] = emp[(i + 1)]; // replace next value into former one
      }
      j--;  // make the size of array smaller
      break;

    default: // If users put the other numbers rather than 0,1, and 2, this structure will run
      printf("\nERROR: Incorrect Option: Try Again\n"); // Let users put another number
    }
  } while (opt != 0); // This function won't stop unless the input is 0
  return 0; // main function ends
}

/*
do {
// Print the option list
printf("1. Display Employee Information\n");
printf("2. Add Employee\n");
printf("0. Exit\n\n");
printf("Please select from the above options: ");

// Capture input to option variable
scanf("%d",&option);
printf("\n");

switch (option) {
case 0: // Exit the program

break;
case 1: // Display Employee Data
// @IN-LAB

printf("EMP ID  EMP AGE EMP SALARY\n");
printf("======  ======= ==========\n");

// Use "%6d%9d%11.2lf" formatting in a
// printf statement to display
// employee id, age and salary of
// all  employees using a loop construct

// The loop construct will be run for SIZE times
// and will only display Employee data
// where the EmployeeID is > 0

break;
case 2: // Adding Employee
// @IN-LAB

printf("Adding Employee\n");
printf("===============\n");

// Check for limits on the array and add employee
// data accordingly.



break;
default:
printf("ERROR: Incorrect Option: Try Again\n\n");
}

} while (option != 0);


return 0;
}
*/

//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/