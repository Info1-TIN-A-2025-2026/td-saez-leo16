#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double formula(int n);

int main(int argc, const char *argv[])
{
	char *endPtr = NULL;
	long n = 0;

	double p = 0.;

	n = strtod(argv[1], &endPtr);

	while (!(fabs(p - 3.1415) < pow(10, -4)))
	{
		p = formula(n);
		printf("%lf\n", p);
		n++;
	}

	printf("\n");
	printf("n = %ld\n", n);

	return 0;
}

double formula(int n)
{
	double a = 0.;
	double f = 0.;
	double p = 0.;

	for (int i = 0; i <= n; i++)
	{
		f = (pow(-1, i)) / (2 * i + 1);
		a += f;
	}

	p = 4 * a;

	return p;
}
