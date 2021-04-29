#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

char keypad[][10] = {"",
                     "",
                     "ABC",
                     "DEF",
                     "GHI",
                     "JKL",
                     "MNO",
                     "PQRS",
                     "YUV",
                     "WXYZ"
                    };

void generate(char *in, char *out, int i, int j) {

	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	int digit = in[i] - '0';

	if (digit == 0 or digit == 1) {
		//handle 123, 0123 like inputs => else no output
		generate(in, out, i + 1, j);
	}

	for (int k = 0; keypad[digit][k] != '\0'; ++k)
	{
		out[j] = keypad[digit][k];
		//fill reamaining
		generate(in, out, i + 1, j + 1);
	}


}

int main()
{
	INPUT();
	char in[100] = "1123";
	//cin >> in;

	char out[100];
	generate(in, out, 0, 0);



	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}