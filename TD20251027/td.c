#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	// OPERATORS DIVIDE AND MODULO
	/*int a = 0; // -13 / 0 / 17
	int b = 0; //  -3 / 0 /  3
	int q = 0;
	int r = 0;

	printf("enter a: ");
	scanf("%d", &a);

	printf("enter b: ");
	scanf("%d", &b);

	q = a / b;
	r = a % b;

	printf("a/b = %d\n", q);
	printf("a%%b = %d\n", r);*/

	// OPERATOR INCREMENTATION
	/*int a = 10;

	printf("%d\n", a++); // 10

	a = 10;

	printf("%d\n", ++a); // 11
	*/

	// PRINT PRIME NUMBER
	const unsigned int I_MIN = 2;
	const unsigned int I_MAX = 100;

	bool isPrime = true;
	unsigned int i = 0;
	unsigned int j = 0;

	for (i = I_MIN; i <= I_MAX; i++)
	{
		isPrime = true;

		for (j = I_MIN; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			printf("%u ", i);
		}
	}

	printf("\n");

	return 0;
}