//https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

// int dx[] = { -1, -1, 1, 1, 2, 2, -2, -2};
// int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void print_board(int (*board)[8]) {
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << setw(3) << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool safe(int x, int y, int (*board)[8]) {
	return ((x >= 0 and x < 8) and
	        (y >= 0 and y < 8) and
	        (board[x][y] == -1)
	       );
}

bool solve_KT(int x, int y, int moves_done, int (*board)[8]) {
	// if (moves_done == 64) //n*n moves done
	// {
	// 	print_board(board);
	// 	return 1;
	// }

	board[x][y] = moves_done++;
	if (moves_done == 64) //n*n moves done
	{
		print_board(board);
		return 1;
	}

	for (int i = 0; i < 8; ++i)
	{
		int nxt_x = x + dx[i];
		int nxt_y = y + dy[i];

		if (safe(nxt_x, nxt_y, board)) {
			if (solve_KT(nxt_x, nxt_y, moves_done , board))
				return 1;
		}
	}

	board[x][y] = -1;

	return false;
}

int main()
{
	INPUT();
	int start_x = 0;
	int start_y = 0;

	int board[8][8];
	memset(board, -1, sizeof board);

	if (!solve_KT(start_x, start_y, 0, board))
		cout << "No solution\n";

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}