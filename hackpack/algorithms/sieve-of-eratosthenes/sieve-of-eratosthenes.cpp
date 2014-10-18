#include <cmath>
#include <iostream>
using namespace std;

const unsigned int N = 10000000;
bool* sieve = new bool[N];

int main()
{
	// Replace composite numbers with -1
	// Begin at index 1. Starting the sift at index 0 (1) will
	// cause all numbers to be marked composite.
	for(unsigned int i = 1; i < N; i++)
	{
		// If this number has been marked, do not use it.
		if(sieve[i]) continue;

		// Mark composites of the prime.
		for(unsigned int j = (i + 1) * (i + 1); j <= N; j += (i + 1))
			sieve[j - 1] = true;
	}

	// Remaining numbers != -1 are prime.	
	for(unsigned int i = 0; i < N; i++)
		if(!sieve[i]) cout << i + 1 << endl;

	return 0;
}
