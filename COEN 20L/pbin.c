/*
 * Andy Wei
 * COEN 20L Tuesday 2:15 Section
 * Lab 5
 * 28 April 2015
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    
    return;
}

/*
 AddBinary Function:
 */
int AddBinary(int first[8], int second[8], int result[8])
{
    int i;
    int carry = 0;
    for(i = 7; i >= 0; i--)
    {
        if(first[i] == 1 && second[i] == 1)
        {
            if(flag == 1)
            {
                result[i] = 1;
                flag = 1;
            }
        }
        else
        {
            result[i] = 0;
            flag = 1;
        }
        
        if(first[i] == 0 && second[i] == 0)
        {
            if(flag == 1)
                result[i] = 1;
            else
                result[i] = 0;
        }
        
        if(first[i] != second[i])
        {
            if(flag == 1)
            {
                result[i] = 0;
                flag = 1;
            }
            else
                result[i] = 1;
        }
    }
    return flag;
}

/*
 SubBinary Function:
 */
int SubBinary(int first[8], int second[8], int result[8])
{
    int i;
    int flag = 0;
    for(i = 7; i >= 0; i--)
    {
        if(first[i] == 1 && second[i] == 1)
        {
            if(flag == 1)
            {
                result[i] = 1;
            }
            else
                result[i] = flag = 0;
        }
        if(first[i] == 0 && second[i] == 0)
        {
            if(flag == 1)
            {
                result[i] = flag = 1;
            }
            else
                result[i] = flag = 0;
        }
        if(first[i] == 1 && second[i] == 0)
        {
            if(flag == 1)
                result[i] = flag = 0;
            else
            {
                result[i] = 1;
                flag = 0;
            }
        }
        if(first[i] == 0 && second[i] == 1)
        {
            if(flag == 1)
            {
                result[i] = 0;
                flag = 1;
            }
            else
                result[i] = flag = 1;
        }
    }
    return flag;
}

/*
 PrintBin Function: prints binary array as converted by Dec2Bin function.
*/
 void PrintBin(int binary[8])
{
	int i;
	printf("The 8 binary bits are: ");
	for(i = 0; i < 8; i++)
	{
		printf("%d", binary[i]);
	}
	printf("\n");
	return;
}

/*
 * Main Function: Receive binary string by user and store into string array "str". Then output unsigned binary and 2's complement representation.
 */
int main()
{
    while(1)
    {
        int i;
        char str[100];
        int x[8]; //operand 1
        int y[8]; //operand 2
        int z[8]; //sum/difference
        //clear bin and str of garbage values
        for(i = 0; i < 8; i++)
        {
            x[i] = 0;
            y[i] = 0;
            z[i] = 0;
        }
        for(i = 0; i < 100; i++)
            str[i] = '0';
        printf("Enter first binary string: \n");
        scanf("%s", &str);
        Asc2Bin(str, x);
        PrintBin(x);
        printf("Enter second binary string: \n");
        scanf("%s", &str);
        Asc2Bin(str, y);
        PrintBin(y);
        printf("The 1st plus the 2nd is: \n");
        AddBinary(x, y, z);
        printf("The carry out is: %d\n", flag);
        PrintBin(z);
        printf("The 1st minus the 2nd is: \n");
        SubBinary(x, y, z);
        printf("The borrow out is: %d\n", flag);
        PrintBin(z);
    }
    return;
}
