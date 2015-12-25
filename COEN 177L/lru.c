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
struct node
{
	int pv; //page value
	struct node* next;
	struct node* prev;
} *head, *tail, *p, *p1;

//Function initializations
void new();
void insert();
void flush();
void search();

//Flag and Counter initializations
int flag = 0; //buffer fullness flag
int pf = 0; //page fault counter
int pr = 0; //page request counter

//Main Function: 
//1. Receive 2 arguments from stdin: program name and cache size
//2. fgets function reads page requests onto buffer of chosen cache size
//3. Use doubly linked list to implement LRU algorithm (head is most recently used, tail is least recently used)
int main(int argc, char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "error: Incorrect number of arguments\n");
		return -1;
	}
	int i;
	long size = atoi(argv[1]);
	char buffer[size];
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
//2. Increment page fault counter because insert is only called if page fault occurs
//3. If buffer full, "flush" the tail(LRU) node to make room for new page.  
//4. Allocate memory for new page
//5. If buffer is empty, set head and tail as new page, and set its page value
//6. Else, set as head and set its page value
void insert(int data, int bs)
{
	pf++;
	printf("page fault: %d\n", data);
	if(flag < bs)	
		flag++;
	else
	{
		flush();
	}
	p = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)		//empty buffer
	{
		p->pv = data;
		head = tail = p;
	}
	else 					//nonempty buffer
	{
		p->pv = data;
		p->next = head;
		head->prev = p;
		head = p;
	}
}	

//Search Function:
//1. Receive page value as int data (first parameter), buffer size as int bs (second parameter)
//2. Check if buffer is empty, if so then call insert function
//3. Else, reset pointer to p1 node as head
//4. Loop through buffer while p1 is not NULL
//5a. If page value was found in buffer, then set it as the new head
//5b. Else, call insert
void search(int data, int bs)
{
	if(head == NULL)
		insert(data, bs);
	p1 = head;
	
	while(p1 != NULL)
	{
		if(p1->pv == data)			//found pv in buffer
		{
			if(p1 == head)          //head case: page with page value is already in most recent spot (head)
			{
				break;
			}
			else if(p1 == tail)		//tail case: move page with page value to head
			{
				p1->next = head;
				head->prev = p1;
				p1->prev->next = NULL;
				tail = p1->prev;
			}
			else 					//move page with page value to most recent spot (head)
			{
				p1->next->prev = p1->prev;
				p1->prev->next = p1->next;
				p1->next = head;
				head->prev = p1;
				head = p1;
				break;
			}
		}
		else if(p1->next == NULL)	//did not find pv
		{	
			insert(data, bs);
		}
		p1 = p1->next;
	}
}

//Flush Function:
//1. Check if buffer is empty
//2. If not, then delete tail
void flush()
{
	if(tail == NULL)
	{
		fprintf(stderr, "error: List is empty\n");
	}
	p1 = tail->prev;
	p1->next = NULL;
	tail = p1;
	flag--;
}

