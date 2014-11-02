#include<unordered_map>
using namespace std;
class sparse_graph{
	unordered_map < int, unordered_map< int, int> > g;
	public:
	void insert(int s, int d, int e){
		if(g.find(s) == g.end()) g.emplace(s,unordered_map<int,int>());
		if(g.find(d) == g.end()) g.emplace(d,unordered_map<int,int>());
		g.at(s).emplace(d,e); }
	bool empty(){return g.empty();}
	size_t size(){return g.size();}
	unordered_map<int, int>::iterator begin(int s){ return g.at(s).begin(); }
	unordered_map<int, int>::iterator end(int s){ return g.at(s).end(); }
	sparse_graph(): g() {};
};
