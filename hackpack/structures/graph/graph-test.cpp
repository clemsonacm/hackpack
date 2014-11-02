#include<iostream>
#include"graph.cpp"

int main(int argc, char *argv[])
{	
	sparse_graph g;
	g.insert(1,2,3);
	g.insert(2,3,4);
	g.insert(1,3,4);

	return 0;
}
