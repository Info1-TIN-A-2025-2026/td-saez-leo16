#include <stdio.h>
#include <stdint.h>

int main(int argc, const char *argv[])
{
	int32_t s = 0;

	printf("Number of seconds: ");
	scanf("%d", &s);

	if (s < 0)
	{
		puts("Error");
	}

	else if (s >= 86400)
	{
		puts("Overflow");
	}

	else
	{
		uint8_t hours = 0;
		uint8_t minutes = 0;
		uint8_t seconds = 0;

		hours = s / 3600;
		minutes = s / 60 - hours * 60;
		seconds = s - minutes * 60 - hours * 3600;

		printf("%02u:%02u:%02u\n", hours, minutes, seconds);
	}
}