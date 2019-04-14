#include<iostream>
using namespace std;
#define ll long long

// we know, a*b = gcd(a,b)*lcm(a,b)

ll gcd(ll a, ll b) {
	if (!b)
		return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return (a*b) / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	ll a, b;
	cin >> a >> b;
	cout << "gcd : " << gcd(a, b) << " lcm : " << lcm(a, b) << "\n";
	return 0;
}