#include<iostream>
using namespace std;
#define ll long long
#define m 10000007
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

int main() {
	ios_base::sync_with_stdio(false);
	ll x, y;
	cin >> x >> y;
	cout << big_mod(x, y) << "\n";
	return 0;
}