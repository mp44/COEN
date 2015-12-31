#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct node
{
	int number;
	char names[20];
	struct node *next;
}x;

x *head = (x*)NULL;
x *tail = (x*)NULL;

pthread_mutex_t mutex;


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
		
		else if(p == tail)
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
	fp = fopen(lab7text, "w");//open text file
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
		pthread_mutex_lock (&mutex);
		insert(nametemp, numbertemp);
		pthread_mutex_unlock (&mutex);

	}
			
	fclose(fp);	
	return;
}
void freenodes()
{
	x *p, *q;
	p = head;
	if(p == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	while(p!=NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	printf("Nodes freed\n");
	return;
}
	
void *autosave(void *arg)
{
	FILE *fp;
	x *p;
	while(1)
	{	
		pthread_mutex_lock (&mutex); //lock
		p = head;
		fp = fopen((char *)arg, "wb"); //open binary file with action write
		
		if(fp == NULL)
		{
			printf("File could not be opened\n");
			return NULL;
		}
		
		while(p!=NULL)
		{	
			fwrite(p, sizeof(x), 1, fp); //save to binary file from node p
			p = p->next;
		}
		fclose(fp);	
		pthread_mutex_unlock (&mutex); //unlock
		sleep(5); //sleep for 5 seconds
		printf("Autosaved.\n");
	}
}
void *readsave(void *arg)
{
	x *q;
	q = (x *)malloc(sizeof(x));	
	FILE *fp;
	fp = fopen((char *)arg, "rb"); //open binary file with action read
	
	if(fp == NULL)
	{
		printf("File could not be opened.\n");
		fclose(fp);
		return;
	}
		
	if(q == NULL) //if temp points to null, then no memory is available. 
	{
		printf("No memory available.\n");
		return;
	}

	while(fread(q, sizeof(x), 1, fp)==1) //while reading from binary file
	{
		printf("%s, %d\n", q->names, q->number); //print what is saved from binary file
	}
	free(q);
	fclose(fp);	//close file
}	
int main(int argc, char* argv[])
{
	pthread_t thread;
	pthread_mutex_init (&mutex, NULL);
	pthread_create(&thread, NULL, autosave, (void*)argv[2]);

	int userinput;
	if(argc == 1)
	{
		printf("The name of the file is missing.\n");
		return 1;
	}
	read(argv[1]);
	
	while(1)
	{
		printf("Customers: Press 1 to enter party name and number.\nWaiters: Press 2 to enter size of table available.\nPress 3 to show list, name, and number.\nPress 4 to read binary file.\nPress 5 to save reservation and quit.\n");
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
					pthread_mutex_lock (&mutex);
					insert(nametemp, numbertemp);
					pthread_mutex_unlock (&mutex);
				}
					break;
				case 2:
				{
					int numbertemp;
					printf("Please enter table size.\n");
					scanf("%d", &numbertemp);
					pthread_mutex_lock (&mutex);
					delete(numbertemp);
					pthread_mutex_unlock (&mutex);
				}
					break;
				case 3:
					list();
					break;
				case 4:
					pthread_mutex_lock (&mutex);
					readsave(argv[2]);
					pthread_mutex_unlock (&mutex);
					break;
				default:
					pthread_mutex_lock (&mutex);
					pthread_cancel (thread);
					pthread_mutex_unlock (&mutex);
					pthread_mutex_destroy (&mutex);
					save(argv[1]);
					freenodes();
					return 0;
			}
		
	}	
}
