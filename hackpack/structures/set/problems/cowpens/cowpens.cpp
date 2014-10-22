#include<algorithm>
#include<iostream>
#include<utility>
#include<set>
#include<vector>
using namespace std;

const long MAXHEIGHT= 1000000;
typedef pair<int,int> pii;
bool SortOnY(pii v1 ,pii v2){return v1.second < v2.second;}
bool SortOnX(pii v1 ,pii v2){return v1.first < v2.first;}
vector<pii> list;
set<pii> myset;

int main (){
    int N,x,y;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        list.push_back(make_pair(x,y));
    }

    //Sort the elements on increasing y values
    sort(list.begin(),list.end(),SortOnY);

	//initalize varibles
    set<pii>::iterator before, after;
    int leftxbound, rightxbound;
    long area = 0;

	//Use a sweep line based on the set
    for(vector<pii>::iterator it = list.begin(); it != list.end(); it++){
        myset.insert(*it);
        before = myset.lower_bound(*it);
        after = myset.upper_bound(*it);

		//compute the left and right boundaries
        leftxbound = (*before != *it) ? before->first : 0;
        rightxbound = (after != myset.end()) ? after->first : 1000000;

		//compute the area of the box
        area = max(area,  (long)it->second * (long)(rightxbound - leftxbound));
    }

	//Some times it is better to make a change than code an edge case
    myset.insert(make_pair(0,0));
    myset.insert(make_pair(1000000,0));

	//Check all of the plots that extend to the back of the plot
    after = myset.begin();
    for(before = myset.begin(); after != myset.end(); before++){
        after++;
        leftxbound = before->first; 
        rightxbound = (after != myset.end()) ? after->first : 1000000;

		//compute the area of the long plots
        area = max(area, (long)(rightxbound - leftxbound) * MAXHEIGHT);
    }

	//output according to the output spec
    cout << area << endl;
}
