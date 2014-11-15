#include<iostream>
#include<cstdlib>

double poly_area(double x[], double y[], int size){
	int i=0, j=size-1;	//Set J to next-to-last point
	double area = 0;

	for(i=0; i < size; i++){
		area+=(x[j] + x[i]) * (y[j]-y[i]);
		j = i;
	}

	if(area>0) return area * 0.5;
	else return area * -0.5;
}
