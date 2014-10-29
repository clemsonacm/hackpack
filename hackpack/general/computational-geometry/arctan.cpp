/* Arctangent function:
 * provides arctangent of given ratio of opposite to adjacent.
 * Give the ratio between opposite and adjacent side, finds angle.
 * Always returns a value in radians between -pi/2 and pi/2, or -90 to 90 degrees.
 * Make sure you don't need to adjust answer for quadrant 2 or 3.
 * To convert to degrees, multiply by 180/PI as below.
 */
#include<iostream>
#include <cstdio>		//This is technically C, but <cmath> still works with C++
#include <cmath>		/* atan */
#define PI 3.14159265

int main() {
	double param, result;
	param = 1.0;
	result = atan (param) * 180 / PI; //Remove the " * 180 / PI" to convert to degrees.
	fprintf(stdout, "The arc tangent of %.1f is %.1f degrees\n", param, result );
	return 0;
}
