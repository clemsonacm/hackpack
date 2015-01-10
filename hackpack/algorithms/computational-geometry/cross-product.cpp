#include<iostream>
void cross_product(double A[3], double B[3], double cross[3]){
	//Input one and two, then output, all taken to be size-3 double arrays
	cross[0] = ((A[1]*B[2])-(A[2]*B[1]));
	cross[1] = ((A[2]*B[0])-(A[0]*B[2]));
	cross[2] = ((A[0]*B[1])-(A[1]*B[0]));//The cross vector is equal to the cross product of A and B
}
