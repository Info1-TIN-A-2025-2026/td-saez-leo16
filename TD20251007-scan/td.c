#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	float x = 0.f;
	float y = 0.f;
	int ret = 0;

	// printf("Enter a floating point value x: ");
	// ret = scanf("%f", &x); // &x = address of variable x

	// printf("x=%.4f\n", x);
	// printf("ret=%d\n", ret);

	// printf("Enter a floating point value y: ");
	// ret = scanf("%f", &y); // &y = address of variable y

	// printf("y=%.4f\n", y);
	// printf("ret=%d\n", ret);

	// printf("Enter two floating point values (space separated): ");
	// ret = scanf("%f%f", &x, &y);
	// printf("ret=%d\n", ret);
	// printf("x=%.4f\n", x);
	// printf("y=%.4f\n", y);

	printf("Enter two floating point values (: separated): ");
	ret = scanf("%f:%f", &x, &y);	// add separator-char in-between the %f
	printf("ret=%d\n", ret);
	printf("x=%.4f\n", x);
	printf("y=%.4f\n", y);

	return 0;
}