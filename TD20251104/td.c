#include <stdio.h>

int main(int argc, const char *argv[])
{
	/*const unsigned int I_MIN = 10;
	const unsigned int I_MAX = 20;

	unsigned int i = 0;
	
	do
	{
		int ret = 0;
		printf("Enter a integer value in range [%u...%u]: ", I_MIN, I_MAX);
		ret = scanf("%u", &i);

		if (ret != 1)
		{
			while(getchar()!='\n');
		}
	} while (i < I_MIN || i > I_MAX);

	printf("i = %u\n", i);*/

	unsigned int state = 0;

	printf("Enter state (ON=1, OFF=2, BLINK=4): ");
	scanf("%u", &state);

	switch(state)
	{
		case 1:
			puts("ON");
			break;
		case 2:
			puts("OFF");
			break;
		case 4:
			puts("BLINK");
			break;
		default:
			puts("ERROR");
			break;
	}

	return 0;
}