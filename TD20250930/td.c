#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	double m1 = 0;
	double m2 = 0;
	double d = 0;
	const double g = 6.67e-11;
	double f = 0;

	printf("Enter mass 1 (in tonne): ");
	scanf("%lf", &m1);

	printf("Enter mass 2 (in tonne): ");
	scanf("%lf", &m2);

	printf("Entre distance (in km): ");
	scanf("%lf", &d);

	f = g * m1 * m2 / pow(d, 2);

	printf("%.3e\n", f);
}