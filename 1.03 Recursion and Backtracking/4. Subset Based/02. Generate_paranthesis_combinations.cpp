// n means n pairs of () to be used
// n=3 => 5 valid combinations

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void generate_Paranthesis(char *out, int n, int curIdx, int openP, int closeP) {
	if (curIdx == 2 * n) {
		out[curIdx] = '\0';
		cout << out << endl;
		return;
	}

	//opening
	if (openP < n) {
		out[curIdx] = '(';
		generate_Paranthesis(out, n, curIdx + 1, openP + 1, closeP);
	}

	if (closeP < openP) {
		out[curIdx] = ')';
		generate_Paranthesis(out, n, curIdx + 1, openP, closeP + 1);
	}

}


int main()
{
	INPUT();
	int n = 3;
	char out[100];

	generate_Paranthesis(out, n, 0, 0, 0);



	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}