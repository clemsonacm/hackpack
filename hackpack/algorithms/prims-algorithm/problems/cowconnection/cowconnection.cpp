#include<unordered_map>
#include<unordered_set>
#include<limits>
using namespace std;

typedef unordered_map<int,int> umii;
typedef unordered_map< int , umii > umiumii;
//The graph class uses c++11 extensions; use map to get O(log N) time with c++98
class graph{
	unordered_map < int, unordered_map< int, int> > g;
	public:
		void insert(int s, int d, int e){g[s][d] = e;g[d];}
		umii::iterator find(int s, int d){ return g.find(s)->second.find(d); }
		umii::const_iterator begin(int s)const{ return g.find(s)->second.cbegin(); }
		umii::const_iterator end(int s)const{ return g.find(s)->second.cend(); }
        unordered_map<int, umii >::const_iterator begin ()const {return g.cbegin();}
        umiumii::const_iterator end () const {return g.cend();}
        int size()const{return g.size();}
		graph(): g() {};
};

void prims(const graph& g){
    int dist[g.size()];
    int parent[g.size()];
    bool intree[g.size()];
    for(const auto& i: g){
        dist[i.first] = numeric_limits<int>::max();
        intree[i.first] = false;
        parent[i.first] = -1;
    }


}

int main(){return 0;}
