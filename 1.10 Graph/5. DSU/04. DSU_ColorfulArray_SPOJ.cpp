/*
https://www.spoj.com/problems/CLFLARR/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int *parent;

int find(int i) {
	// if (parent[i] != i) {
	// 	parent[i] = find(parent[i]);
	// }

	// return parent[i];
	return ((parent[i] == i) ? i : (parent[i] = find(parent[i])));
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) {
		parent[x] = parent[y] = max(x, y);
	}



}


int main()
{
	INPUT();

	int n, q;
	cin >> n >> q;

	parent = new int[n + 5];
	int l[q], r[q], c[q];
	int res[n + 5] = {};

	for (int i = 0; i < n + 5; ++i)
	{
		parent[i] = i;

		//why not -1 => we can, but we need to modify in unite function this => (parent[x] = parent[y] = max(x, y);) accordingly
	}


	for (int i = 0; i < q; ++i)
	{
		cin >> l[i] >> r[i] >> c[i];
	}

	for (int i = q - 1; ~i; --i)
	{
		//index = rightmost non colored index
		int index = find(l[i]);

		//coloring indices
		while (index <= r[i]) {
			res[index] = c[i];
			unite(index, index + 1);
			index = find(index);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << res[i] << "\n";
	}


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}