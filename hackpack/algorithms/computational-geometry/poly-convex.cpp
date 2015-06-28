#include<iostream>

bool is_convex(double *xes, double *yes, int len){
if(len < 3) return false;
double prev, next;
prev = xes[0]*yes[1 ] - xes[1]*yes[0];

for(int c=1; c<len; c++){
	next = xes[c]*yes[c+1] - xes[c+1]*yes[c];
	if((prev*next) < 0) return false;
	prev=next;
}
return true;
}
