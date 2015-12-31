#include <stdio.h>
#include <string.h>
#define SIZE 10
typedef struct info
{
	int number;
	char names[20];
}x;

x array[10];
int counter=0;

void reserve()
{
	x *p = array;
	if(counter>9)
	{
		printf("Sorry, we are full at the moment.\n");
		return;
	}
	int partysize ,i;
	char name[20];
	printf("Please enter the name of your party.\n");
	scanf("%s", name);		
	
	for(i=0; i<counter; i++, p++)
	{
		if(strcmp(name, p->names)==0)
		{
			printf("Sorry, name is taken. Enter another.\n");
			return;
		}
	}			
	printf("Now enter the amount of people in your party.\n");
	scanf("%d", &partysize);
	
		p = &array[counter];		
		strcpy(p->names, name);
		p->number = partysize;
		counter++;
		printf("Your reservation has been noted. Please wait to be seated.\n");
		
	return;
}
void tables()
{
	int i,j;
	int table;
	x *p = array;
	if(counter==0)
	{
		printf("Sorry, there are no tables available.\n");
		return;
	}
	printf("Waiter: Please enter the number of seats available at the next empty table.\n");
	scanf("%d", &table);
	for(i=0; i<counter; i++, p++)
	{
		if(p->number <= table)
		{
			printf("Seat %s, party of %d.\n", p->names, p->number);
			counter--;
			for(j=i; j<counter; j++, p++)
			{	
				strcpy(&p->names[j],&p->names[j+1]);
				*p = *(p+1);	
			}
		p->names[0] ='\0';
		p->number = 0;	
		return;
		}
	}
		
}

void list()
{
	x *p = array;
	if(counter==0)
	{
		printf("No reservations.\n");
		return;
	}
		while(*p->names != '\0')	
		{	
			printf("%s, %d\n", p->names, p->number);
			p++;
		}
		return;
}
int main(void)
{
	int userinput;
	int i;
	x *p = array;
	for(i=0; i<SIZE; i++, p++)
		p->names[i] = '\0';
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
