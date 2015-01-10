#include<fstream>
#include<ctime>

#include "graph-traversals.h"	

int main(void){
	const char *input_file_name = "depth-first-search.in";
	const char *output_file_name = "depth-first-search.out";
	/* Open input file */
	ifstream file;
	file.open(input_file_name);
	int graph_size, vertex, edge;
	/* The first number in input.txt specifies the number of vertices */
	file >> graph_size;
	/* Instantiate the graph with the graph_size variable */
	Graph g(graph_size, output_file_name);
	/* Parse each line beginning with second line for vertex and edge */
	while(file >> vertex >> edge){	
		/* Add the vertex and the edge emanating from it to the graph */
		g.addEdge(vertex, edge);
	}
 	file.close();

	/* Seed the rand() function */
	srand(time(NULL));
	/* Start both searches from a random start vertex */
	int rand_start_vertex = rand() % graph_size;
	/* Execute BFS from the random vertex */
	g.depth_first_search(rand_start_vertex);

	return 0;
}
