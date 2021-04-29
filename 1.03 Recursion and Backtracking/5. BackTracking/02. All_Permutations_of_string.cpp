/*
(len)! permuatations

abc => abc,acb,bac,bca, cab,cba

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void permute(char *in, int cur = 0) {
	if (in[cur] == '\0') {
		cout << in << endl;
		return;
	}

	//recusrion
	for (int j = cur; in[j] != '\0'; ++j)
	{
		swap(in[cur], in[j]);
		permute(in, cur + 1);
		swap(in[cur], in[j]);
	}
}


int main()
{
	INPUT();
	char in[] = "abc";

	permute(in, 0);



	// //
	// int visited[strlen(input)]={};
	// fun(input,visited....)

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}