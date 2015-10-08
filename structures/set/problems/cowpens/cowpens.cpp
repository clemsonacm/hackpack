#include<algorithm>
#include<iostream>
#include<utility>
#include<set>
#include<vector>
using namespace std;

//#ifdef hackpackpp
//Using longs because 1000000*1000000 > MAX_INT
//#endif
const long MAXHEIGHT= 1000000;
typedef pair<long,long> pii;

// #ifdef hackpackpp
//The default sorting of pii is v1.first < v2.first;
//SortOnY allows for sorting on ascending y values
// #endif
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

    //#ifdef hackpackpp
	//Sort the elements on increasing y values
    //#endif
	sort(list.begin(),list.end(),SortOnY);

    //#ifdef hackpackpp
	//initialize variables
    //#endif
	set<pii>::iterator before, after;
	long area = 0;

    //#ifdef hackpackpp
	//Some times it is better to make a change than code an edge case
    //#endif
	myset.insert(make_pair(0,0));
	myset.insert(make_pair(1000000,0));

    //#ifdef hackpackpp
	//Use a sweep line based on the set
    //#endif
	for(vector<pii>::iterator it = list.begin(); it != list.end(); it++){
		myset.insert(*it);
		before = myset.lower_bound(*it);
		after = myset.upper_bound(*it);

        //#ifdef hackpackpp
		//lower_bound returns the pointer to the current element
		//decrement if it will be within bounds
        //#endif
		if(before != myset.begin()) before--;

        //#ifdef hackpackpp
		//compute the area of the box
        //#endif
		area = max(area,  it->second * (after->first - before->first));
	}


    //#ifdef hackpackpp
	//Check all of the plots that extend to the back of the plot
    //#endif
	after = myset.begin();
	for(before = myset.begin(); after != myset.end(); before++){
		after++;

        //#ifdef hackpackpp
		//compute the area of the long plots
        //#endif
		area = max(area, (after->first - before->first) * MAXHEIGHT);
	}

    //#ifdef hackpackpp
	//output according to the output spec
    //#endif
	cout << area << endl;
}
