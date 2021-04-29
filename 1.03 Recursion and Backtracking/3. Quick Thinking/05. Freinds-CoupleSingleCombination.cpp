/*
Given n friends who want to got to  trip on bike
Each can go as singlr or as couple
find no of ways

//sufficient bikes are available
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int combination(int n) {
	// if (n == 0)
	// 	return 0;
	// if (n == 1)
	// 	return 1;
	// if (n == 2)
	// 	return 2;
	if (n < 3)
		return n;

	return 1 * combination(n - 1) + 1 * (n - 1) * combination(n - 2);
	// 1 and valid n-1
	// or 1 and 2nd in (n-1)C1 ways and valid n-2
}

int main()
{
	INPUT();
	cout << combination(3);
	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}