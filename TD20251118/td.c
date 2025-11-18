
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

double kmh_to_ms(double s_kmh);
double reaction_distance(double speed, double reaction_time);
double break_distance(double speed, double deceleration);
double total_stop_distance(double speed, double reaction_time, double deceleration);
bool stop_before_obstacle(double stop_distance, double obstacle_distance);

int main(int argc, const char *argv[])
{
	double speed_kmh = 0;
	double reaction_time = 0;
	double deceleration = 0;
	double d_obstacle = 0;

	double speed_ms = 0;
	double r_distance = 0;
	double b_distance = 0;
	double t_distance = 0;
	bool isSafe = false;

	printf("Enter the speed (km/h): ");
	scanf("%lf", &speed_kmh);

	printf("Enter the reaction time (s): ");
	scanf("%lf", &reaction_time);

	printf("Enter the deceleration (m/s/s): ");
	scanf("%lf", &deceleration);

	printf("Enter the distance to the obstacle (m): ");
	scanf("%lf", &d_obstacle);

	speed_ms = kmh_to_ms(speed_kmh);
	r_distance = reaction_distance(speed_ms, reaction_time);
	b_distance = break_distance(speed_ms, deceleration);
	t_distance = total_stop_distance(speed_ms, reaction_time, deceleration);
	isSafe = stop_before_obstacle(t_distance, d_obstacle);

	printf("Speed : %.2lf km/h = %.2lf m/s\n", speed_kmh, speed_ms);
	printf("Reaction distance : %.2lf m\n", r_distance);
	printf("Break distance : %.2lf m\n", b_distance);
	printf("Total stop distance : %.2lf m => ", b_distance);

	if (isSafe)
	{
		printf("☑ no collision");
	}

	else
	{
		printf("X collision");
	}

		return 0;
}

double kmh_to_ms(double s_kmh)
{
	assert(s_kmh >= 0);

	double s_ms = s_kmh / 3.6;

	return s_ms;
}

double reaction_distance(double speed, double reaction_time)
{
	assert(speed >= 0);
	assert(reaction_time >= 0);

	double rd = speed * reaction_time;

	return rd;
}

double break_distance(double speed, double deceleration)
{
	assert(speed >= 0);
	assert(deceleration >= 0);

	double bd = (speed * speed) / (2 * deceleration);

	return bd;
}

double total_stop_distance(double speed, double reaction_time, double deceleration)
{
	assert(speed >= 0);
	assert(reaction_time >= 0);
	assert(deceleration >= 0);

	double rd = reaction_distance(speed, reaction_time);
	double bd = break_distance(speed, deceleration);
	double tsd = rd + bd;

	return tsd;
}

bool stop_before_obstacle(double stop_distance, double obstacle_distance)
{
	return stop_distance < obstacle_distance ? true : false;
}
