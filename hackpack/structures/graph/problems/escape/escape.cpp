#include<iostream>
#include<iomanip>
#include<functional>
#include<unordered_map>
#include<queue>
#include<utility>
#include<limits>

using namespace std;

class graph{
    unordered_map< int , unordered_map< int, int> > g;
    public:
    void insert(int s, int d, int e){g[s][d] = e; g[d];}
    unordered_map<int,int>::iterator find(int s, int d){
        return g.find(s)->second.find(d);}
    unordered_map<int,int>::iterator begin (int s) {return g.find(s)->second.begin();}
    unordered_map<int,int>::iterator end (int s) {return g.find(s)->second.end();}
    graph(): g(){};
};
int dist[1000*1000+1];
int C[1001][1001];

int main(){
    int t;
    cin >> t;
    while(t--){
        int X,Y;
        int k,w,h;
        unordered_map<char, int> zombie_classes;
        graph g;
        cin >> k >> w >> h;
        while(k--){ 
            char s;
            int a;
            cin >> s >> a;
            zombie_classes[s] = a;
        }
        zombie_classes['E'] = 0;
        for(int j=0; j<h; j++){
            for(int i=0; i < w; i++){
                char s;
                cin >> s;
                C[i][j] =zombie_classes[s];
                if (s == 'E')  {X=i;Y=j;}
            }
        }
        for(int i=0; i < w; i++){
            for(int j=0; j < h; j++){
                int id = i + w*j;
                dist[id] = numeric_limits<int>::max();
                if(!(i+1 >= w) )
                    g.insert(id,id+1,C[i+1][j]);
                else g.insert(id,w*h,0);

                if(!(i-1 < 0) )
                    g.insert(id,id-1,C[i-1][j]);
                else g.insert(id,w*h,0);

                if(!(j+1 >= h))
                    g.insert(id,id+w,C[i][j+1]);
                else g.insert(id,w*h,0);

                if(!(j-1 < 0))
                    g.insert(id,id-w,C[i][j-1]);
                else g.insert(id,w*h,0);
            }
        }
        dist[w*h] = numeric_limits<int>::max();

		//This is how you make a min-queue of pair<int,int> in C++
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > q;
		
        //dijkstra whohoo
        q.push(make_pair(0,X+w*Y));
        dist[X+w*Y]=0;
        while(!q.empty()){
            auto n = q.top();
            int d = n.first;
            int v = n.second;
            q.pop();
            if(d <= dist[v]){
               for(auto tmp = g.begin(v); tmp != g.end(v); tmp++){
                    if (dist[tmp->first] > d+tmp->second){
                        dist[tmp->first] = d+tmp->second;
                       q.push(make_pair((d+tmp->second), tmp->first));
                    }
               } 
            }
        } 
        cout << dist[w*h] << endl;
    }
    return 0;
}
