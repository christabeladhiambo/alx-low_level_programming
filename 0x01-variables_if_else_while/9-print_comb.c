#include <stdio.h>

/**
* main - Print all the digit in base 10 separate by , using putchar
* Return: 0 void function
*/

int main(void)
{
	int digit = 48;

	while (digit < 58)
	{
		putchar(digit);
		if (digit != 57)
		{
			putchar(',');
			putchar(' ');
		}
		digit++;
	}
	putchar('\n');

	return (0);
}
