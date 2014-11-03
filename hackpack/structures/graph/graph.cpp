#include<unordered_map>
using namespace std;

//The graph class uses c++11 extensions; use map to get O(log N) time with c++98
class sparse_graph{
	unordered_map < int, unordered_map< int, int> > graph;
	public:
		//inserts into the graphraph in O(1) am ex time
		void insert(int source, int destination, int edge){graph[source][destination] = edge;graph[destination];}

		//graphets a specific edgraphe in O(1) am ex time
		unordered_map<int,int>::iterator find(int source, int destination){
			return graph.find(source)->second.find(destination); 
		}

		//returns an begraphin iterator for all edges leaving source; O(K) time to traverse
		unordered_map<int, int>::iterator begin(int source){ return graph.find(source)->second.begin(); }
		
		//returns an end iterator for all edges leaving source; O(K) time to traverse
		unordered_map<int, int>::iterator end(int source){ return graph.find(source)->second.end(); }

		//Constructs the sparse graphraph
		sparse_graph(): graph() {};
};
