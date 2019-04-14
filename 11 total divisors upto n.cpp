#include<iostream>
#include<cmath>
using namespace std;
#define ll long long

ll number_of_factors_upto_n(ll n) {
	ll sum = 0;
	//cin >> n;
	ll root = sqrt(n);
	for (ll i = 1; i*i <= n; i++) {
		sum += n / i;
	}
	sum = 2 * sum - root*root;
	//cout << sum << "\n";
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	cout << number_of_factors_upto_n(n) << "\n";
	return 0;
}