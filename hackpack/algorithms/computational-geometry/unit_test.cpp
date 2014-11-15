#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

double dot_product(double *v, double *v2, int len);
void cross_product(double A[3], double B[3], double cross[3]);
double arctan(double param);
double p_l_dist(double *li, double *lii, double* point);
bool points_line_side(double p1[2], double p2[2], double slope, double intercept);
bool is_convex(double *xes, double *yes, int len);
double poly_area(double x[], double y[], int size);
int poly_contains(int vertices, double *vertx, double *verty, double tx, double ty);
double tri_area(double *p1, double *p2, double *p3);


int main(){
int success=0, fail=0;
double v1[3] = {1, 2, 3};
double v2[3] = {-4, 0, 7};
double r[3], y, z;
int test[4];
bool a, b;

cout << "Computational Geometry Unit Tests\n";

//Dot product
fprintf(stdout, "Dot Product of {%.0lf, %.0lf, %.0lf} and {%.0lf, %.0lf, %.0lf} is 17.\n", 
		v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
fprintf(stdout, "Dot product function returns %lf, and %lf reversed.\n\n",
		dot_product(v1, v2, 3), dot_product(v2, v1, 3));
if((dot_product(v1, v2, 3) == 17) && (dot_product(v2, v1, 3) == 17)) success++;
else fail++;

//Cross Product
cross_product(v1, v2, r);
fprintf(stdout, "Cross Product of {%.0lf, %.0lf, %.0lf} and {%.0lf, %.0lf, %.0lf} is {14, -19, 8}.\n", 
		v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
fprintf(stdout, "Cross product function returns {%.0lf, %.0lf, %.0lf}.\n\n", r[0], r[1], r[2]);
if((r[0]==14) && (r[1]==-19) && (r[2]==8)) success++;
else fail++;

//Arctangent
fprintf(stdout, "Arctangent of 1 is %.1lf, arctan(-sqrt(3)) is %.1lf\n",
	r[0]=arctan(1.0), r[1]=arctan(-1*sqrt(3)));
cout << "Expected 45 and -60 degrees\n\n";
if((r[0] == 45) && (r[1]==-60)) success++;
else fail++;

//Sides of a line
fprintf(stdout, "Cows on same side of Fence test. (Points and line)\n");
fprintf(stdout, "Points: (%.0lf, %.0lf), (%.0lf, %.0lf)\n", v1[0], v1[1], v2[0], v2[1]);
cout << "Line: -x = y, or the line through the origin and (-1, 1).\n";
fprintf(stdout, "Points 1 and 2: %d, should be false.\n", a=points_line_side(v1, v2, -1, 0));
fprintf(stdout, "Duplicate point shoud be true: %d.\n", b=points_line_side(v1, v1, -1, 0));
if(!a && b) success ++;
else fail++;

//Point to line distance
double r2[3] = {0, 0, 0};
y = p_l_dist(v1, v2, r2);
double r3[3] = {5, 7, -9};
z = p_l_dist(v1, v2, r3);
fprintf(stdout, "Distance from (0, 0, 0) and (5, 7, -9) to point through ");
fprintf(stdout, "(%.1lf, %.1lf, %.1lf) and (%.1lf, %.1lf, %.1lf):\n", 
	v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
fprintf(stdout, "Correct values: 3.7 and 7.1\n");
fprintf(stdout, "Calculated values: %.1lf and %.1lf.\n\n", y, z);
if((abs(y-3.7)<.1) && (abs(z-7.1)<.1)) success++;
else fail++;

//Polygon area
double polyx[6] = {-1, -1, 2, 2, 3, 3};
double polyy[6] = {-1, 1, 2, 1, 1, -1};
fprintf(stdout, "Polygon is formed by (-1, -1), (-1, 1), (2, 2), (2, 1), (3, 1), and (3, -1)\n\n");

y = poly_area(polyx, polyy, 6);
fprintf(stdout, "Area of Polygon should be 9.5, is %.1lf.\n\n", y);
if(abs(y-9.5)<.01) success++;
fail++;

//Polygon Convexity
fprintf(stdout, "Polygon Convexity:\nShould be no: %d\n", a=is_convex(polyx, polyy, 6));
polyy[3]=1.75;
polyx[3]=2.75;
cout << "Changed fourth point to (1.75, 2.75)\n";
fprintf(stdout, "Should be yes: %d\n\n", b=is_convex(polyx, polyy, 3));
if(a && b) success++; else fail++;


//Polygon Contains Point?
fprintf(stdout, "Polygon contains point:\nShould be yes: %d\n", test[0] = poly_contains(6, polyx, polyy, 1, 0));
fprintf(stdout, "Should be no: %d\n\n", test[1] = poly_contains(6, polyx, polyy, 3, 3));
if(test[0] && (!test[1])) success++;
else fail++;

//Triangle Area
r[0] = 1; r[1] = 0;
fprintf(stdout, "Area of Triangle from (1, 2), (-4, 0), and (1, 0) should be 5. Calculated: %.1lf.\n\n", tri_area(v1, v2, r));

return 0;
}
