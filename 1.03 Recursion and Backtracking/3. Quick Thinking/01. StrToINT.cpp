#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int strToInt(char a[], int n) {
	if (n == 0)
		return 0;

	int lastDigit = a[n - 1] - '0';

	int rest = strToInt(a, n - 1);

	return rest * 10 + lastDigit;
}

int main()
{
	INPUT();
	char a[] = "1234";
	int n = strlen(a);

	cout << strToInt(a, n);

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}