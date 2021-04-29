/*
Ax+By = c

g= gcd(A,B)
A=ag
B=bg

=> agx + bgx = c
=> ax + by =c/g  (c/g in integer, say k => c = kg)

=> ax + by = k ---1

=> Ax + By = k.g

0r A(x/k) + B(y/k) = g

now AX + BY = g (extended euc algo , X and Y are diff)

=> x=kX and y=KY
solution (x0,y0) of dpphantile eq
*/

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

int main()
{
	INPUT();

	ll t = 1;
	cin >> t;

	while (t--) {
		ll a, b, c;
		cin >> a >> b >> c;

		extendedEuc(a, b);
		ll k = c / GCD;

		if (c % GCD == 0) // solution exist
			cout << k*x << " " << k*y << endl;
		else
			cout << "No solution exist" << endl;
	}
	return 0;
}

/*
INPUT:
2
18 7 3
5 15 3

OUTPUT:
6 -15
No solution exist

*/

