#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

//Assumes that no more than 1000 items considered
//and that no more than 10000 capacity is used
#define MAX_NUM_OF_ITEMS 1000
#define MAX_CAPACITY 10000
typedef pair<int,int> pii;

int A[MAX_NUM_OF_ITEMS][MAX_CAPACITY];
pii items[MAX_NUM_OF_ITEMS];

int main(int argc, char *argv[])
{
	//Read in the input
	int N,C, size, value;
	cin >> N >> C;
	for (int i = 0; i < N; i ++){
		cin >> size >> value ;
		items[i] = make_pair(size, value);
	}
	//No need to set up base cases since global arrays of ints 
	//initialize to 0

	//Solve the problem;  Can be optomized to use O(C) memory
	for(int i = 1; i < N; i++){
		for(int j = 0; j < C; j++){
			if( j - items[i].first >= 0) 
				A[i][j] = max( A[i-1][j], A[i-1][j- items[i].first] + items[i].second );
		}
	}
	return 0;
}
