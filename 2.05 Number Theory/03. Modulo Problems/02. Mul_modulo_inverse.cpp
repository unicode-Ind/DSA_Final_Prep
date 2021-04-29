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

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd( b, a % b );
}


ll x, y, GCD;
//logn  , n=max(a,b)
void extendedEuc(ll a, ll b) {
	//base case
	if (b == 0) {
		GCD = a;
		x = 1;
		y = 0;
		return;
	}

	extendedEuc(b, a % b);

	ll curX = y;
	ll curY = x - (a / b) * y;

	x = curX;
	y = curY;
}

ll inverseModulo(ll a, ll m) {
	extendedEuc(a, m);

	if (GCD != 1)
		//inv doesnot exist
		return INT_MAX;

	return (x + m) % m; // x can be -ve
}

int main()
{
	INPUT();

	ll t = 1;
	cin >> t;

	while (t--) {
		ll a, m;
		cin >> a >> m;

		cout << inverseModulo(a, m) << endl;

	}
	return 0;
}

/*
input :
2
18 7
18 8

output:
2
2147483647
*/

