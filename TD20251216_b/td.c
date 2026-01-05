#include <stdio.h>

#define H 16
#define W 16

void display_matrix(unsigned char m[H][W]);
void dilatation(unsigned char m[H][W], unsigned char n[H][W]);

int main(int argc, const char *argv[])
{
	unsigned char t[H][W] = {0};
	unsigned char q[H][W] = {0};
	unsigned char r[H][W] = {0};

	for (int i = 4; i < 12; i++)
	{
		for (int j = 4; j < 12; j++)
		{
			t[i][j] = 255;
		}
	}

	display_matrix(t);
	dilatation(t, q);
	printf("\n");
	display_matrix(q);
	//substraction(t, q, r);
	printf("\n");
	display_matrix(r);
	printf("\n");

	return 0;
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

void dilatation(unsigned char m[H][W], unsigned char n[H][W])
{
	for (int i = 1; i < (H - 1); i++)
	{
		for (int j = 1; j < (W - 1); j++)
		{
			if (m[i][j] == 255)
			{
				for (int k = i - 1; k < i + 2; k++)
				{
					for (int l = j - 1; l < j + 2; l++)
					{
						n[k][l] = 255;
					}
				}
			}
		}
	}
}

void substraction(unsigned char m[H][W], unsigned char n[H][W], unsigned char o[H][W])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			o[i][j] = n[i][j] - m[i][j];
		}
	}
}
