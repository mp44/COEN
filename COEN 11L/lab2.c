#include <stdio.h>
#include <string.h>
#define SIZE 10
char names[10][20];
int counter=0;
int number[10];

void reserve()
{
	if(counter>9)
	{
		printf("Sorry, we are full at the moment.\n");
		return;
	}
	int partysize ,i;
	char name[20];
	printf("Please enter the name of your party.\n");
	scanf("%s", name);		
	
	for(i=0; i<counter; i++)
	{
		if(strcmp(name, names[i])==0)
		{
			printf("Sorry, name is taken. Enter another.\n");
			return;
		}
	}			
	printf("Now enter the amount of people in your party.\n");
	scanf("%d", &partysize);
	
	
		strcpy(names[counter], name);
		number[counter] = partysize;
		counter++;
		printf("Your reservation has been noted. Please wait to be seated.\n");
		
	return;
}
void tables()
{
	int i,j;
	int table;
	if(counter==0)
	{
		printf("Sorry, there are no tables available.\n");
		return;
	}
	printf("Waiter: Please enter the number of seats available at the next empty table.\n");
	scanf("%d", &table);
	for(i=0; i<counter; i++)
	{
		if(number[i] <= table)
		{
			printf("Seat %s, party of %d.\n", names[i], number[i]);
			counter--;
			for(j=i; j<counter; j++)
			{	
				strcpy(names[j], names[j+1]);
				number[j] = number[j+1];	
			}
		names[counter][0] = '\0';
		number[counter] = '\0';	
		return;
		}
	}
		
}

void list()
{
	int i = 0;
	if(counter==0)
	{
		printf("No reservations.\n");
		return;
	}
	for(i=0; i<=counter; i++)
	{
		while(names[i][0] != '\0')	
		{	
			printf("%s, %d\n", names[i], number[i]);
			i++;
		}
		return;
	}	
}
int main(void)
{
	int userinput;
	int i;
	for(i=0; i<SIZE; i++)
		names[i][0] = '\0';
	while(1)
	{
		printf("Customers: Press 1 to enter party name and number.\nWaiters: Press 2 to enter size of table available.\nPress 3 to show list, name, and number.\nPress 4 to exit.\n");
		scanf("%d", &userinput);
			
			switch(userinput)
			{
				case 1:
					reserve();
					break;
				case 2:
					tables();
					break;
				case 3:
					list();
					break;
				default: 
					return 0;
			}
		
	}	
}
