#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);

int nxn = 1000000;
int n;

void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

//logn  , n=max(a,b)
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd( b, a % b );
}

int main()
{
	INPUT();

	ll t = 1;
	cin >> t;

	while (t--) {
		ll a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	}
	return 0;
}

