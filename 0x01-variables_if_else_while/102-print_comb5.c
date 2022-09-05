#include <stdio.h>

/**
* main - Print all possible combinations of two two-digit numbers
*
* Return: 0 void function
*/

int main(void)
{
	int unit1, ten1, unit2, ten2, i, j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		unit1 = i % 10;
		ten1 = i / 10;
		while (j <= 99)
		{
			unit2 = j % 10;
			ten2 = j / 10;

			putchar(ten1 + '0');
			putchar(unit1 + '0');
			putchar(' ');
			putchar(ten2 + '0');
			putchar(unit2 + '0');

			if (i != 98)
			{
				putchar(',');
				putchar(' ');
			}
			j++;
		}
		i++;
	}
	putchar('\n');
	return (0);
}
