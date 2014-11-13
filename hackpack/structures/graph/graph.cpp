#include<unordered_map>
using namespace std;

typedef unordered_map<int,int> umii;
typedef unordered_map< int , umii > umiumii;
//The graph class uses c++11 extensions; use map to get O(log N) time with c++98
class sparse_graph{
	unordered_map < int, unordered_map< int, int> > graph;
	public:
		//inserts into the graphraph in O(1) am ex time
		void insert(int source, int destination, int edge){graph[source][destination] = edge;graph[destination];}

		//graphets a specific edgraphe in O(1) am ex time
		umii::iterator find(int source, int destination){
			return graph.find(source)->second.find(destination); 
		}

		//returns an begraphin iterator for all edges leaving source; O(K) time to traverse
		umii::iterator begin(int source){ return graph.find(source)->second.begin(); }
		
		//returns an end iterator for all edges leaving source; O(K) time to traverse
		umii::iterator end(int source){ return graph.find(source)->second.end(); }

        //returns begin iterator over all of the nodes
        unordered_map<int, umii >::iterator begin () {return graph.begin();}

        //returns end iterator over all of the nodes
        umiumii::iterator end () {return graph.end();}
        
		//Constructs the sparse graph
		sparse_graph(): graph() {};
};
