#include <stdio.h>
#include <math.h>

int f(unsigned int t, int *a, int *b, int *c);
void c2p(double x, double y, double *rho, double *theta);

int main(int argc, const char *argv[])
{
	/*unsigned int t = 3999;
	int h = 0;
	int m = 0;
	int s = 0;

	printf("address of h=%p\n", &h);
	printf("address of m=%p\n", &m);
	printf("address of s=%p\n", &s);

	f(t, &h, &m, &s);*/

	double x = 40;
	double y = 40;
	double rho = 0;
	double theta = 0;

	c2p(x, y, &rho, &theta);

	return 0;
}

void c2p(double x, double y, double *rho, double *theta)
{
	*rho = sqrt(pow(x, 2) + pow(y, 2));
	*theta = atan2(y, x) * 180/3.14;

	printf("rho = %lf\ntheta = %lf\n", *rho, *theta);
}

int f(unsigned int t, int *a, int *b, int *c)
{
	*a = t / 3600;
	*b = t / 60 - *a * 60;
	*c = t - *b * 60 - *a * 3600;

	printf("a=%p\n", a);
	printf("b=%p\n", b);
	printf("c=%p\n", c);

	printf("h=%d\n", *a);
	printf("m=%d\n", *b);
	printf("s=%d\n", *c);

	printf("%02d:%02d:%02d\n", *a, *b, *c);
	printf("%d [s]\n", t);

	return t;
}
