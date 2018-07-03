//--------------------------------------------------
// Name: Hwisun Bae          
// Student Number: 128835170
// Email: hwisunbae.hb@gmail.com         
// Section: IPC 144 SMM       
// Workshop: 4       
//--------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
// Place your code below
#include <stdio.h> // start
int main(void) {    // start for functions
	int NumDay; // intialize NumDay
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");    // print
	printf("Please enter the number of days, between 3 and 10, inclusive: "); // alert that users have to put number between 3 and 10
	scanf("%d", &NumDay); // prompt user to put the number of days
	while (NumDay < 3 || NumDay>10) { // iterate until the number of days is between 3 and 10
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");   // another alert
		scanf("%d", &NumDay); // keep prmopting until it satisfy the requirements
	}printf("\n");
	int arrHigh[NumDay], arrLow[NumDay]; // initialize two arrays for high temperature and low temperature
	int i;
	for (i = 0; i < NumDay; i++) {   // print and prompt what temperature occurs
		printf("Day %d - High: ", i + 1);
		scanf("%d", &arrHigh[i]); // for high temperature
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &arrLow[i]);  // for low temperature
	}printf("\n");
	char stDay[] = "Day", stHi[] = "Hi", stLow[] = "Low"; // initialize the strings 
	int j;
	printf("%-5s%-4s%1s\n", stDay, stHi, stLow);  // put white blanks in between strings by using numbers
	for (j = 0; j < NumDay; j++) {   // to show what value is contained in every single elements
		printf("%-5d%-5d%2d\n", j + 1, arrHigh[j], arrLow[j]);    // make arrays look like a box in orders
	}
	int HighTemp = arrHigh[0], HighDay = 1, k; // initialize  HighTemp and HighDay
	for (k = 0; k < NumDay; k++) {
		if (arrHigh[k] > HighTemp) {    // if the value of the k elements is bigger the previous one,
			HighTemp = arrHigh[k];  // the higher value is declared as a HighTemp
			HighDay = k + 1;    // remember what day has the highest temperature
		}
	}
	int LowTemp = arrLow[0], LowDay = 1, m;    // initialize LowTemp and LowDay
	for (m = 0; m < NumDay; m++) {
		if (arrLow[m] < LowTemp) {  // if the vaue of the m elements is lower than the previous one
			LowTemp = arrLow[m];    // LowTemp is changed into the lower value 
			LowDay = m + 1; // remember what dya has the lowest temperature
		}
	}
	printf("\n");   // swith a line
	printf("The highest temperature was %d, on day %d\n", HighTemp, HighDay);   // print what temperature is the higest and the day when it happened
	printf("The lowest temperature was %d, on day %d\n", LowTemp, LowDay);  // print what temperature is the lowest and the day when it happened
	int AvgDay;

	printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", NumDay);    //print
	scanf("%d", &AvgDay);   // put the value into AvgDay

	while (AvgDay >= 0) {    // this statment should be run until AvgDay is less then 0
		if (AvgDay > NumDay) {
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", NumDay); // if the input is higher than the value of NumDay, it's printed as 'invalid'
		}
		else if (0 < AvgDay && AvgDay <= NumDay) {    // if AvgDay is located in between 0 and Numday, statments below runs.
			double Avg = 0.0;   // declare Avg as a double so that it prints out numbers with decimal points
			int Total = 0;
			for (j = 0; j < AvgDay; j++)
				Total += arrHigh[j] + arrLow[j];    // Total is incremented by the sum of arrHigh and arrLow
			Avg = Total / ((double)AvgDay * 2); // Avg is total devided by double of AvgDay
			printf("\nThe average temperature up to day %d is: %.2lf\n", AvgDay, Avg);  // print AvgDay and Avg
			printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", NumDay); // let users know this statements is endless until the value is negative
		}

		scanf("%d", &AvgDay);   // either way of if ends up making users to put the value of AvgDay
	}

	printf("\nGoodbye!\n");

	return 0;   // end
}
