#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);

void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

ll fastModExpo(ll a, ll b, ll m) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (a * res) % m;

		b = b >> 1;
		a = (a * a) % m;
	}
	return res;
}

int main()
{
	INPUT();

	ll t = 1;
	cin >> t;

	while (t--) {
		ll a, b, m;
		//a^b mod m
		cin >> a >> b >> m;
		cout << fastModExpo(a, b, m) << endl;
	}
	return 0;
}

