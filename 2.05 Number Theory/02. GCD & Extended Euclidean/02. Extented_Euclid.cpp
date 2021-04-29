#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);

int nxn = 1000000;
int n;

void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvin/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvin/Desktop/Current/output.txt", "w", stdout);
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

	cout << x << " " << y << endl;
}

int main()
{
	INPUT();

	ll t = 1;
	cin >> t;

	while (t--) {
		ll a, b;
		cin >> a >> b;
		// cout << gcd(a, b) << endl;
		extendedEuc(a, b);

		//gcd(a,b)= ax+by
		// the x and y are :
		cout << x << " " << y << endl;
	}
	return 0;
}

