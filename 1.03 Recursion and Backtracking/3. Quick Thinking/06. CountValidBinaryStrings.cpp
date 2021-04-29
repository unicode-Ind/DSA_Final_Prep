/*
Count Binry strings of lenght n, with no consecutive 1's
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int valid(int n) {
	if (n < 0)
		return 0;

	if (n == 1)
		return 2;
	if (n == 2)
		return 3;

	return valid(n - 1) + valid(n - 2);

	//valid(n) means all possible strings of length n
	// ---1 => 0 is forced i.e. 1 comes as 01
	//=> --01 => find valid(n-2)

	//---0 => find valid (n-1)

}


int main()
{
	INPUT();
	cout << valid(2);

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}