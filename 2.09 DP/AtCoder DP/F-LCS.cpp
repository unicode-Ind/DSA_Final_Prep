#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int nxn = 1000000;
int n;
//vector<int> input(n);
//int input[nxn];

//up left diagonal
int dx[] = {0, -1, -1};
int dy[] = { -1, 0, -1};

int main()
{
	INPUT();
	string a, b;
	cin >> a >> b;

	vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1));
	vector<vector<int>> dir(a.length() + 1, vector<int>(b.length() + 1));

	pair<int, int> ansEndsAt = {1, 1};
	int ansLen = 0;

	for (int i = 1; i <= (int)a.length(); ++i)
	{
		for (int j = 1; j <= (int)b.length(); ++j)
		{
			if (a[i - 1] == b[j - 1]) {
				//diag
				dp[i][j] = 1 + dp[i - 1][j - 1];
				dir[i][j] = 2;
			} else if (dp[i][j - 1] >= dp[i - 1][j]) {
				//up
				dp[i][j] = dp[i][j - 1];
				dir[i][j] = 0;
			} else {
				dp[i][j] = dp[i - 1][j];
				dir[i][j] = 1;
			}

			if (dp[i][j] > ansLen) {
				ansLen = dp[i][j];
				ansEndsAt = {i, j};
			}
		}


	}

	// for (int i = 1; i <= (int)a.length(); ++i)
	// {
	// 	for (int j = 1; j <= (int)b.length(); ++j)
	// 	{
	// 		cout << setw(3) << dp[i][j] << "(" << dir[i][j] << ")  ";
	// 	}
	// 	cout << endl;
	// }

	stack<char> stk;
	int x = ansEndsAt.first;
	int y = ansEndsAt.second;
	//cout << x << " " << y << endl;
	while (ansLen) {

		if (a[x - 1] == b[y - 1]) {
			stk.push(a[x - 1]);
			ansLen--;
		}

		int delX = dx[dir[x][y]];
		int delY = dy[dir[x][y]];

		x += delX;
		y += delY;
	}

	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}



	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}
