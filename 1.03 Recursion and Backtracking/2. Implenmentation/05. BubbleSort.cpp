#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void bubble_sort(int a[], int n) {
	if (n == 1)
		return;

	for (int j = 0; j < n - 1; ++j)
	{
		if (a[j] > a[j + 1])
			swap(a[j], a[j + 1]);
	}

	bubble_sort(a, n - 1);
}

void bubble_sort_recursive(int a[], int j, int n) {
	//n controls outer loop
	// j controls inner loop (in equivalent iteratve implementation)

	//since n and j do diff things => 2 base cases
	if (n == 1)
		return;

	if (j == n - 1) {
		//single pass of current array has been done

		//break inner loop
		return bubble_sort_recursive(a, 0, n - 1);
	}
	//recur

	if (a[j] > a[j + 1])
		swap(a[j], a[j + 1]);

	bubble_sort_recursive(a, j + 1, n);

}


int main()
{
	INPUT();
	//ll t=1;
	//cin>>t;

	//while(t--)
	//	solve();

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}