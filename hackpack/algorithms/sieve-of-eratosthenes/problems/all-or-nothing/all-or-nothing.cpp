#include <bitset>
#include <iostream>
using namespace std;

const size_t N = 10000000;
bitset<N> sieve;
int prefix[N];

int main()
{
	size_t a, b;
	cin >> a >> b;
		
	// Begin at index 1. Starting the sift at index 0 (1) will
	// cause all numbers to be marked composite.
	sieve[0] = 1; // 1 is not prime.
	for(size_t i = 1; i < N; i++)
	{
		// If this number has been marked, do not use it.
		if(sieve[i]) continue;
		// Mark composites of the prime.
		for(size_t j = (i + 1) * (i + 1); j <= N; j += (i + 1))
			sieve[j - 1] = 1;
	}

	// Compute prefix sum of the number of primes.
	size_t count = 0;
	for(size_t i = 0; i < N; i++)
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
