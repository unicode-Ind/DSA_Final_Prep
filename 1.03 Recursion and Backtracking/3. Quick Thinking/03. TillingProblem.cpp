#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int tilling(int n) {
	if (n < 0)
		return 0;
	if (n <= 3)
		return 1;

	return tilling(n - 1) + tilling(n - 4);

}


int main()
{
	INPUT();

	cout << tilling(4);
	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}