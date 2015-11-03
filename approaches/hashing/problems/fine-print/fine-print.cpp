#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define PRIME 31
#define LENGTH_TARGET 4

int main()
{
	//#ifdef hackpackpp
	//Initialize the strings
	//#endif
	string target = "pool";
	string text = "", buffer ="";
	int target_hash = 0;
	int hash = 0;
	int count = 0;
	//#ifdef hackpackpp

	//Read in the string into memory
	//#endif
	while(!cin.eof()) {getline(cin,buffer); text +=buffer;}
	//#ifdef hackpackpp

	//Calculate the starting hashes
	//#endif
	for(unsigned int i=0; i<target.length(); i++){
		target_hash = target_hash * PRIME + target[i];
		hash = hash * PRIME + text[i] ;
	}
	//#ifdef hackpackpp

	//Calculate the hashes as the windows slides
	//#endif
	for(unsigned int i=0,j=target.length();j<text.length();i++,j++){
		if(hash == target_hash) count++;
		hash = (hash * PRIME) + text[j] - text[i]*pow(PRIME,LENGTH_TARGET);
	}
	//#ifdef hackpackpp
	//don't forget the possible ending point match
	//#endif
	if(hash == target_hash) count++;

	cout << count << endl;

	return 0;
}
