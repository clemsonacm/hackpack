#include<unordered_map>
using namespace std;

typedef unordered_map<int,int> umii;
typedef unordered_map< int , umii > umiumii;
//The graph class uses c++11 extensions; use map to get O(log N) time with c++98
class sparse_graph{
	unordered_map < int, unordered_map< int, int> > graph;
	public:
        //#ifdef hackpackpp
		//inserts into the graph in O(1) am ex time
        //#endif
		void insert(int source, int destination, int edge){graph[source][destination] = edge;graph[destination];}
        //#ifdef hackpackpp
        
		//inserts a specific edge in O(1) am ex time
        //#endif
		umii::iterator find(int source, int destination){
			return graph.find(source)->second.find(destination); 
		}
        //#ifdef hackpackpp
        
		//returns an begin iterator for all edges leaving source; O(K) time to traverse
        //#endif
		umii::iterator begin(int source){ return graph.find(source)->second.begin(); }
        //#ifdef hackpackpp

		//returns an end iterator for all edges leaving source; O(K) time to traverse
        //#endif
		umii::iterator end(int source){ return graph.find(source)->second.end(); }
        //#ifdef hackpackpp
        
        //returns begin iterator over all of the nodes
        //#endif
        unordered_map<int, umii >::iterator begin () {return graph.begin();}
        //#ifdef hackpackpp

        //returns end iterator over all of the nodes
        //#endif
        umiumii::iterator end () {return graph.end();}
        //#ifdef hackpackpp

		//Constructs the sparse graph
        //#endif
		sparse_graph(): graph() {};
};
