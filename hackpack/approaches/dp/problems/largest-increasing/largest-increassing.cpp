#include <iostream>
#include <vector>
using namespace std;

#define MAX_LEN 10000
int L[MAX_LEN];

int main(int argc, char *argv[])
{
	int val;
	vector<int> A;
	while(cin >> val) A.push_back(val);

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
