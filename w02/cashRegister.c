/*
Name:      <Hwisun Bae>
Student#:  <128835170>
Section:   <IPC-144SMM>
*/

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include <stdio.h>	//information about double, int identifier

int main(void)	// start for double and integer
{
	double amountOwing;	// declare payment in a form of 'double'
	printf("Please enter the amount to be paid: $");	// print this sentence to a user
	scanf("%lf", &amountOwing);	// let a user put the value of payment

	int gst = ((amountOwing * .13) + .005) * 100;	// gst is an integer, which is 8.68*.13+0.005=1.1334->113
	printf("GST: %.2lf\n", (double)gst / 100.0);	// print the value of gst in a double form. (1.13)

	double balanceOwing;	// balanceOwing is a double
	balanceOwing = amountOwing + ((double)gst / 100.0);	// the value that a user entered and GST added together (9.81)
	printf("Balance owing: $%.2lf\n", balanceOwing);	// print the value of balanceOwing in double form with 2 decimal point (9.81)

	int loonies = balanceOwing / 1;	// put an integer value of balanceOwing into loonies
	printf("Loonies required: %d", loonies);	// print the integer value of loonies

	int balance_loonies;	// balance_loonies is an integer
	balance_loonies = ((int)(balanceOwing * 100.0 + .005)) % (loonies * 100);	// By using modulus, balance_loonies became 81=981%900
	double bl = (double)balance_loonies / 100.0;	// make forementioned balance_loonies a double, which is 0.81=81/100
	printf(", balance owing $%.2lf\n", bl);	// print the double bl, which is 0.81, with 2 decimal points

	int quarters = bl / 0.25;	// quarters is an integer, which is bl(balance_loonies) devided by .25
	printf("Quarters required: %d", quarters);	// print the integer value of quarters

	double balance_quarters = (int)(bl * 100) % 25;	// balance_quarters is a double calculating the difference between balance and the value of quarters 
	printf(", balance owing $%.2lf\n", balance_quarters / 100);	// print the double value of balance_quarters with 2 decimal points

	int dimes = balance_quarters / 10;	// dimes is an integer, which is balance_quarters devided by .1
	printf("Dimes required: %d", dimes);	// print the integer value of dimes

	double balance_dimes = (int)balance_quarters % 10;	// balance_dimes is a double calculating the difference between balance and the value of dimes 
	printf(", balance owing $%.2lf\n", balance_dimes / 100);	// print the double value of balance_dimes with 2 decimal points

	int nickels = (balance_dimes / .5) / 10;	// nickels is an integer, which is balance_dimes devided by .05
	printf("Nickels required: %d", nickels);	// print the integer value of nickels

	double balance_nickels = (int)balance_quarters % 5;	// balance_nickels is a double calculating the difference between balance and the value of nickels
	printf(", balance owing $%.2lf\n", balance_nickels / 100);	// print the double value of balance_nickels with 2 decimal points

	int pennies = (balance_nickels / .1 + 0.005) / 10;	// pennies is an integer, which is balance_nickels devided by .01
	printf("Pennies required: %d", pennies);	// print the integer value of pennies

	double balance_pennies = (int)balance_nickels % 1;	// balance_pennies is a double calculating the difference between balance and the value of pennies 
	printf(", balance owing $%.2lf\n", balance_pennies / 100);	// print the double value of balance_pennies with 2 decimal points

	return 0; // return to operating system
}