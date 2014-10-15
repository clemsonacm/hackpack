#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	// Create an array with elements 1..N
	const int N = 212;
	int* sieve = new int[N];
	for(int i = 0; i <= N; i++) sieve[i] = i + 1;

	// Replace composite numbers with -1
	// Begin at index 1. Starting the sift at index 0 (1) will
	// cause all numbers to be marked composite.
	for(int i = 1; i < N; i++)
	{
		// If this number has been marked, do not use it.
		if(sieve[i] == -1) continue;

		// Mark composites of the prime.
		for(int j = pow(sieve[i], 2); j <= N; j += sieve[i])
			sieve[j - 1] = -1;
	}

	// Remaining numbers != -1 are prime.	
	for(int i = 0; i < N; i++)
		if(sieve[i] != -1) cout << sieve[i] << endl;

	return 0;
}
