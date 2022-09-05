#include <stdio.h>

/**
* main - Print the alphabet in lower case without q,e and using printf
* Return: 0 cause void function
*/
int main(void)
{
	char alphabet = 'a';

	while (alphabet <= 'z')
	{
		if (alphabet != 'q' && alphabet != 'e')
		{
			putchar(alphabet);
			alphabet++;
		}
		else
		{
			alphabet++;
		}
	}
	putchar('\n');
	return (0);
}
