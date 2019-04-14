#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<algorithm>
using namespace std;
#define min(a,b)	((a)<(b)?(a):(b))
#define max(a,b)	((a)>(b)?(a):(b))
#define abs(a)		((a)<0?-(a):(a))
#define mod			1000000007
#define MAX			INT_MAX
#define MIN			INT_MIN
#define ull			unsigned long long
#define ll			long long
#define ul			unsigned long

ll gcd(ll a, ll b) {
	if (!b)
		return a;
	return gcd(b, a%b);
}

ll power(ll x, ll y) {
	if (y == 0)
		return 1;
	ll temp = power(x, y / 2);
	if (y % 2 == 0)
		return temp*temp;
	else {
		if (y > 0)
			return x*temp*temp;
		else
			return (temp*temp) / x;
	}
}
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

void prime_factors_of_n(ull n) {
	int index = 0;
	ull no_of_factors = 1, count = 0;	// no of factors = (a+1)*(b+1)*(c+1)*... a,b,c are primes
	ull prime_fact[100001];
	for (ull i = 2; i*i <= n; i++) {
		count = 0;			// for counting no of facotrs
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
/*
	Distinct pairs of ordered positive integers (a,b) such that their LCM is 
	equal to n

	(2x+1)*(2y+1)*(2z+1)*....
	
*/

int nums[1000001] = { 0 };
int primes[10000];
void sieve(int n) {
	if (n < 2)
		return; // not prime
	cout << "Primes :";
	int index = 0;
	for (int i = 2; i <= n; i++) {
		if (nums[i]) {	// if not prime
			continue;
		}
		cout << i << " "; // prime
		primes[index++] = i;
		for (int j = 2 * i; j <= n; j += i) {
			nums[j] = i; // i is prime factor of j
		}
	}
	// cout << "total primes : " << index << "\n";
	// return nums[n]==0?true:false;
}

// calculate x^y modulo mod

ll big_mod(ll x, ll y)
{
	if (y == 0)
		return 1;
	ll p = big_mod(x, y / 2) % mod;
	p = (p*p) % mod;

	if (y % 2 == 0)
		return p;
	else
		return (x*p) % mod;
}

// if mod is prime then mod inverse is a^-1 = a^(m-2)%mod
ll modular_inverse(ll a) {

	ll g = gcd(a, mod);
	if (g != 1) {
		cout << "inverse doesn't exists!";
	}
	return big_mod(a, mod - 2);
}

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
	cin.tie(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ull n;
	//cin >> n;
	//prime_factors_of_n(n);
	//facotrs_of_n(n);
	//sum_of_divisors_of_n(n);
	//sieve(n);
	//modular_inverse(n);
	//cout << mod_inverse(4, 11);

	return 0;
}
