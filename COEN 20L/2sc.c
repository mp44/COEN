#include <stdio.h>
#include <string.h>

/*
 * Asc2Bin Function: Receives and stores user input of a binary char string n a binary integer array
 */
void Asc2Bin(char *string, int binary[8])
{
	int i;
	//loop to store string values into binary array
	for(i = 7; i >= 0; i--)
	{
		if(string[i] == '1')
			binary[i] = 1;
		else binary[i] = 0;
	}
	printf("Unsigned Binary: ");
	return;
}

/*
 * TwosComp Function: Receives unsigned binary array and converts into 2's complement representation.
 */
void TwosComp(int binary[8])
{
	int i, j;
	printf("2's complement: ");
	if(binary[0] == 0)
		return;
	//loop to search for least significant bit with 1
	for(i = 7; i > -1; i--)
	{
		if(binary[i] == 1)
		{
			break;
			if(binary[1] == 0)   //special case when 10000000
				binary[7] = 1;
		}
	}
	//loop to complement each bit after the least significant bit with 1
	for(j = 0; j < i; j++)
	{
		if(binary[j] == 1) 
			binary[j] = 0;
		else binary[j] = 1;
	}
	return;
}

/*0
 * PrintBin Function: Prints binary array.
 */
void PrintBin(int binary[8])
{
	int i;
	//loop to output binary array
	for(i = 0; i < 8; i++)
	{
		printf("%d", binary[i]);
	}
	printf("\n");
	return;
}

/*
 * Main Functino: Receive binary string by user and store into string array "str". Then output unsigned binary and 2's complement representation.
 */
int main()
{
	while(1)
	{
		int i;
		char str[100];
		int bin[8];
		//clear bin and str of garbage values
		for(i = 0; i < 8; i++)
			bin[i] = 0;
		for(i = 0; i < 100; i++)
			str[i] = '0';
		printf("Enter a binary string: \n");
		scanf("%s", &str);
		Asc2Bin(str, bin);
		PrintBin(bin);
		TwosComp(bin);
		PrintBin(bin);
	}
	return;
}
