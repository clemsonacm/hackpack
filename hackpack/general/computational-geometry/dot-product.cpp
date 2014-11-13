#include<iostream>
#include<vector>

double dot_product(double *v, double *v2, int len) {//Can convert all ints to doubles
	double result=0;
	for(int c=0; c < len; c++) result += (v[c] * v2[c]);
	return result;
}
