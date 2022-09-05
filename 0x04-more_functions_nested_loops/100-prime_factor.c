#include "main.h"

/**
* main - Print the largest prime factor of 612852475143.
*
* Return: The largest prime factor of 612852475143
*/
int main(void)
{
	long primeFactor = 2, number = 612852475143;
	int mLPN = 0;

	while (number > 1)
	{
		while (number % primeFactor == 0)
		{
			mLPN = primeFactor;
			number = number / primeFactor;
		}
		primeFactor++;
	}
	printf("%d\n", mLPN);
	return (0);
}
