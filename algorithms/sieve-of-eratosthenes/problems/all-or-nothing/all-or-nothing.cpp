// #ifdef hackpackpp
#include <bitset>
#include <iostream>
using namespace std;
// #endif

const unsigned int N = 10000001;
bitset<N> sieve;
unsigned int prefix[N];

int main()
{
	// #ifdef hackpackpp
	unsigned int a, b;
	cin >> a >> b;

	// Begin at index 1. Starting the sift at index 0 (1) will
	// cause all numbers to be marked composite.
	// #endif
	sieve[0] = 1; // 0 is not prime.
	sieve[1] = 1; // 1 is not prime.
	for(unsigned int i = 1; i < N; i++)
	{
		// #ifdef hackpackpp
		// If this number has been marked, do not use it.
		// #endif
		if(sieve[i]) continue;
		// #ifdef hackpackpp
		// Mark composites of the prime.
		// #endif
		for(unsigned int j = (i * i); j <= N; j += i)
			sieve[j] = 1;
	}

	// #ifdef hackpackpp
	// Compute prefix sum of the number of primes.
	unsigned int count = 0;
	for(unsigned int i = 0; i < N; i++)
	{
		if (!sieve[i]) count++;
		prefix[i] = count;
	}

	// Remaining numbers != 0 are prime.	
	if(a < 2) cout << prefix[b];
	else cout << prefix[b] - prefix[a - 1];
	cout << endl;
	// #endif

	return 0;
}
