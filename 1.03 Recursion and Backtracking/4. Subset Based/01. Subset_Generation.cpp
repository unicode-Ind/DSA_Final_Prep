// subset / subsequeance generation => can be non-continous

//subarray => continous

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void generateSubseq(char *in, char *out, int i, int j) {

	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;;

		return;
	}

	//include current
	out[j] = in[i];
	generateSubseq(in, out, i + 1, j + 1);

	//exclude current
	generateSubseq(in, out, i + 1, j);

}


int main()
{
	INPUT();

	char in[] = "abc";
	char out[10];

	generateSubseq(in, out, 0, 0);



	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}

