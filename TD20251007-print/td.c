#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	long volume = 42; // m3

	printf("Volume = [%ld]\n", volume);
	printf("Volume = [%7ld]\n", volume);	// right justified
	printf("Volume = [%-7ld]\n", volume);	//  left justified
	printf("Volume = [%+ld]\n", volume);	// add sign of variable
	printf("Volume = [%+7ld]\n", volume);
	printf("Volume = [%+-7ld]\n", volume);

	long pression = -4; // bar

	printf("Pression = [%ld]\n", pression);

	double pi = 3.141592653;

	printf("π = [%lf]\n", pi);		// 6 digits after decimal point
	printf("π = [%.2lf]\n", pi);	// 2 digits after decimal point
	printf("π = [%+.2lf]\n", pi);	// force sign

	double absolute_zero = -459.67;	// °F

	printf("Zero abs. = [%.1lf]\n", absolute_zero); // 1 digit after decimal point

	printf("[%+10.2lf]\n", pi);
	printf("[%+10.2lf]\n", absolute_zero);

	double light_speed = 299792458.0;	// m/s
	printf("[%+10.2lf]\n", light_speed); // shift if too big

	int num_digits = 3; // &.3lf
	printf("π = [%.*lf]\n", num_digits, pi);	// 3 digits after decimal point

	num_digits = 12;
	printf("π = [%.*lf]\n", num_digits, pi); // num_digits digits after decimal point

	int width = 8;
	num_digits = 3;
	printf("π = [%+*.*lf]\n", width, num_digits, pi);	// 3 digits after decimal point

	return 0;
}