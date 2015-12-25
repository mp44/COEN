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
 AddBinary Function: Receive two binary arrays and add the first operand to the second. Then compute the carry out using a flag.
 */
int AddBinary(int first[8], int second[8], int result[8])
{
    int i;
    int flag = 0;
    //loop from least significant bit to most significant bit
    for(i = 7; i >= 0; i--)
    {
    	//case where both operands are 1
        if(first[i] == 1 && second[i] == 1)
        {
            if(flag == 1)
            {
                result[i] = 1;
                flag = 1;
            }
       	    else
	    {
            result[i] = 0;
            flag = 1;
	    }
	}
        //case where both operands are 0
        if(first[i] == 0 && second[i] == 0)
        {
            if(flag == 1)
                result[i] = 1;
            else
                result[i] = 0;
	    flag = 0;
        }
        //case where operands are either 0 or 1
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
 SubBinary Function: Receive two binary arrays and subtract the second from the first. Then compute the borrow out using a flag.
 */
int SubBinary(int first[8], int second[8], int result[8])
{
    int i;
    int flag = 0;
    //loop from least significant bit to most significant bit
    for(i = 7; i >= 0; i--)
    {
    	//case where both opereands are 1
        if(first[i] == 1 && second[i] == 1)
        {
            if(flag == 1)
            {
                result[i] = 1;
            }
            else
                result[i] = flag = 0;
        }
	//case where both operands are 1
        if(first[i] == 0 && second[i] == 0)
        {
            if(flag == 1)
            {
                result[i] = flag = 1;
            }
            else
                result[i] = flag = 0;
        }
	//case where first operand is 1 and second operand is 0
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
	//case where first operand is 0 and second operand is 1
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
 PrintBin Function: Receives and prints binary array.
*/
 void PrintBin(int binary[8])
{
	int i;
	for(i = 0; i < 8; i++)
	{
		printf("%d", binary[i]);
	}
	printf("\n");
	return;
}

/*
 Main Function: Receives two 8 bit binary numbers and adds and subtracts them and computes their carry/borrow outs via the AddBinary and SubBinary functions. Then outputs the sum and difference as well as the carry and borrow outs.
 */
int main()
{
    while(1)
    {
        int i;
	int flag = 0;
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
        printf("Enter second binary string: \n");
        scanf("%s", &str);
        Asc2Bin(str, y);
        printf("The 1st plus the 2nd is: ");
        AddBinary(x, y, z);
        PrintBin(z);
	printf("The carry out is: %d\n", AddBinary(x, y, z));
        printf("The 1st minus the 2nd is: ");
        SubBinary(x, y, z);
        PrintBin(z);
	printf("The borrow out is: %d\n", SubBinary(x, y, z));

    }
    return 0;
}
