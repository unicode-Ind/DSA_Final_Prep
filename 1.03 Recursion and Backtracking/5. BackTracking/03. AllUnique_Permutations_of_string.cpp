/*
(len)! permuatations

abc => abc,acb,bac,bca, cab,cba

anwer =< (unique, lexiographically sorted)

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

set<string> ans;

void permute(char *in, int cur = 0) {
	if (in[cur] == '\0') {
		ans.insert( string(in));
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
	char in[] = "aba";

	ans.clear();
	permute(in, 0);

	for (auto cur : ans)
		cout << cur << endl;



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