<<<<<<< HEAD
#include<iostream>
#include<cmath>		/* atan */
#define PI 3.14159265

double arctan(double param) {
	double result;
	result = atan (param) * 180 / PI; //Remove the " * 180 / PI" to convert to degrees.
	//fprintf(stdout, "The arc tangent of %.1f is %.1f degrees\n", param, result );
	return result;
}
=======
#include<iostream>
#include <cmath>		/* atan */
#define PI 3.14159265

int main() {
	double param, result;
	param = 1.0;
	result = atan (param) * 180 / PI; //Remove the " * 180 / PI" to convert to degrees.
	fprintf(stdout, "The arc tangent of %.1f is %.1f degrees\n", param, result );
	return 0;
}
>>>>>>> 54f62fb475ff714691c744b1d2f4934192f72762
