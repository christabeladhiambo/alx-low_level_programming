#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* main - Crack the hash key for the crackme5 file
*
* @argc: The number of argument
* @argv: Array of arg
*
* Return: 0 if succes, -1 else
*/
int main(int argc, char **argv)
{
int lenName = 0;
char *lC = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
int i, sum, _char;
char *res = malloc(sizeof(char) * 7);

if (argc != 2 || !res)
{
printf("Only 2 argument is needed : ./keygen5 name");
return (-1);
}
lenName = strlen(argv[1]);
res[0] = lC[(lenName ^ 59) & 63];
for (i = 0, sum = 0; i < lenName; i++)
sum += argv[1][i];
res[1] = lC[(sum ^ 79) & 63];
for (i = 0, sum = 1; i < lenName; i++)
sum *= argv[1][i];
res[2] = lC[(sum ^ 85) & 63];
_char = argv[1][0];
for (i = 0; i < lenName; i++)
{
if (_char < argv[1][i])
_char = argv[1][i];
}
srand(_char ^ 14);
res[3] = lC[rand() & 63];
for (i = 0, sum = 0; i < lenName; i++)
sum = sum + argv[1][i] * argv[1][i];
res[4] = lC[(sum ^ 239) & 63];
for (i = 0, sum = 0; i < argv[1][0]; i++)
sum = rand();
res[5] = lC[(sum ^ 229) & 63];
res[6] = '\0';
printf("%s\n", res);
return (0);
}
