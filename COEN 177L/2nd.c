/*
 * Andy Wei
 * COEN177 Lab 3
 * TA: David Obatake
 * Section: Wednesday 5:15 pm
 * Due Date: 18 November 2015
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Struct node for doubly linked list data structure
typedef struct node
{
	int ref; //reference bit flag
	int pv; //page value
	struct node* next;
	struct node* prev;
}node;
node *head, *tail, *p1, *p2, *p3;

//Function initializations
void insert();
void search();

//Flag and Counter initializations
int flag = 0; //buffer fullness flag
int pf = 0; //page fault counter
int pr = 0; //page request counter

//Main Function: 
//1. Receive 2 arguments from stdin: program name and cache size
//2. fgets function reads page requests onto buffer of chosen cache size
//3. isdigit function makes sure to only add numbers to buffer
//4. sscanf function scans each page value to buffer
//5. Use doubly linked list to implement Second Chance algorithm 
int main(int argc, char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "error: Incorrect number of arguments\n");
		return -1;
	}
	int i = 0;
	long size = atoi(argv[1]);
	printf("%d\n", size);
	char buffer[size];
	char cur[size];
	int pv; //page value
	while(fgets(buffer, size, stdin)!= NULL)
	{
		if(!isdigit(buffer[0]))
			continue;
		else
		{
			sscanf(buffer, "%d", &pv);
			search(pv, size);
		}	
					
	}
	return 0;
};

//Insert Function: 
//1. Receive page value as int data (first parameter), buffer size as int bs (second parameter)
//2. Allocate memory for new page, set reference bit and page value.
//3. If buffer is not full, 
//	a. if empty buffer, then set p as head and tail
//	b. else add new page to end of buffer
//4. If buffer full, while iterator "i" is not NULL
//	a. set reference bit to 0 if it is 1, continue 
//	b. if reference bit was 0, then replace head with new page

void insert(int data, int bs)
{
	printf("page fault: %d\n", data);
	node *p = (struct node*)malloc(sizeof(struct node));
	p->pv = data;
	p->ref = 1;
	if(flag < bs) 	//buffer not full
	{
		
		if(head == NULL && tail == NULL) //empty buffer
		{
			head = tail = p;
			return;
		}
		else if(flag < bs)	//nonempty buffer
		{
			tail->next = p;
			p->prev = tail;
			p->next = NULL;
			tail = p;
			return;
		}
	}
	node *i = head;		//iterator node
	while(i != NULL)
	{
		if(i->ref == 1)		
		{
			i->ref = 0;
			continue;
		}
		else if(i->ref == 0) 
		{
			if(i != head || i != tail) 	//not head and tail case
			{
				i->prev->next = p;
				i->next->prev = p;
				p->next = i->next;
				p->prev = i->prev;
				break;
			}
			else if(i == head || i == tail) //head and tail case
			{
				i->next->prev = p;
				p->prev = i;
				head = p;
				break;
			}
		}
		i = i->next;
	}	
			
	return;
}	

//Search Function:
//1. Receive page value as int data (first parameter), buffer size as int bs (second parameter)
//2. Check if buffer is empty, if so then call insert function
//3. Else, reset pointer to p1 node as head
//4. Loop through buffer while p1 is not NULL
//5a. If page value was found in buffer and reference bit was 0, reset it to 1. Else, break
//5b. If not found, then call insert
void search(int data, int bs)
{
	if(head == NULL)	
	{
		insert(data, bs);
	}
	p3 = head;	
	while(p3 != NULL)
	{
		if(p3->pv == data)			//found pv in buffer
		{
			if(p3->ref == 0)		//ref bit = 0
			{
				p3->ref = 1;
				break;
			}
			else if(p3->ref == 1)
			{
				break;
			}
		}	
		else if(p3->pv != data && p3 == tail)	//did not find pv
		{
			insert(data, bs);
		}
		else if(flag == bs)
			break;	
		p3 = p3->next;
	}
	
}



