#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	srand(0);

	long n[1000] = {0};
	double rdm = 0;
	int j = 0;

	for (int i = 0; i < 1000; i++)
	{
		rdm = rand();
		rdm /= RAND_MAX; // 0..1
		rdm *= 200; // 0..200
		rdm -= 100; // -100..100

		n[i] = rdm;

		//printf("[%d] -> %ld\n", i, n[i]);
	}

	while (!(n[j] == 93))
	{
		j++;
	}

	printf("[%d] -> %ld\n", j, n[j]);


	return 0;
}