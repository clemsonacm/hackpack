#include<iostream>
#include<string>
#include"graph.cpp"
#include<cassert>

int main(int argc, char *argv[])
{	
	sparse_graph g;
    string buffer;
    int s,d,e;
    while(cin >> s){
        cin >> d >> e;
        g.insert(s,d,e);
    }
    int edges=0;
    int A[] = {2,3,1,1};
    for(auto i = 1; i<5;i++){
        for(auto j = g.begin(i); j != g.end(i); j++){ edges++;}
        assert(edges==A[i-1]);
        edges = 0;
    }
    auto i = g.find(2,4);
    assert(i->second == 1);
    i = g.find(3,4);
    assert(i->second == 2);
    g.insert(2,4,3);
    i = g.find(2,4);
    assert(i->second == 3);



	return 0;
}
