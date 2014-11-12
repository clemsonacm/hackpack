#include <bitset>
#include <iostream>
using namespace std;

const unsigned int N = 10000000;
bitset<N> sieve;
unsigned int prefix[N];

int main()
{
	unsigned int a, b;
	cin >> a >> b;
		
	// Begin at index 1. Starting the sift at index 0 (1) will
	// cause all numbers to be marked composite.
	sieve[0] = 1; // 1 is not prime.
	for(unsigned int i = 1; i < N; i++)
	{
		// If this number has been marked, do not use it.
		if(sieve[i]) continue;
		// Mark composites of the prime.
		for(unsigned int j = (i + 1) * (i + 1); j <= N; j += (i + 1))
			sieve[j - 1] = 1;
	}

	// Compute prefix sum of the number of primes.
	unsigned int count = 0;
	for(unsigned int i = 0; i < N; i++)
	{
		if (!sieve[i]) count++;
		prefix[i] = count;
	}

	// Remaining numbers != 0 are prime.	
	if(a < 2) cout << prefix[b - 1];
	else cout << prefix[b - 1] - prefix[a - 2];
	cout << endl;

	return 0;
}
