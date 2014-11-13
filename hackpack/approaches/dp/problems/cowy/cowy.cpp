#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
	int vote;
	vector<int> votes; // the votes of the cows
	vector<int> lenght; // the lenght of the longest sequence
	//Read in the votes of the cows
	while(cin >> vote) {
		votes.push_back(vote);
		lenght.push_back(1);
	}

	//solve the problem
	//for each stopping place
	for(int i=0; i<votes.size(); i++){
		//extend the sequence if possible
		for(int j=0; j<i; j++){
			if (votes[j] < votes[i]) lenght[i] = max(lenght[i],lenght[j]+1);
		}
	}

	//The largest increasing subsequence could end with any vote
	int k =0;
	for(int i=0; i< votes.size(); i++){
		k = max(k,lenght[i]);
	}

	//if the length of the largest increasing subsequence is 
	//greater than the number of votes/2 then the cows bake a
	//cake else they do not
	if (k > votes.size()/2) cout << "1" << endl;
	else cout << "0" << endl;


	return 0;
}
