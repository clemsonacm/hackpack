#include<iostream>

bool points_line_side(double p1[2], double p2[2], double slope, double intercept){
	double diff1 = slope * p1[0] + intercept - p1[1];
	double diff2 = slope * p2[0] + intercept - p2[1];
	if((diff1*diff2) >= 0)
		return true;
	return false;
}
