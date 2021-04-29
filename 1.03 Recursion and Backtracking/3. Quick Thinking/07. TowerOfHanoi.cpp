#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void toh(int n, char src, char aux, char dest) {
	if (n == 0)
		return;

	toh(n - 1, src, dest, aux);
	cout << "Move " << n << " from " << src << " to " << dest << endl;
	toh(n - 1, aux, src, dest);
}

int main()
{
	INPUT();

	toh(3, 'A', 'B', 'C');

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}