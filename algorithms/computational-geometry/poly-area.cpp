#include<iostream>

double poly_area(double x[], double y[], int size){
	int i=0, j=size-1;	//Set J to next-to-last point
	double area = 0;

	for(i=0; i < size; i++){
		area+=(x[j] + x[i]) * (y[j]-y[i]);
		j = i;
	}

	return abs(area/2);
}
