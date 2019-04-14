#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

const int MAX = (int)5e8;
int prime[MAX/8];
int mark[MAX >> 5] = { 0 };	// MAX/32	
int n;
int index = 0;

bool check(int x, int pos) {	// check either pos-th bit is 1 or not
	return (bool)(x&(1 << pos));
}

int bit_set(int x, int pos) {	// set pos-th bit to 1
	return x | (1 << pos);
}

void seive_bitwise(int n) {
	int i;
	prime[index++] = 2;
	
	for (i = 3; i*i <= n; i += 2) {
		if (check(mark[i >> 5], i & 31))	// not prime
			continue;						// i & 31 = i % 31

		prime[index++] = i;
		for (int j = i*i; j < n; j += (i << 1))
			mark[j >> 5] = bit_set(mark[j >> 5], j & 31);
	}

	for (; i <= n; i += 2) {
		if (!check(mark[i >> 5], i & 31))
			prime[index++] = i;
	}
}

int main() {
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	seive_bitwise(n);
	cout << "primes upto n: \n";
	for (int i = 0; i < index; i++)
		cout << i+1 << "th\t" << prime[i] << "\n";
	cout << "\n";
	return 0;
}