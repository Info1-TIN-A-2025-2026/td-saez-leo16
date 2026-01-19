#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	const unsigned int MASS_FULL = 750000; // 750T
	const unsigned int MASS_EMPTY = 90000; // 90T
	const unsigned int SPEED = 4000;	   // 4km/s
	const unsigned int CONSUMPTION = 4000; // 4T/s

	unsigned int s = 0;
	unsigned int mass_old = MASS_FULL;
	unsigned int mass_new = MASS_FULL;
	unsigned int altitude = 0;
	double speed = 0;

	printf(" Time [s] | Mass [T] | Speed [m/s] | Speed [km/h] | Cons. [T] | Alt. [m]\n");
	printf("-------------------------------------------------------------------------\n");

	while (mass_new >= MASS_EMPTY)
	{
		speed += SPEED * log((double)mass_old / (double)mass_new);
		altitude += speed;

		if (!(s % 10) || mass_new == MASS_EMPTY)
		{
			printf("%9d |", s);
			printf("%9d |", mass_new / 1000);
			printf("%12.1lf |", speed);
			printf("%13.1lf |", speed * 3.6);
			printf("%10d |", (CONSUMPTION * s) / 1000);
			printf("%9d", altitude / 1000);
			printf("\n");
		}

		

		mass_old = mass_new;
		mass_new -= CONSUMPTION;
		s++;
	}

	return 0;
}