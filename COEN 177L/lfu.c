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
	int freq;
	int age;
	int pv; //page value
	struct node* next;
	struct node* prev;
} *head, *tail, *p; 

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
	long size1 = atoi(argv[1]);
	long size = size1 -1;
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
//3. If buffer is not full, either set as head and tail (if empty) or add to end of list
//4. If buffer full, find the lowest frequency, then store each page value with lowest frequency in lowest array
//5. Search through lowest array for oldest page
//6. Search for ties in lowest array
//7. If no tie, then replace page with lowest frequency
//8. If tie, then pick oldest and replace page
void insert(int data, int bs)
{
	int lowest[bs];
	int x = 0;
	printf("page fault: %d\n", data);
	struct node *p = (struct node*)malloc(sizeof(struct node));
	p->pv = data;
	struct node *i = head;
	if(head == NULL)		//empty buffer
	{	
		flag++;
		head = tail = p;
		return;
	}
	if(flag < bs)		//if buffer isn't full, add new page to end of list
	{
		flag++;
		tail->next = p;
		p->prev = tail;
		tail = p;
		return;
	}
	//full buffer
	int min = head->freq;
	while(i != NULL) 	//find lowest freq
	{
		if(i->freq < min)
			min = i->freq;
		i = i->next;
	}
	
	for(x = 0; x < bs; x++)	//store page values of lowest frequencies in array
	{	
		i = head;
		while(i != NULL)
		{
			if(i->freq == min)	
			{	
				lowest[x] = i->pv;
			}
			i = i->next;
		}
	}
	
	int oldest = head->age;
	int oldestindex = 0;
	for(x = 0; x < bs; x++)	//search through lowest array to find oldest page
	{
		i = head;
		while(i != NULL)
		{
			if(i->pv == lowest[x])
			{	
				if(i->age > oldest)
				{
					oldest = i->age;
					oldestindex = x;
				}
			}
			i = i->next;
		}
	}
	
	int j = 0;
	i = head;
	while(i != NULL)
	{
		if(i->freq == min)
		j++;
		i = i->next;
	}
	i = head;
	struct node* q = head;
	for(x = 0; x < bs; x++)		//replace page with lowest freq and oldest age
	{
		i = head;
		while(i != NULL)
		{
				if(i->pv == lowest[x] && j == 1)
				{
					if(i->prev == NULL)
					{
						head->next->prev = p;
						p->next = head->next;
						head = p;
						break;
					}
					else if(i->next == NULL)
					{
						tail->prev->next = p;
						p->prev = tail->prev;
						tail = p;
							
						break;
					}
					else
					{
						i->prev->next = p;
						i->next->prev = p;
						p->next = i->next;
						p->prev = i->prev;
						break;
					}
				}
				else if(i->pv == lowest[x] && j > 1){
					while(q != NULL)
					{
						if(q->freq == i->freq)
						{
							if(q->age < i->age)
							{	
								if(i->prev == NULL)
								{
									head->next->prev = p;
									p->next = head->next;
									head = p;
									break;
								}
								else if(i->next == NULL)
								{
									tail->prev->next = p;
									p->prev = tail->prev;
									tail = p;	
									break;
								}
								else
								{
									i->prev->next = p;
									i->next->prev = p;
									p->next = i->next;
									p->prev = i->prev;
									break;		
								}
							}
							else
							{
								if(q->prev == NULL)
								{
									head->next->prev = p;
									p->next = head->next;
									head = p;
									break;
								}
								else if(q->next == NULL)
								{
									tail->prev->next = p;
									p->prev = tail->prev;
									tail = p;	
									break;
								}
								else if(q!=tail && q!=head)
								{
									q->prev->next = p;
									q->next->prev = p;
									p->next = q->next;
									p->prev = q->prev;
									break;		
								}
							}
						}
					q = q->next;
					}
					break;
				}
			i = i->next;
		}
	}
	return;
}
//Search Function:
//1. Receive page value as int data (first parameter), buffer size as int bs (second parameter)
//2. Check if buffer is empty, if so then call insert function
//3. Else, reset pointer to p1 node as head
//4. Increment age of every page in buffer
//5. Loop while p1 != NULL
//5a. If page has been found in buffer, then increment frequency
//5b. Else, call insert
void search(int data, int bs)
{
	if(head == NULL)
		insert(data, bs);
	
	struct node *i = head;
	while(i != NULL)	//increment age
	{
		i->age++;
		i = i->next;
	}
	struct node* p1 = head;
	
	while(p1 != NULL)
	{
		if(p1->pv == data)			//found pv in buffer
		{
			p1->freq++;
			break;
		}
		else if(p1->next == NULL)	//did not find pv
		{		
			insert(data, bs);
		}
		p1 = p1->next;
	}
	return;
}


