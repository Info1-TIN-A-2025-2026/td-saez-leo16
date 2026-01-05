#include <stdio.h>
#include <string.h>

void display(char *t);

int main(int argc, const char *argv[])
{
	char s1[] = "mot";
	printf("memory size : %ld\n", sizeof(s1));
	printf("num cells   : %ld\n", sizeof(s1) / sizeof(char));

	unsigned long count = 0;

	while (s1[count] != 0)
	{
		count++;
	}

	printf("string length : %lu\n", count);
	printf("string length : %lu\n", strlen(s1));

	//
	char s2[100] = "mot";
	printf("memory size : %ld\n", sizeof(s2));
	printf("string length : %lu\n", strlen(s2));

	//
	char *s3 = "pipo";
	printf("memory size : %ld\n", sizeof(s3));
	printf("string length : %lu\n", strlen(s3));

	//
	char s4[] = "Voluptates quam vel aut cum quam laboriosam." \
	"Consequatur autem numquam sint voluptatem tenetur laboriosam asperiores." \
	"Totam optio perferendis a. Laboriosam tenetur porro corporis quisquam." \
	"Dignissimos architecto deleniti illum accusamus adipisci.";
	printf("memory size : %ld\n", sizeof(s4));
	printf("string length : %lu\n", strlen(s4));

	char s5[] = "ABC";
	display(s5);

	char s6[][10] = { // 3 x 10 char (9+\0) = 30 bytes in memory -- char = 1 byte
		"ABC",
		"DEF",
		"GHIJKL"
	};

	char *s7[] = { // 3 x sizeof(address) = 24 bytes -- address = 8 bytes
		"ABC",
		"DEF",
		"GHIJKL"
	};

	return 0;
}

void display(char *t)
{
	for (int i = 0; i < strlen(t) + 1; i++)
	{
		printf("%3d ", t[i]);
	}

	printf("\n");

	for (int i = 0; i < strlen(t) + 1; i++)
	{
		printf("%2c  ", t[i]);
	}

	printf("\n");
}