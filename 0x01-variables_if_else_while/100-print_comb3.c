#include <stdio.h>

/**
* main - Print list of number, sorted by a certain sort, without using printf
* Return: 0 void function
*/
int main(void)
{
	int i, j;

	i = 0;
	while (i < 10)
	{
		j = i + 1;
		while (j < 10)
		{
			putchar(i + 48);
			putchar(j + 48);
			if (i != 8)
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
