#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();
#define vvint vector<vector<int>>
#define vint vector<int>
#define vbool vector<bool> v
int nxn = 100005;

void dfs(int node, const vector<vector<int>> &gr, vector<bool> &visited, vector<int> &dp) {
	visited[node] = true;
	int extra = 0;

	for (int child : gr[node]) {
		if (!visited[child]) {
			dfs(child, gr, visited, dp);
		}
		extra = max(extra, dp[child]);
	}

	dp[node] = 1 + extra;
}

int solve(int n, int m, vvint &gr) {
	vector<int> dp(n, 0); //length of longest path starting at node i

	vector<bool> visited(n, false);

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		//int extra = 0;
		if (!visited[i]) {
			dfs(i, gr, visited, dp);
			ans = max(ans, dp[i]);
		}

	}

	// int ans = 0;

	// for (int i = 0; i < n; ++i)
	// {
	// 	ans = max(ans, dp[i]);
	// }

	// for (int i : dp)
	// 	cout << i << " ";
	// cout << endl;

	return ans;
}

int main()
{
	INPUT();
	int n, m;
	cin >> n >> m;

	vector<vector<int>> gr(n, vector<int>());
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;

		gr[x - 1].push_back(y - 1);
	}

	cout << solve(n, m, gr) - 1;
	//solve gives no of nodes in path => eddges = nodes-1

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}