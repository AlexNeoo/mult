#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Multiplies str1 and str2, and prints result.
int multiply(char *num1, char *num2)
{
	//input args could be up to 131K symbols on Linux OS so using int type
	//to store string length - considering it has 4 bytes on most 32/64  bit systems
	int sln1 = strlen(num1);
	int sln2 = strlen(num2);
	int len = sln1 + sln2;

	if (sln1 == 0 || sln2 == 0)
	{
		printf("\n----Input data is Empty !!! ----"
			"\nPlease provide 2 integers as arguments\n");

		return 1;
	}
	// will save the result in array
	// in reverse order
	int *result = (int *) malloc(sizeof(int) *len);

	if (result == NULL)
	{
		printf("\n----Not Enough Memory !!!----\n");
		return 2;
	}
	// Two indexes to store positions
	// in result.
	int index_n1 = 0;
	int index_n2 = 0;

	// Go from right to left in num1
	for (register int i = sln1 - 1; i >= 0; i--)
	{
		int carry = 0;
		// Take current digit of first number
		int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication
		index_n2 = 0;

		// Go from right to left in num2
		for (register int j = sln2 - 1; j >= 0; j--)
		{
			// Take current digit of second number
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position.
			int sum = n1 *n2 + result[index_n1 + index_n2] + carry;

			// Carry for next iteration
			carry = sum / 10;

			// Store result
			result[index_n1 + index_n2] = sum % 10;

			index_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[index_n1 + index_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		index_n1++;
	}

	// ignore '0's from the right
	register int i = len - 1;

	while (i >= 0 && result[i] == 0)
		i--;

	// print result
	printf("\n---Multiplication result is:\n");
	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
		printf("0");
	else
	{
		while (i >= 0)
		{
			printf("%d", result[i]);
			i--;
		}
	}

	printf("\n-------End of result---------\n");

	//Free memory and exit
	free(result);
	return 0;
}

