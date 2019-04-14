#include<iostream>
using namespace std;
#define ll long long
// calculate x^y
double power(ll x, ll y) {	
	if (y == 0)
		return 1;
	double temp = power(x, y / 2);
	if (y % 2 == 0)
		return temp*temp;
	else {
		if (y > 0)
			return x*temp*temp;
		else
			return (temp*temp) / x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout << sizeof(double) << " " << sizeof(ll) << "\n";
	cout << DBL_MAX << " " << LLONG_MAX << "\n";
	ll x, y;
	cin >> x >> y;
	cout << power(x, y) << "\n";
	return 0;
}