/*
Mapping Given 1->A ....... 26->Z

and a number is given eg 1234
what possible strings can be generated

*given not starting with 0

eg 1: 1234
	 1 2 3 4=> ABCD

	 12 3 4 => LCD

	 1 23 4 => AWD

	 1 2 34 =>invalid bcz 36 represent no character

eg 2: 102
	 1 0 2 => not allowed
	 10 2 => allowed
	 1 02 =>not allowed /allowed ? => depeneds how handeled in problem

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void generate_string(char *in, char *out, int i, int j) {
	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	//one digit at time
	int digit = in[i] - '0';
	if (digit != 0) {
		char ch = digit + 'A' - 1;
		out[j] = ch;
		generate_string(in, out, i + 1, j + 1);
	}

	//two digit at a time
	if (in[i + 1] != '\0') {
		int secondDigit = in[i + 1] - '0';
		int num = digit * 10 + secondDigit;

		if (num <= 26 and num >= 10) {
			char ch = num + 'A' - 1;
			out[j] = ch;

			generate_string(in, out, i + 2, j + 1);
		}
	}
}


int main()
{
	INPUT();

	char in[100] = "102"; //=> 10 2 only if 02 is not allowed
	//cin >> in;
	char out[100];

	generate_string(in, out, 0, 0);



	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}