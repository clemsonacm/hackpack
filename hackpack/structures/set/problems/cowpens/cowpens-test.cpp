//This file implements a slow solution (O(n^2)) to the cowpens
//problem for verification
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef pair<long,long> pii;
vector<pii> v;

int main(int argc, char *argv[])
{
	long area =0;
	long x,y,N;

	//get the input
	cin >> N;
	for (long i = 0; i < N; ++i)
	{
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}

	//sometimes it is easier to change the input than code an edge case
	v.push_back(make_pair(0,0));
	v.push_back(make_pair(1000000,0));

	//sort the points x (default sorting of a pair)
	sort(v.begin(),v.end());

	//for every two point p1, p2, find the point closest to the river
	for(vector<pii>::iterator left = v.begin(); left!= v.end(); left++){
		long min_y = 1000000;
		for(vector<pii>::iterator right = left+1; right!= v.end(); right++){
			area = max(area, (right->first - left->first) * min_y);
			min_y = min( min_y, right->second);
		}
	}
	cout << area << endl;
	
	return 0;
}
