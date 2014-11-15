#include<iostream>
#include<cmath>

double p_l_dist(double *li, double *lii, double* point){
	double a[3], b[3], axb[3];
	for(int c=0; c<3; c++) a[c]=-1*li[c]+lii[c];
	for(int c=0; c<3; c++) b[c]=-1*li[c]+point[c];

	axb[0] = ((a[1]*b[2])-(a[2]*b[1]));//Cross product of a and b
	axb[1] = ((a[2]*b[0])-(a[0]*b[2]));//alternatively, use cross product funciton
	axb[2] = ((a[0]*b[1])-(a[1]*b[0]));
	
	return (sqrt(axb[0]*axb[0] + axb[1]*axb[1] + axb[2]*axb[2])/
		sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]));
}
