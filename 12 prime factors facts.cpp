#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
#define ull unsigned long long

/*
Distinct pairs of ordered positive integers (a,b) such that their LCM is
equal to n

(2x+1)*(2y+1)*(2z+1)*....

*/
double power(ll x, ll y);

void prime_factors_of_n(ull n) {
	int index = 0;
	ull no_of_factors = 1, count = 0;	// no of factors = (a+1)*(b+1)*(c+1)*... a,b,c are primes
	ull prime_fact[100001];
	for (ull i = 2; i*i <= n; i++) {
		count = 0;			// for counting no of factors
		while (n%i == 0)
		{
			prime_fact[index++] = i;
			n /= i;
			count++;
		}
		no_of_factors *= (count + 1);
	}
	if (n > 1) {
		prime_fact[index++] = n;
		count = 1;
	}
	no_of_factors *= (count + 1);
	cout << "Tatal factors/divisors : " << no_of_factors << "\n";
	cout << "Prime factors : ";
	for (int i = 0; i < index; i++)
		cout << prime_fact[i] << " ";
	cout << "\n";
}

void sum_of_divisors_of_n(ull n) {
	ull sum = 1, freq = 0, temp_sum = 1;	// sum = (a^(x+1)-1)/(a-1) * (b^(y+1)-1)/(b-1) * ...
	ull prime;								// a,b,c are primes and x, y, z are frequency
	for (ull i = 2; i*i <= n; i++) {
		prime = 0;
		freq = 0;
		while (n%i == 0)
		{
			prime = i;
			n /= i;
			freq++;
		}

		if (prime) {
			freq++;
			sum *= (power(prime, freq) - 1) / (prime - 1);
		}
	}
	if (n > 1) {
		prime = n;
		freq = 1;
	}
	if (prime) {
		freq++;
		sum *= (power(prime, freq) - 1) / (prime - 1);
	}
	cout << "Divisor sum : " << sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	prime_factors_of_n(n);
	sum_of_divisors_of_n(n);
	return 0;
}

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