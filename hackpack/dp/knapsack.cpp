#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

//Create a item class to represent the items
class item{
	public:
		int size;
		int value;
		//This is an initializer list; it makes initializing easy
		item(int s, int v): size(s), value(v) {}
};

//Create a vector of items to hold all of the items
vector<item> items;
vector<int> A;

int main(int argc, char *argv[])
{
	//Read in the number of items, capacity, and items
	int N,C,s,v;
	cin >> C >> N;
	for (int i = 0; i < N; i++){
		cin >> s >> v;
		items.push_back(item(s,v));
	}

	//Solve the problem
	//Be certain to include the base case M(0) = 0
	A.push_back(0);

	//Iteratively solve the rest
	for (int j = 1; j <= C; j++){
		int m=INT_MIN;
		for(auto i = items.begin(); i != items.end(); i++){
			if(j - i->size >= 0) m = max(A[j - i->size] + i->value, m);
		}
		A.push_back( max(A[j-1], m));
	}
	cout << A[C] << endl;

	return 0;
}
