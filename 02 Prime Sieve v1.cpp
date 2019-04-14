#include<iostream>
using namespace std;
const int MAX = (int)2e8;
int n;
int primes[MAX] = { 0 };	// 0 for prime

void isPrime(int n) {
	primes[0] = primes[1] = 1;	//if n less than 2,  not prime;

	for (int i = 2; i <= n; i++) {
		if (primes[i])	// if not prime, do nothing
			continue;
		for (int j = 2 * i; j <= n; j += i) {
			primes[j] = i;	// i is prime divisor of j
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	isPrime(n);

	cout << "Primes upto n: ";
	for (int i = 0; i <= n; i++) {
		if (!primes[i]) {		// if false, that means prime
			cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}