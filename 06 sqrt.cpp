#include<iostream>
using namespace std;

double sqrt(double n) {
	double low = 0, high = n, mid;
	for (int i = 0; i < 64; i++) {
		mid = (low + high) / 2.0;
		if (mid*mid <= n)
			low = mid;
		else
			high = mid;
	}
	return mid;
}

int main() {
	ios_base::sync_with_stdio(false);
	double n;
	cin >> n;
	if (n >= 0)
		cout << sqrt(n) << "\n";
	else
		cout << "-nan\n";
	return 0;
}