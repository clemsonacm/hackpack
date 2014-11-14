#include <iostream>
#include <bitset>
using namespace std;

const unsigned int N = 10000001;

int main()
{
	unsigned int cases = 0;
	unsigned int expected;
	unsigned int a, b;
	while(cin >> expected >> a >> b)
	{
		cases++;
		bitset<N> sieve;
		unsigned int prefix[N];
		sieve[0] = 1;
		sieve[1] = 1;
		for(unsigned int i = 1; i < N; i++)
		{
			if(sieve[i]) continue;
			for(unsigned int j = (i * i); j <= N; j += i)
				sieve[j] = 1;
		}

		unsigned int count = 0;
		for(unsigned int i = 0; i < N; i++)
		{
			if(!sieve[i]) count++;
			prefix[i] = count;
		}

		if(a < 2) a = 0;
		else a = prefix[a - 1];
		b = prefix[b];
		cout << "Test #" << cases << ":\t";
		if((b - a) == expected) { cout << "Passed."; }
		else cout << "Failed. Expected " << expected << "; got " << b - a << endl;
		cout << endl;

		if(cin.eof()) break;
	}

	return 0;
}
