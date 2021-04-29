/*
	Author : Arvinder Singh
*/

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvin/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvin/Desktop/Current/output.txt", "w", stdout);
#endif
}

#define ll long long
#define ar array
//#define PI 3.14159
const double PI = acos(-1);
const long long mod = 1e9 + 7;
#define vint vector<int>
#define vfloat vector<float>
#define pb push_back
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)

int cnt;

pair<int, int> fib (int n) {
	//cnt++;
	if (n == 0)
		return {0, 1};

	auto p = fib(n >> 1);
	int c = p.first * (2 * p.second - p.first);
	int d = p.first * p.first + p.second * p.second;
	if (n & 1)
		return {d, c + d};
	else
		return {c, d};
}

void solve() {
	cin >> n;
	cout << fib(n).first << endl;
	//cout << cnt;

}

int main(int argc, char const *argv[])
{
	FIO
	INPUT();

	ll t = 1;
	cin >> t;

	while (t--)
	{
		solve();

	}
	return 0;
}
