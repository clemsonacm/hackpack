#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//#ifdef hackpackpp
//Create a item class to represent the items
//#endif
class item{
	public:
		int size,value;
		//#ifdef hackpackpp
		//This is an initializer list; it makes initializing easy
		//#endif
		item(int s, int v): size(s), value(v) {}
};

//#ifdef hackpackpp
//Create a vector of items to hold all of the items
//#endif
vector<item> items;
vector<int> A;

int main(int argc, char *argv[])
{
	//#ifdef hackpackpp
	//Read in the number of items, capacity, and items
	//#endif
	int N,C,s,v;
	cin >> C >> N;
	for (int i = 0; i < N; i++){
		cin >> s >> v;
		items.push_back(item(s,v));
	}
	//#ifdef hackpackpp

	//Solve the problem
	//Be certain to include the base case M(0) = 0
	//#endif
	A.push_back(0);
	//#ifdef hackpackpp

	//Iteratively solve the rest
	//#endif
	for (int j = 1; j <= C; j++){
		int m=INT_MIN;
		for(vector<item>::iterator i = items.begin(); i != items.end(); i++){
			if(j - i->size >= 0) m = max(A[j - i->size] + i->value, m);
		}
		A.push_back( max(A[j-1], m));
	}
	cout << A[C] << endl;

	return 0;
}
