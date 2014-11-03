#include<unordered_map>
using namespace std;

//The graph class uses c++11 extensions; use map to get O(log N) time with c++98
class sparse_graph{
	unordered_map < int, unordered_map< int, int> > g;
	public:
		//inserts into the graph in O(1) am ex time
		void insert(int s, int d, int e){g[s][d] = e;g[d];}

		//gets a specific edge in O(1) am ex time
		unordered_map<int,int>::iterator find(int s, int d){
			return g.find(s)->second.find(d); 
		}

		//returns an begin iterator for all edges leaving s; O(K) time to traverse
		unordered_map<int, int>::iterator begin(int s){ return g.find(s)->second.begin(); }
		
		//returns an end iterator for all edges leaving s; O(K) time to traverse
		unordered_map<int, int>::iterator end(int s){ return g.find(s)->second.end(); }

		//Constructs the sparse graph
		sparse_graph(): g() {};
};
