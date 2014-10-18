#include <bitset>
#include <iostream>
using namespace std;

const size_t N = 10000000;
bitset<N> sieve;

int main()
{
	// Replace composite numbers with -1
	// Begin at index 1. Starting the sift at index 0 (1) will
	// cause all numbers to be marked composite.
	for(size_t i = 1; i < N; i++)
	{
		// If this number has been marked, do not use it.
		if(sieve[i]) continue;

		// Mark composites of the prime.
		for(size_t j = (i + 1) * (i + 1); j <= N; j += (i + 1))
			sieve[j - 1] = 1;
	}

	// Remaining numbers != 0 are prime.	
	sieve.flip();
	for(size_t i = 0; i < N; i++)
		if(sieve[i]) cout << i + 1 << endl;

	return 0;
}
