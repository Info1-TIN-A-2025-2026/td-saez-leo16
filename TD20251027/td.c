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

	bool isPrime;

	for (int i = 2; i <= 100; i++)
	{
		isPrime = true;

		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}