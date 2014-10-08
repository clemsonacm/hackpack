#include<algorithm>
#include<iostream>
#include<utility>
#include<set>
#include<vector>
using namespace std;

const long MAXHEIGHT= 1000000;
typedef pair<long,long> pii;

//The default sorting of pii is v1.first < v2.first;
//SortOnY allows for sorting on ascending y values
bool SortOnY(pii v1 ,pii v2){return v1.second < v2.second;}
vector<pii> list;
set<pii> myset;

int main (){
    long N,x,y;
    cin >> N;
    for(long i = 0; i < N; i++){
        cin >> x >> y;
        list.push_back(make_pair(x,y));
    }

    //Sort the elements on increasing y values
    sort(list.begin(),list.end(),SortOnY);

	//initialize variables
    set<pii>::iterator before, after;
    long leftxbound, rightxbound;
    long area = 0;

	//Some times it is better to make a change than code an edge case
    myset.insert(make_pair(0,0));
    myset.insert(make_pair(1000000,0));

	//Use a sweep line based on the set
    for(vector<pii>::iterator it = list.begin(); it != list.end(); it++){
        myset.insert(*it);
        before = myset.lower_bound(*it);
        after = myset.upper_bound(*it);
		
		//lower_bound returns the pointer to the current element
		//decrement if it will be within bounds
		if(before != myset.begin()) before--;

		//compute the area of the box
        area = max(area,  it->second * (after->first - before->first));
    }


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
