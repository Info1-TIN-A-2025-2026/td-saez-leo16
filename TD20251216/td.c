#include <stdio.h>
#include <stdlib.h>

#define H 100
#define W 100
#define L 256

void fill_matrix(unsigned char m[H][W], int min, int max);
void display_matrix(unsigned char m[H][W]);
void compute_histo(unsigned char m[H][W], unsigned char n[L]);
void display_histo(unsigned char n[L]);

int main(int argc, const char *argv[])
{
	srand(0);

	unsigned char f[H][W] = {0};
	unsigned char h[L] = {0};

	fill_matrix(f, 0, 256);
	//display_matrix(f);

	compute_histo(f, h);
	display_histo(h);

	return 0;
}

void fill_matrix(unsigned char m[H][W], int min, int max)
{
	double rdm = 0;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			rdm = rand();
			rdm /= RAND_MAX;
			rdm *= (max - min);
			rdm += min;

			m[i][j] = rdm;
		}
	}
}

void display_matrix(unsigned char m[H][W])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			printf("%4d", m[i][j]);
		}

		printf("\n");
	}
}

void compute_histo(unsigned char m[H][W], unsigned char n[L])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			n[m[i][j]] += 1;
		}
	}
}

void display_histo(unsigned char n[L])
{
	for (int i = 0; i < L; i++)
	{
		printf("%4d:", i);

		for (int j = 0; j < n[i]; j++)
		{
			printf("*");
		}

		printf("\n");
	}
}
