#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
	int number;
	char names[20];
	struct node *next;
}x;

x *head = (x*)NULL;
x *tail = (x*)NULL;

void insert()
{
	x *p;
	x *q;
	x *temp;
	p = head;

	char nametemp[20];
	int numbertemp;
	
	
	temp = (x *)malloc(sizeof(x));//create node under pointer temp	
	if(temp == NULL) //if temp points to null, then no memory is available. 
	{
		printf("No memory available.\n");
		return;
	}
	
	printf("Please enter your name.\n");
	scanf("%s", nametemp);

	
	while(p!=NULL) //checks for duplicates
	{
		if(strcmp(p->names, nametemp) == 0)
			{
				printf("Sorry, name is taken. Please enter another.\n");
				return;
			}
		p = p->next;
	}
	
	strcpy(temp->names, nametemp);
	if(head == NULL) //if list is empty, point both head and tail to temp and tail->next to null
	{
		head = temp;
		tail = temp;
		temp->next = NULL;
	}
		
	else //if list has nodes, add to last node in list
	{
		temp->next = NULL; 
		tail->next = temp;
		tail = temp;
	}
	printf("Now enter number of seats.\n");
	scanf("%d",&numbertemp);
	
	temp->number = numbertemp;
	return;
}	

	
void delete() 
{
	x *p;
	x *q;
	int numbertemp;
	p = q = head;
	
	printf("Please enter table size.\n");
	scanf("%d", &numbertemp);
	if(head == NULL) //if head points to null, list is empty
	{
		printf("List is empty.\n");
		return;
	}
	while(p!=NULL) //while p is not null, keep pointer q behind pointer p, increment pointer p
	{
		if(numbertemp >= p->number) //break if amount of seats are >= than those requested in reserve
			break;
		else
		{	
			printf("Sorry, no seats available.\n");
			return;
		}
		q = p;
		p = p->next;
	}	
	if(head == tail) //if only one node in list, point head and tail to null
	{
		head = tail = NULL;
	}
	else if(p == head) //if deleting first node
	{
		head = head->next; //releases first node, points head to second node
	}
	
	else if(p == tail) //if deleting last node
	{
		tail = q; //set last node to node before it; don't use p because it is used in printf below
		q->next = NULL; //set next pointer for the last node to null
	}
	
	else //deleting middle node
	{
		q->next = p->next; //previous pointer points to two nodes ahead, while next pointer points to two behind, effectively releasing middle node
	}
	printf("Seat %s, party of %d.\n", p->names, p->number);
	free(p);
	return;
}

void list()
{
	x *p;
	p = head;
	if(p == NULL) //list is empty
	{
		printf("No data available\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%s, %d\n", p->names, p->number);
		p = p->next;
	}
	return;
}

	
void retrieve()
int main(void)
{
	int userinput;
	while(1)
	{
		printf("Customers: Press 1 to enter party name and number.\nWaiters: Press 2 to enter size of table available.\nPress 3 to show list, name, and number.\nPress 4 to exit.\n");
		scanf("%d", &userinput);
			
			switch(userinput)
			{
				case 1:
					int numbertemp;
					char nametemp[20];
					printf("Please enter your name.\n");
					scanf("%s", nametemp);
					printf("Now enter number of guests\n");
					scanf("%d", &numbertemp);
					insert(nametemp, numbertemp);
					break;
				case 2:
					int numbertemp;
					printf("Please enter table size.\n");
					scanf("%d", &numbertemp);
					delete(numbertemp);
					break;
				case 3:
					list();
					break;
				default: 
					return 0;
			}
		
	}	
}
