#include<queue>
#include<unordered_map>
#include<limits>
#include<functional>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;


//Taken from the section on graphs
typedef unordered_map<int,int> umii;
typedef umii::const_iterator edge_iter;
typedef unordered_map<int,umii> umiumii;
typedef umiumii::const_iterator graph_iter;
class graph{
	umiumii g;
	public:
		void insert(int s, int d, int e){g[s][d] = e;g[d];}
		umii::iterator find(int s, int d){ return g.find(s)->second.find(d);}
		edge_iter cbegin(int s)const{return g.find(s)->second.cbegin();}
		edge_iter cend(int s)const{return g.find(s)->second.cend(); }
        graph_iter begin ()const {return g.cbegin();}
        graph_iter end () const {return g.cend();}
        int size()const{return g.size();}
		graph(): g() {};
};

//Convenes class that improves readably of code.
class edge{
	public: int source,dest,cost;
	//defining the operator> function allows use to use std::greater<edge>
	bool operator> (const edge& rhs) const{ return cost > rhs.cost ;}
	edge(int source, int dest, int cost):source(source),dest(dest),cost(cost){};
};

//Finds a undirected minimum spanning forest in O(E log V) time 
//For connected graphs, this produces a minimum spanning tree
graph prims(const graph& g){
	
	priority_queue<edge, vector<edge>, greater<edge> > Q; //queue of edges
	vector<bool> in_tree(g.size(), false); //tracks if an element is in the tree
	graph mst; //Graph that holds the minimum spanning forest

	//chose an arbitrary first node and queue all its edges
	for(auto node = g.begin(); node!= g.end(); node++){
		
		//Skip nodes that have been visited
		if (!in_tree[node->first]) { 

			//Visit an arbitrary node
			in_tree[node->first] = true;
			for(auto i = g.cbegin(node->first); i != g.cend(node->first); i++){
				Q.emplace(node->first, i->first, i->second);
			}

			while(Q.size() > 0){

				//Remove an edge from the queue.
				edge e = Q.top();
				Q.pop();
				
				//if the edge is in the tree ignore it
				if (!in_tree[e.dest]) { 
					in_tree[e.dest] = true; 
					mst.insert(e.source, e.dest, e.cost); 
					mst.insert(e.dest, e.source, e.cost); 
					for(auto i = g.cbegin(e.dest); i != g.cend(e.dest); i++){
						Q.emplace(e.dest, i->first, i->second);
					}
				}
			}
		}
	}
	return mst;

}

int main(){
	//Assumes nodes are numbered 0..N-1
	graph g; 
	int n,s,d,e;

	cin >> n;
	while(n--){
		cin >> s >> d >> e;	
		g.insert(s,d,e);
		g.insert(d,s,e);
	}

	//Solve the problem
	graph mst = prims(g);

	//Prepare the graph for printing
	int cost=0;
	set<pair<int,int> > edges;
	for (auto i = mst.begin(); i != mst.end(); i++){
		for(auto j = mst.cbegin(i->first); j != mst.cend(i->first); j++){
			int a=i->first,b=j->first;
			cost += j->second;
			edges.emplace(min(a,b),max(a,b));
		}	
	}
	//Edges were double counted so divide by 2.
	cost/=2;

	//Print a minimum spanning tree
	cout << cost << endl;
	for(auto i = edges.begin(); i != edges.end(); i++)
		cout << i->first << " " << i->second << endl;

	return 0;
}
