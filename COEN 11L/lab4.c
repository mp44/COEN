Andy Wei
Figueira
Friday
31 January 2014

#include <stdio.h>
#include <string.h>
#define SIZE 10
typedef union stat
{
	char school[20];
	float salary;
	int retire;
}u;

typedef struct info
{
	char names[20];
	int age;
	u stat;
}x;

struct info array[SIZE];
int counter=0;

void input()
{
	int i;
	char name[20];
	int agetemp;
	x *p = array;
	
	if(counter>9)
	{
		printf("Sorry, database is full.\n");
		return;
	}

	printf("Please enter your name.\n");
	scanf("%s",name);
	
	printf("Please enter your age.\n");
	scanf("%d",&agetemp);
	
	p = &array[counter];
	strcpy(p->names, name);
	p->age = agetemp;
	if(agetemp<= 21)
	{
		printf("Please enter name of your school.\n");
		scanf("%s", p->stat.school);
	}
	else if(agetemp > 21 && agetemp < 65)
	{
		printf("Please enter salary.\n");
		scanf("%f", &p->stat.salary);
	}
	else if(agetemp >= 65)
	{
		printf("Please enter year of retirement\n");
		scanf("%d", &p->stat.retire);
	}
	printf("Input saved.\n");
	counter++;
	return;
} 		

void delete()
{
	int i;
	x *p = array;
	char nametemp[20];
	
	if(counter == 0)
	{
		printf("No data.\n");
		return;
	}
	
	printf("Enter name you wish to delete.\n");
	scanf("%s", nametemp);
	for(i=0; i<counter; i++, p++)		
	{
		if(strcmp(nametemp, p->names)==0)
		{
			array[i] = array[counter-1];
			counter--;
			return;	
		}
	}
	printf("%s's data deleted.\n", nametemp);
}

void list()
{
	x *p = array;
	int i;
	if(counter==0)
	{
		printf("No data saved.\n");
		return;
	}
	
	for(i=0; i<counter; i++, p++)
	{
		printf("%s, %d, ", p->names, p->age);
		{		
			if(p->age <= 21)
			{
				printf("%s\n", p->stat.school);
			}
			else if(p->age > 21 && p->age < 65)
			{
				printf("%f\n", p->stat.salary);
			}	
			else if(p->age >= 65)
			{
				printf("%d\n", p->stat.retire);
			}
		}	
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
		printf("Press 1 to input a person.\nPress 2 to delete a person.\nPress 3 list info.\nPress 4 to exit.\n");
		scanf("%d", &userinput);
			
			switch(userinput)
			{
				case 1:
					input();
					break;
				case 2:
					delete();
					break;
				case 3:
					list();
					break;
				default: 
					return 0;
			}
		
	}	
}
