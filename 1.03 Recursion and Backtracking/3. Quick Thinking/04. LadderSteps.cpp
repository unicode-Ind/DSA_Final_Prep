#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int ladder(int n, int k) {
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += ladder(n - i, k);
	}
	return ans;
}


int main()
{
	INPUT();
	cout << ladder(6, 3);

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}