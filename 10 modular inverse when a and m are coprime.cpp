#include<iostream>
using namespace std;
#define ll long long

// if a and m are coprime, then extended euclidian method can be used;
// ax+by=gcd(a,b) => ax+my = 1 => ax = 1(mod m) => x is the modular inverse of a
ll mod_inverse(ll a, ll m) {
	ll m0 = m;
	ll y = 0, x = 1;

	if (m == 1)
		return 0;
	while (a>1)
	{
		ll quotient = a / m;
		ll temp = m;

		m = a%m;
		a = temp;
		temp = y;

		y = x - quotient*y;
		x = temp;
	}

	if (x < 0)
		x += m0;
	return x;
}


int main() {
	ios_base::sync_with_stdio(false);
	ll a, m;
	cin >> a >> m;
	cout << mod_inverse(a,m) << "\n";
	return 0;
}
