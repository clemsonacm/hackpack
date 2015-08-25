#include<iostream>

int poly_contains(int vertices, double *vertx, double *verty, double tx, double ty)
{
	int c=0, d=vertices-1, r = 0;
	for (; c < vertices; d = c++) {
		if ( ((verty[c]>ty) != (verty[d]>ty)) &&
			(tx < (vertx[d]-vertx[c]) * (ty-verty[c]) / (verty[d]-verty[c]) + vertx[c]) )
			r = !r;
	}
	return r;
}
