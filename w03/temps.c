// Name: Hwisun Bae
// Student Number: 128835170
// Email: hwisunbae.hb@gmail.com
// Section:	IPC 144 SMM
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#define NUMS 4	// define NUMS to 4 in this entire coding source
#include <stdio.h>	// start for int, for, while

int main(void)
{
	int i, high, low, totalHigh = 0, totalLow = 0;	// set variables 
	int highest = 0, lowest = 0;	// set highest and lowest to the middle value in the range from 40 to -40
	int highestDay, lowestDay;	// set variables for certain days

	printf("---=== IPC Temperature Analyzer ===---");	// print the first sentence
	for (i = 0; i < NUMS; i++)	// By using constant number, NUMS, run iteration for 3 times
	{
		printf("\nEnter the high value for day %d: ", i + 1);	// print 'high value'
		scanf("%d", &high);	//	prompt 'high value'
		printf("\nEnter the low value for day %d: ", i + 1);	// print 'low value'
		scanf("%d", &low);	// prompt 'low value'
		while (high > 40 || low > 40 || high < -40 || low < -40 || high < low)	//	if the range are not in -40<value<40 or high is lower than low value, prompt 'values' again
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");	// print warning
			printf("\nEnter the high value for day %d: ", i + 1);	//	print 'high value'
			scanf("%d", &high);	//prompt 'high value'
			printf("\nEnter the low value for day %d: ", i + 1);	// print 'low value'
			scanf("%d", &low);	// prompt 'low value'
		}
		totalHigh += high;	// add high into totalHigh constantly under the condition where the values are in the right range
		totalLow += low;	// add low into totalLow constantly under the condition where the values are in the right range

		if (highest < high)	// if high is higher than highest (0),
		{
			highest = high;	// regard highest as high
			highestDay = i + 1;	// remember highestDay so that it will be printed later
		}
		if (lowest > low)	// if low is lower than lowest (0),
		{
			lowest = low;	// regard lowest as low
			lowestDay = i + 1;	// remember lowestDay so that it will be printed later
		}
	}
	double avg = ((double)totalLow + totalHigh) / (NUMS * 2);	// set avg in double format 
	printf("\nThe average (mean) temperature was: %.2lf\n", avg);	// print avg in 2 decimal points
	printf("The highest temperature was %d, on day %d\n", highest, highestDay);	// print higest temperature and the day when it was highest
	printf("The lowest temperature was %d, on day %d\n", lowest, lowestDay);	// print lowest temperature and the day when it was lowest

	return 0;	// end
}