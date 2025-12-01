#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	char *endPtr = NULL;
	unsigned int n = 0;
	unsigned int width = 0;

	char symbole = '*';
	char trunkSymbole = '|';
	char baseSymbole = '-';

	if (argc < 2)
	{
		printf("Not enough argument.");
		return 1;
	}

	n = strtod(argv[1], &endPtr);

	if (n % 2 == 0)
	{
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%*c", n - i, symbole);

		for (int j = 0; j < width; j++)
		{
			printf("*");
		}

		width += 2;
		printf("\n");
	}

	printf("%*c\n", n, trunkSymbole);
	printf("%*c\n", n, trunkSymbole);
	printf("%*c%c%c\n", n - 1, baseSymbole, baseSymbole, baseSymbole);
	
	return 0;
}
