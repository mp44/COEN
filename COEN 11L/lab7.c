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

void insert(char nametemp[], int numbertemp)
{
	x *p;
	x *q;
	x *temp;
	p = head;

	
	
	temp = (x *)malloc(sizeof(x));//create node under pointer temp	
	if(temp == NULL) //if temp points to null, then no memory is available. 
	{
		printf("No memory available.\n");
		return;
	}
	

	
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
	
	temp->number = numbertemp;
	return;
}	

	
void delete(numbertemp) 
{
	x *p;
	x *q;
	p = q = head;
	
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

void save(char *lab7text)
{
	FILE *fp;
	x *p;
	fp = fopen(lab7text, "w");
	if(fp == NULL)
		return;
	p = head;
	fprintf(fp, "Names and Seats Reserved.\n--------------------------------------\n");
	while(p != NULL)
	{
		fprintf(fp, "%s %d\n", p->names, p->number);
		p = p->next;
	}
	printf("Reservation saved into text file.\n");
	fclose(fp);
	return;
}
void read(char *lab7text)
{
	FILE *fp;
	char nametemp[20];
	int numbertemp;
	int skip;
	skip = strlen("Names and Seats Reserved.\n--------------------------------------\n");
	fp = fopen(lab7text, "r");
	if(fp == NULL)
	{
		printf("No data in text file.\n");
		return;
	}
	fseek(fp, skip, SEEK_SET);
	while(fscanf(fp, "%s %d", nametemp, &numbertemp)>0) //while reading info from text file
	{
		insert(nametemp, numbertemp);
	}
			
	fclose(fp);	
	return;
}
int main(int argc, char* argv[])
{
	int userinput;
	if(argc == 1)
	{
		printf("The name of the file is missing.\n");
		return 1;
	}
	else
		read(argv[1]);
	
	while(1)
	{
		printf("Customers: Press 1 to enter party name and number.\nWaiters: Press 2 to enter size of table available.\nPress 3 to show list, name, and number.\nPress 4 to to save reservation into text file and quit.\n");
		scanf("%d", &userinput);
				
			switch(userinput)
			{
				case 1:
				{
					int numbertemp;
					char nametemp[20];
					printf("Please enter your name.\n");
					scanf("%s", nametemp);
					printf("Now enter number of guests.\n");
					scanf("%d", &numbertemp);
					
					insert(nametemp, numbertemp);
				}
					break;
				case 2:
				{
					int numbertemp;
					printf("Please enter table size.\n");
					scanf("%d", &numbertemp);
					delete(numbertemp);
				}
					break;
				case 3:
					list();
					break;
				default:
					save(argv[1]);
					return 0;
			}
		
	}	
}
