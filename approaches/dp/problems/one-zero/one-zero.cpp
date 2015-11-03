#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
//#ifdef hackpackpp

//Assumes that no more than 1000 items considered
//and that no more than 10000 capacity is used
//#endif
#define MAX_NUM_OF_ITEMS 1001
#define MAX_CAPACITY 10001
typedef pair<int,int> pii;

int A[MAX_NUM_OF_ITEMS][MAX_CAPACITY];
pii items[MAX_NUM_OF_ITEMS];

int main(int argc, char *argv[])
{
	//#ifdef hackpackpp
	//Read in the input
	//#endif
	int N,C, size, value;
	cin >> N >> C;
	for (int i = 1; i <= N; i ++){
		cin >> size >> value ;
		items[i] = make_pair(size, value);
	}
	//#ifdef hackpackpp
	//No need to set up base cases since global arrays of ints 
	//initialize to 0

	//Solve the problem;  Can be optomized to use O(C) memory
	//#endif
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= C; j++){
			if( j - items[i].first >= 0) 
				A[i][j] = max( A[i-1][j], A[i-1][j- items[i].first] + items[i].second );
			else A[i][j] = A[i-1][j];
		}
	}
	cout << A[N][C] << endl;
	return 0;
}
