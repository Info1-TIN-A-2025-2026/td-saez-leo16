#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{

	// Boucle While()
	/*const unsigned int BASE = 10;

	unsigned int n = atoi(argv[1]);
	unsigned int w = n == 0 ? 1 : 0;

	while(n > 0)
	{
		n /= BASE;
		w++;
	}

	printf("w=%u\n", w);*/

	unsigned int n = atoi(argv[1]);
	unsigned int r = 0;

	do
	{
		r *= 10;
		r += n % 10;
		n /= 10;

	} while (n > 0);

	printf("r = %u\n", r);

	return 0;
}