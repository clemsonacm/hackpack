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
int dist[1000*1000+1]; //Array to hold the minimum distance to each grid
int farmMap[1001][1001]; //Buffer to hold the zombie locations while graph is built

int main(){
    int t;
    cin >> t;
    while(t--){
        int X,Y; //Used to hold farmer John's location
        int k,w,h; //hold number of zombie classes, hight and width.
		//Read in the zombie classes
        unordered_map<char, int> zombie_classes;
        graph g;
        cin >> k >> w >> h;
        while(k--){ 
            char z; //zombie class name
            int t; // time it will take to escape them
            cin >> z >> t;
            zombie_classes[z] = t;
        }
		//Build the farmMap
        zombie_classes['F'] = 0; //Farmer John can escape the barn instantly
        for(int j=0; j<h; j++){
            for(int i=0; i < w; i++){
                char s;
                cin >> s;
                farmMap[i][j] =zombie_classes[s]; //fill the buffer with the time to pass through
                if (s == 'F')  {X=i;Y=j;} //When we find farmer john store his location
            }
        }
		//Build the graph
        for(int i=0; i < w; i++){
            for(int j=0; j < h; j++){
                int id = i + w*j;
				//initialize the distance to node to the max int
                dist[id] = numeric_limits<int>::max();

				//if it does not run off the edge connect it
				//else map it to the dummy end node

                if(!(i+1 >= w) )
                    g.insert(id,id+1,farmMap[i+1][j]);
                else g.insert(id,w*h,0);

                if(!(i-1 < 0) )
                    g.insert(id,id-1,farmMap[i-1][j]);
                else g.insert(id,w*h,0);

                if(!(j+1 >= h))
                    g.insert(id,id+w,farmMap[i][j+1]);
                else g.insert(id,w*h,0);

                if(!(j-1 < 0))
                    g.insert(id,id-w,farmMap[i][j-1]);
                else g.insert(id,w*h,0);
            }
        }
		//initalize the dummy end node
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
		//output the answer
        cout << dist[w*h] << endl;
    }
    return 0;
}
