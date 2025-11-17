#include <stdio.h>

void proc(void); // Prototype for the function
void f1(const int a);

int main(int argc, const char *argv[])
{
	int i = 0;
	proc();

	printf("Enter an integer value: ");
	scanf("%d", &i);

	f1(i);

	return 0;
}

void proc(void)
{
	puts("Здавствуйте");
	return;
}

void f1(const int a)
{
	printf("%d\n", a * 3);
}