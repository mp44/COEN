#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
	int number;
	char names[20];
	struct node *next;
}x;
typedef struct entry
{
	x *head;
	x *tail;
}e;
e array[4];

void insert(char nametemp[], int numbertemp)
{
	int i, j;
	x *p;
	x *q;
	x *temp;
 	p = array[i].head; //p points to head of each linked list	
	temp = (x *)malloc(sizeof(x));//create node under pointer temp	
	if(temp == NULL) //if temp points to null, then no memory is available. 
	{
		printf("No memory available.\n");
		return;
	}
	
	for(i = 0; i < 4; i++) //checking for duplicates
	{ 	p = array[i].head;
		while(p!=NULL)
		{
			if(strcmp(p->names,nametemp) == 0)
				{
					printf("Sorry, name is taken. Please enter another.\n");
					return;
				}
			p = p->next;
		}
	}
	strcpy(temp->names, nametemp); //copy name into node temp
	if(numbertemp <= 2)//tells which head to insert node temp into 
	{
		j = 0;
		if(array[j].head == NULL) //if list is empty, point both head and tail to temp and tail->next to null
		{
			array[j].head = temp;
			array[j].tail = temp;
			temp->next = NULL;
		}
		
		else //if list has nodes, add to last node in list
		{
			temp->next = NULL; 
			array[j].tail->next = temp;
			array[j].tail = temp;
		}
	}
	else if(numbertemp > 2 && numbertemp <= 4)
	{
		j = 1;
		if(array[j].head == NULL) //if list is empty, point both head and tail to temp and tail->next to null
		{
			array[j].head = temp;
			array[j].tail = temp;
			temp->next = NULL;
		}
		
		else //if list has nodes, add to last node in list
		{
			temp->next = NULL; 
			array[j].tail->next = temp;
			array[j].tail = temp;
		}
	}
	else if(numbertemp > 4 && numbertemp <= 6)
	{
		j = 2;
		if(array[j].head == NULL) //if list is empty, point both head and tail to temp and tail->next to null
		{
			array[j].head = temp;
			array[j].tail = temp;
			temp->next = NULL;
		}
		
		else //if list has nodes, add to last node in list
		{
			temp->next = NULL; 
			array[j].tail->next = temp;
			array[j].tail = temp;
		}
	}
	else if(numbertemp >= 7)
	{
		j = 3;
		if(array[j].head == NULL) //if list is empty, point both head and tail to temp and tail->next to null
		{
			array[j].head = temp;
			array[j].tail = temp;
			temp->next = NULL;
		}
	
		else //if list has nodes, add to last node in list
		{
			temp->next = NULL; 
			array[j].tail->next = temp;
			array[j].tail = temp;
		}
	}
	temp->number = numbertemp;
	return;
}	

	

	
void delete(numbertemp) 
{
	x *p;
	x *q;
	int i;
	if(array[0].head == NULL &&	array[1].head == NULL && array[2].head == NULL && array[3].head == NULL) //if each head is empty, no data available
	{
		printf("List is empty.\n");
		return;
	}
	for(i = 0; i < 4; i++)	
	{
		q = p = array[i].head;	
		while(p!=NULL)
		{
			if(numbertemp >= p->number) //break if amount of seats are >= than those requested in insert
			{
				break;
			}
			else
			{
				printf("No seats available.\n");
				return;
			}
			q = p;
			p = p->next;
		}
		if(p != NULL &&  numbertemp >= p->number)
		{
			break;
		}
	}
	if(numbertemp <= 2)
	{
		i = 0;
		q = p = array[i].head;
		
		if(array[i].head == array[i].tail) //if only one node in list, point head and tail to null
		{
			array[i].head = array[i].tail = NULL;
		}
		else if(p == array[i].head) //if deleting first node
		{
			array[i].head = array[i].head->next; //releases first node, points head to second node
		}
	
		else if(p == array[i].tail) //if deleting last node
		{
			array[i].tail = q; //set last node to node before it; don't use p because it is used in printf below
			q->next = NULL; //set next pointer for the last node to null
		}	
	
		else //deleting middle node
		{
		q->next = p->next; //previous pointer points to two nodes ahead, while next pointer points to two behind, effectively releasing middle node
		}
	}
	else if(numbertemp <=4)
	{
		i = 1;
		q =	p = array[i].head;
		if(array[i].head == array[i].tail) //if only one node in list, point head and tail to null
		{
			array[i].head = array[i].tail = NULL;
		}
		else if(p == array[i].head) //if deleting first node
		{
			array[i].head = array[i].head->next; //releases first node, points head to second node
		}
	
		else if(p == array[i].tail) //if deleting last node
		{
			array[i].tail = q; //set last node to node before it; don't use p because it is used in printf below
			q->next = NULL; //set next pointer for the last node to null
		}	
	
		else //deleting middle node
		{
		q->next = p->next; //previous pointer points to two nodes ahead, while next pointer points to two behind, effectively releasing middle node
		}
	}
	else if(numbertemp <=6)
	{
		i = 2;
		q = p = array[i].head;
		if(array[i].head == array[i].tail) //if only one node in list, point head and tail to null
		{
			array[i].head = array[i].tail = NULL;
		}
		else if(p == array[i].head) //if deleting first node
		{
			array[i].head = array[i].head->next; //releases first node, points head to second node
		}
	
		else if(p == array[i].tail) //if deleting last node
		{
			array[i].tail = q; //set last node to node before it; don't use p because it is used in printf below
			q->next = NULL; //set next pointer for the last node to null
		}	
	
		else //deleting middle node
		{
		q->next = p->next; //previous pointer points to two nodes ahead, while next pointer points to two behind, effectively releasing middle node
		}
	}
	else if(numbertemp >= 7)
	{
		i = 3;
		q =	p = array[i].head;
		if(array[i].head == array[i].tail) //if only one node in list, point head and tail to null
		{
			array[i].head = array[i].tail = NULL;
		}
		else if(p == array[i].head) //if deleting first node
		{
			array[i].head = array[i].head->next; //releases first node, points head to second node
		}
	
		else if(p == array[i].tail) //if deleting last node
		{
			array[i].tail = q; //set last node to node before it; don't use p because it is used in printf below
			q->next = NULL; //set next pointer for the last node to null
		}	
	
		else //deleting middle node
		{
		q->next = p->next; //previous pointer points to two nodes ahead, while next pointer points to two behind, effectively releasing middle node
		}
	}
	printf("Seat %s, party of %d.\n", p->names, p->number);
	free(p);
	return;
}

void list()
{
	x *p;
	int i;
	if(array[0].head == NULL &&	array[1].head == NULL && array[2].head == NULL && array[3].head == NULL) //if each head is empty, no data available
	{
		printf("No data available.\n");
		return;
	}
	for(i = 0; i < 4; i++)//increment each head and print 
	{
		p = array[i].head;
		while(p!=NULL)
		{
			printf("%s, %d\n", p->names, p->number);
			p = p->next;
		}
	}
	return;
}

void change(char nametemp[], int numbertemp)
{
	//traverse to find name use strcmp
	//change number in node to numbertemp	
	//move node to correct list if necessary
	int i,j;
	x *p;
	x *q;
	q = p = array[i].head;
	if(array[0].head == NULL &&	array[1].head == NULL && array[2].head == NULL && array[3].head == NULL) //if each head is empty, no data available
	{
		printf("No data available.\n");
		return;
	}
	for(i=0; i<4; i++)
	{	
		p = array[i].head;
		while(p!=NULL)
		{
			if(strcmp(nametemp, p->names) == 0)
				break;
			q = p;
			p = p->next;
		}
		if(p != NULL && strcmp(nametemp, p->names) == 0)
		{
			break;
		}
	}
	
	p->number = numbertemp;
	printf("New number is %d\n", p->number);
	if(numbertemp <= 2)
	{
		j = 0;
		if(array[i].head == array[i].tail) //only one node in original list
		{
			if(array[j].head == NULL) //if new node is empty
			{
				array[i].head = array[i].tail = NULL; //delete node from original list
				array[j].head = array[j].tail = p; //point head and tail of new list to p 
				p->next = NULL;
			}
			else if(i == j) //if staying in same node
			{
				printf("Your reservation has been changed.\n");
				return;
			}
			else //new node is not empty
			{
				array[i].head = array[i].tail = NULL; //delete node from original list
				array[j].tail->next = p; //add p after tail in new list
				array[j].tail = p;
				p->next = NULL;
			}
		}
		else //more than one node in original list
		{
			if(array[j].head == NULL) //new node is empty
			{
				q->next = p->next;
				array[j].head = array[j].tail = p;
				p->next = NULL;
			}
			else if(i == j) //staying in same node
			{
				printf("Your reservation has been changed.\n");
				return;
			}
			else //more than one node in new list
			{
				q->next = p->next;
				array[j].tail->next = p;//adding p after tail in new list
				array[j].tail = p;
				p->next = NULL;
			}
		}
	}
	if(numbertemp > 2 && numbertemp <= 4)
	{
		j = 1;
		if(array[i].head == array[i].tail) //only one node in original list
		{
			if(array[j].head == NULL) //if new node is empty
			{
				array[i].head = array[i].tail = NULL; //delete node from original list
				array[j].head = array[j].tail = p; //point head and tail of new list to p 
				p->next = NULL;
			}
			else if(i == j) //if staying in same node
			{
				printf("Your reservation has been changed.\n");
				return;
			}
			else //new node is not empty
			{
				array[i].head = array[i].tail = NULL; //delete node from original list
				array[j].tail->next = p; //add p after tail in new list
				array[j].tail = p;
				p->next = NULL;
			}
		}
		else //more than one node in original list
		{
			if(array[j].head == NULL) //new node is empty
			{
				q->next = p->next;
				array[j].head = array[j].tail = p;
				p->next = NULL;
			}
			else if(i == j) //staying in same node
			{
				printf("Your reservation has been changed.\n");
				return;
			}
			else //more than one node in new list
			{
				q->next = p->next;
				array[j].tail->next = p;//adding p after tail in new list
				array[j].tail = p;
				p->next = NULL;
			}
		}
	}
	if(numbertemp > 4 && numbertemp <= 6)
	{
		j = 2;
		if(array[i].head == array[i].tail) //only one node in original list
		{
			if(array[j].head == NULL) //if new node is empty
			{
				array[i].head = array[i].tail = NULL; //delete node from original list
				array[j].head = array[j].tail = p; //point head and tail of new list to p 
				p->next = NULL;
			}
			else if(i == j) //if staying in same node
			{
				printf("Your reservation has been changed.\n");
				return;
			}
			else //new node is not empty
			{
				array[i].head = array[i].tail = NULL; //delete node from original list
				array[j].tail->next = p; //add p after tail in new list
				array[j].tail = p;
				p->next = NULL;
			}
		}
		else //more than one node in original list
		{
			if(array[j].head == NULL) //new node is empty
			{
				q->next = p->next;
				array[j].head = array[j].tail = p;
				p->next = NULL;
			}
			else if(i == j) //staying in same node
			{
				printf("Your reservation has been changed.\n");
				return;
			}
			else //more than one node in new list
			{
				q->next = p->next;
				array[j].tail->next = p;//adding p after tail in new list
				array[j].tail = p;
				p->next = NULL;
			}
		}
	}
	if(numbertemp >= 7)
	{
		j = 3;
		if(array[i].head == array[i].tail) //only one node in original list
		{
			if(array[j].head == NULL) //if new node is empty
			{
				array[i].head = array[i].tail = NULL; //delete node from original list
				array[j].head = array[j].tail = p; //point head and tail of new list to p 
				p->next = NULL;
			}
			else if(i == j) //if staying in same node
			{
				printf("Your reservation has been changed.\n");
				return;
			}
			else //new node is not empty
			{
				array[i].head = array[i].tail = NULL; //delete node from original list
				array[j].tail->next = p; //add p after tail in new list
				array[j].tail = p;
				p->next = NULL;
			}
		}
		else //more than one node in original list
		{
			if(array[j].head == NULL) //new node is empty
			{
				q->next = p->next;
				array[j].head = array[j].tail = p;
				p->next = NULL;
			}
			else if(i == j) //staying in same node
			{
				printf("Your reservation has been changed.\n");
				return;
			}
			else //more than one node in new list
			{
				q->next = p->next;
				array[j].tail->next = p;//adding p after tail in new list
				array[j].tail = p;
				p->next = NULL;
			}
		}
	}
	return;
}

void quit(x *p, x *q)
{
	int i;
	
	if(array[0].head == NULL &&	array[1].head == NULL && array[2].head == NULL && array[3].head == NULL) //if each head is empty, no data available
	{
		printf("List is empty.\n");
		return;
	}
	for(i = 0; i < 4; i++)
	{
		p = q = array[i].head;
		if(array[i].head == NULL)
			continue;
		else if(array[i].head == array[i].tail)
		{
			array[i].head = NULL;
			array[i].tail = NULL;
			free(p);
			continue;	
		}
		while(p != NULL)
		{			
			q = p;
			p = p->next;
			free(q);
		}
		array[i].head = NULL;
	}
	printf("List deleted.\n");
	return;
}
int main(void)
{
	int userinput;
	while(1)
	{
		printf("Customers: Press 1 to enter party name and number.\nWaiters: Press 2 to enter size of table available.\nPress 3 to show list, name, and number.\nPress 4 to change your reservation.\nPress 5 to exit.\n");
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
						scanf("%d",&numbertemp);
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
				case 4:
					{
						char nametemp[20];
						int numbertemp;
						printf("Please enter your party name.\n");
						scanf("%s", nametemp);
						printf("Now enter your new party number.\n");
						scanf("%d", &numbertemp);
						change(nametemp, numbertemp);
					}
					break;
				case 5:
					{	
						x *p;
						x *q;
						quit(p, q);
						return 0;	
					} 
			}
		
	}	
}
