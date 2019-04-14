#include<iostream>
using namespace std;
#define ll long long
#define m 10000007

ll gcd(ll a, ll b) {	// a*b = gcd(a,b)*lcm(a,b) 
	if (!b)
		return a;
	return gcd(b, a%b);
}

// calculate x^y modulo m
ll big_mod(ll x, ll y) {
	if (y == 0)
		return 1;
	ll p = big_mod(x, y / 2) % m;
	p = (p*p) % m;

	if (y % 2 == 0)
		return p;
	else
		return (x*p) % m;
}

// if mod is prime then mod inverse is a^-1 = a^(m-2)%mod
ll modular_inverse(ll a) {

	ll g = gcd(a, m);
	if (g != 1) {
		cout << "inverse doesn't exists!";
	}
	return big_mod(a, m - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	ll a;
	cin >> a;
	cout << modular_inverse(a) << "\n";
	return 0;
}
