// O(n*sqrt(n))
#include<iostream>
using namespace std;
const int MAX = (int)2e5;
int n;
int primes[MAX];
bool isPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	int index = 0;
	for (int i = 0; i <= n; i++) {
		//isPrime(i) ? cout << i << " is prime.\n" : cout << i << " is not prime.\n";
		if (isPrime(i))
			primes[index++] = i;
	}
	
	cout << "primes up to n: ";
	for (int i = 0; i < index; i++)
		cout << primes[i] << " ";
	cout << "\n";
	return 0;
}