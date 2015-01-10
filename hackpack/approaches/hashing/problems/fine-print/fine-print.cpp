#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	//Initialize the strings
	string target = "pool";
	string text = "", buffer ="";
	int target_hash = 0;
	int hash = 0;
	int count = 0;

	//Read in the string into memory
	while(!cin.eof()) {getline(cin,buffer); text +=buffer;}

	//Calculate the starting hashes
	for(int i=0; i<target.length(); i++){
		target_hash = target_hash * 31 + target[i];
		hash = hash * 31 + text[i] ;
	}

	//Calculate the hashes as the windows slides
	for(int i=0,j=target.length();j<text.length();i++,j++){
		if(hash == target_hash) count++;
		hash = (hash * 31) + text[j] - text[i]*pow(31,4);
	}
	//don't forget the possible ending point match
	if(hash == target_hash) count++;

	cout << count << endl;

	return 0;
}
