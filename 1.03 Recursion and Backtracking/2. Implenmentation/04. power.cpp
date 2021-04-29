#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int powerSlow(int a, int n) {
	//a^n
	if (n == 0)
		return 1;

	return a * power(a, n - 1);
}

int fastPower(int a, int b) {
	if (n == 0)
		return 1;

	int smallAns = fastPower(a, n / 2);
	smallAns *= smallAns;

	if (n & 1)
		return a * smallAns;

	return smallAns;
}

ll power(ll a, ll b)	//a is base, b is exponent
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b % 2 == 1)
		return (power(a, b - 1) * a) % mod;
	ll q = power(a, b / 2);
	return (q * q) % mod;
}


int main()
{
	INPUT();
	//ll t=1;
	//cin>>t;

	//while(t--)
	//	solve();

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}