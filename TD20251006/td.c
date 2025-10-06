#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	char a = 'A';	// ASCII code of 'A' = 65
	char b = 98;	// ASCII code of 'b' = 98

	unsigned char num_students = 23;
	unsigned char num_chairs = 32;

	signed short delta = num_students - num_chairs;

	bool sw1 = true;							// lampe prof allumée
	bool sw2 = true;							// lampe salle allumée

	unsigned char state = (sw2 << 4) + sw1;		// sw1 au bit 0, sw2 au bit 4

	// printf
	// 1 arg: format => simple string "Hello"
	//				 => combination "x=%d" %d format base 10 signed
	//				 => %u base 10 unsigned
	//				 => %hd base 10 signed short

	// Number of students = 23
	printf("Number of students = %u\n", num_students);

	// Number of students = 23, Number of chairs = 32
	printf("Number of students = %u, Number of chairs = %u\n", num_students, num_chairs);

	// Δ = -9
	printf("Δ = %hd\n", delta);

	// sw1, sw2
	printf("SW1 = %d, SW2 = %d\n", sw1, sw2);

	printf("State = %x (Base 16)\n", state);
	printf("State = %d (Base 10)\n", state);
	printf("State = %o (Base 8)\n", state);

	printf("a = %d\n", a);	// a = 65
	printf("a = %c\n", a);	// a = A
	printf("b = %c\n", b);	// b = b

	return 0;
}