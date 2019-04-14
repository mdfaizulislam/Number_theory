#include<iostream>
#include<cmath>
using namespace std;
const int MAX = (int)1e8;
int n;
bool mark[MAX] = { false };	// false for prime;
int prime[MAX / 2];
int index = 0;

void sieve(int n) {
	int i;
	// prime[i] is going to store true if 
	// if i*2 + 1 is composite.
	prime[index++] = 2;

	for (i = 3; i*i < n; i += 2) {
		if (mark[i/2])			// if not prime, do nothing
			continue;
		prime[index++] = i;		// else it is prime
		for ( int j = i*i; j < n; j += 2*i)
			mark[j/2] = true;		// j is composite of i, i.e. not prime
	}

	for (; i < n; i += 2 ) {
		if (mark[i/2] == false)
			prime[index++] = i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	sieve(n);

	cout << "Primes upto n: ";
	for (int i = 0; i < index; i++) {
		cout << prime[i] << " ";
	}
	cout << "\n";
	return 0;
}