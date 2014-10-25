#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
	int val;
	vector<int> A;
	vector<int> L;
	while(cin >> val) {
		A.push_back(val);
		L.push_back(1);
	}

	//solve the problem
	for(int j=0; j<A.size(); j++){
		for(int i=0; i<j; i++){
			if (A[i] < A[j]) L[j] = max(L[j],L[i]+1);
		}
	}

	int k =0;
	for(int i=0; i< A.size(); i++){
		k = max(k,L[i]);
	}

	cout << k << endl;


	return 0;
}
