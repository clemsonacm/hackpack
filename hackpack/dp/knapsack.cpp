#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class item{
	public:
		int size;
		int value;
		item(int s, int v): size(s), value(v) {}
};

vector<item> items;
vector<int> A;

int main(int argc, char *argv[])
{
	int N,C,s,v;
	cin >> N >> C;
	for (int i = 0; i < N; i++){
		cin >> s >> v;
		items.push_back(item(s,v));
	}
	for (int j = 0; j < C; j++){
		int m=0;
		for(vector<item>::iterator i = items.begin(); i != items.end(); i++){
			if(j - i->size >= 0) m = max(A[j - i->size] + i->value, m);
		}
		A.push_back( max(A[j-1], m));
	}
	cout << A[C] << endl;

	return 0;
	
}
