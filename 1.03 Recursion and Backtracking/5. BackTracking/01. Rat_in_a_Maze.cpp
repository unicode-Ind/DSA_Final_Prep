/*
Moves - right /down

1. find path src to dest
2. count no of paths
3. print all possible paths

here we will write for 3rd
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n) {
	if (i == m and j == n) {
		soln[m][n] = 1;

		//print
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		soln[m][n] = 0;

		return true;
	}
	///rat shd be iniside grid
	if (i > m or j > n)
		return false;

	if (maze[i][j] == 'X')
		return false;


	//assume soln exists throught current cell
	soln[i][j] = 1;

	bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
	bool downSuccess  = ratInMaze(maze, soln, i + 1, j, m, n);

	//backtracking
	soln[i][j] = 0;


	if (rightSuccess or downSuccess)
		return true;

	return false;
}


int main()
{
	INPUT();

	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int soln[10][10] = {0};
	int m = 4, n = 4;

	bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);

	if (!ans)
		cout << "No path";


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}