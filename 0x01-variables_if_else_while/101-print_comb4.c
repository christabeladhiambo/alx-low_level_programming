#include <stdio.h>

/**
* main - Print list of number, sorted by a certain sort, without using printf
* Return: 0 void function
*/
int main(void)
{
	int i, j, k;

	i = 0;
	while (i < 10)
	{
		j = i + 1;
		while (j < 10)
		{
			k = j + 1;
			while (k < 10)
			{
				putchar(i + 48);
				putchar(j + 48);
				putchar(k + 48);
				k++;
				if (i != 7)
				{
					putchar(',');
					putchar(' ');
				}
			}
			j++;
		}
		i++;
	}
	putchar('\n');
return (0);
}
