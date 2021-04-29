#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int knap(int n, int remainingCap, int *wt, int *prices) {

	if (n == 0 or remainingCap == 0)
		return 0;


	int includeLast = 0;
	int excludeLast = 0;

	if (remainingCap >= wt[n - 1]) {
		includeLast = prices[n - 1] + knap(n - 1, remainingCap - wt[n - 1], wt, prices);
	}

	excludeLast = 0 + knap(n - 1, remainingCap, wt, prices);

	int ans = max(includeLast, excludeLast);

	return ans;

}


int main()
{
	INPUT();

	int n = 4, c = 7;

	int wt[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};

	cout << knap(n, c, wt, prices);

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}