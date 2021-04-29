#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);

const int nxn = 1000000;
int n;
//vector<int> input(n);
//int input[nxn];

void read(vector<int> input);
void read(int *input);
void solve();

vector<bool> isPrime(nxn, false);
void sieve() {
	isPrime[2] = true;

	for (int i = 3; i < nxn; i += 2)
		isPrime[i] = true;

	for (int i = 3; i < nxn; i += 2)
	{
		if (isPrime[i]) {
			for (ll j = i * (ll)i; j < nxn; j += i)
			{
				isPrime[j] = 0;
			}
		}
	}
}

int main()
{
	ll t = 1;
	cin >> t;

	sieve();

	while (t--) {
		solve();
	}
	return 0;
}

void solve() {
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; ++i)
	{
		if (isPrime[i])
			cout << i << " ";
	}
	cout << endl;

}

void read(vector<int> input) {
	input.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
}
void read(int *input) {
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
}