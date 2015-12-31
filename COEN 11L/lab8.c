#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int reverse(char *, int);

int main(int argc, char *argv[])
{
	FILE *fp1;
	FILE *fp2;
	char str[SIZE];
	char *p = str;
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "w");
	if(fp1 == NULL || fp2 == NULL)
		return 0;
	while(fgets(str, SIZE, fp1)!=NULL)
	{
		
		reverse(str, 0);
		fprintf(fp2, "%s", str);
	}
	fclose(fp1);
	fclose(fp2);
	printf("Strings have been reversed.\n");
	return 0;


}

int reverse(char *str, int counter)
{
	int i;
	char strtemp; 
	strtemp = str[counter];
	if(str[counter]=='\0'|| str[counter]=='\n') //if end of string
		return 0;
	
	i = reverse(str, counter + 1); //first iteration of i is 5, so str[i] for example of "hello" is o
	str[i] = strtemp; //following example above, "o" will be first character of strtemp array
	return i+1;
}	





