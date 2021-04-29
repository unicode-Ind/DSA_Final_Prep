#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

char word[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void print(int n) {
	if (n == 0)
		return;

	print(n / 10);
	cout << word[n % 10] << " ";
}

int main()
{
	INPUT();

	print(1234);

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}