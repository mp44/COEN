#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int division(int dd, int q, int d);//dd = dividend, q = quotient, d = divisor

int main(void)
{
	srand((int) time(NULL));
	int counter=0;
	int i;
	for(i=0; i<10; i++)
	{
		int d = rand()%12+1;
		int q = rand()%13;
		int dd = d*q;
		if(division(dd, q, d) == 1)
		{	
			counter++;
		 	printf("Correct!");
		}
		else
		{
			printf("Sorry, the correct answer was %d.\n", q);
		}
	printf("You got %d correct.\n", counter);
	}	
}
int division(int dd, int q, int d)
{
	int answer;
	{
		printf("What is %d / %d?\n", dd, d);
		printf("Enter quotient below.\n");
		scanf("%d", &answer);
			if(q == answer)
			{
				return 1;
			}
			else
			{
				return 0;
			}
	}
	
}

			
