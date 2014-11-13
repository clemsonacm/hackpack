#include<iostream>
#include<cmath>

int main(){
	double p1[2]={0,0}, p2[2]={0,3}, p3[2]={4,0}; //Three 2d points to measure the area of the triangle between
	double v1[2], v2[2];
	v1[0] = p2[0]-p1[0];
	v2[0] = p3[0]-p1[0];
	v1[1] = p2[1]-p1[1];
	v2[1] = p3[1]-p1[1];

	int det = (v1[0]*v2[1]) - (v1[1]*v2[0]);
	int area = det/2;
}


