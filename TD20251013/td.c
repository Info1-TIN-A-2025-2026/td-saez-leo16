#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	const double vol = 27.4;
	const double rate = 1.5;

	double stockPrice = 0;
	double strike = 0;
	double days = 0;

	double d1 = 0;
	double d2 = 0;
	double T = 0;

	double n_d1 = 0;
	double n_d2 = 0;

	double a1 = 0.319381530;
	double a2 = -0.356563782;
	double a3 = 1.781477937;
	double a4 = -1.821255978;
	double a5 = 1.330274429;
	double k1 = 0;
	double k2 = 0;

	double finalPrice = 0;

	printf("Enter stock price: ");
	scanf("%lf", &stockPrice);

	printf("Enter strike: ");
	scanf("%lf", &strike);

	printf("Enter remaining days: ");
	scanf("%lf", &days);

	T = days / 365;

	d1 = 1 / (vol * sqrt(T)) * (log(stockPrice / strike) + (rate + pow(vol, 2) / 2) * T);
	k1 = 1 / (1 + 0.2316419 * d1);
	n_d1 = (exp(pow(-d1, 2) / 2) / sqrt(2 * 3.1415)) * (a1 * k1 + a2 * pow(k1, 2) + a3 * pow(k1, 3) + a4 * pow(k1, 4) + a5 * pow(k1, 5));
	d2 = d1 - vol * sqrt(T);
	k2 = 1 / (1 + 0.2316419 * d2);
	n_d2 = (exp(pow(-d2, 2) / 2) / sqrt(2 * 3.1415)) * (a1 * k2 + a2 * pow(k2, 2) + a3 * pow(k2, 3) + a4 * pow(k2, 4) + a5 * pow(k2, 5));
	finalPrice = stockPrice * n_d1 - strike * exp(-rate / T) * n_d2;

	printf("Price : %lf", finalPrice);

	return 0;
}