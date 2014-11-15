#include<iostream>
#include<cmath>

double tri_area(double *p1, double *p2, double *p3){
	double v1[2], v2[2];
	v1[0] = p2[0]-p1[0];
	v2[0] = p3[0]-p1[0];
	v1[1] = p2[1]-p1[1];
	v2[1] = p3[1]-p1[1];

	double det = (v1[0]*v2[1]) - (v1[1]*v2[0]);
	return det/2;
}


