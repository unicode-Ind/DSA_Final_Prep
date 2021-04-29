#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();


bool safePosition(bool board[][100], int row, int col, int n) {
	//since we are placing row-wise => need to check only upper part (below is empty now)

	//check :column
	for (int i = 0; i < row; ++i)
	{
		if (board[i][col])
			return false;
	}

	//check :left diagonal
	int i = row - 1, j = col - 1;
	while (i >= 0 && j >= 0) {
		if (board[i][j])
			return false;
		i--;
		j--;
	}
	//check :right diagonal
	i = row - 1, j = col + 1;
	while (i >= 0 && j < n) {
		if (board[i][j])
			return false;
		i--;
		j++;
	}
	return true;
}

bool NQueen(bool board[][100], int row, int n) {
	//base case
	if (row == n) {
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j])
					cout << "Q";
				else
					cout << "*";
			}
			cout << "\n";
		}
		return true; //in case to get one possible ans (achieved first)
		//return false //to get all possible ans
	}

	//recursive case
	//try every cell in present column for favourable condition
	for (int col = 0; col < n; ++col)
	{
		if (safePosition(board, row, col, n)) {
			board[row][col] = true;
			if (NQueen(board, row + 1, n)) //is this pos suitable if we try to fill next rows
				return true;
		}
		//else (!!! not include here)
		board[row][col] = false;
	}

	return false; // handles case when it is not possible to palce a queen anywhere in row
}

int main() {
	INPUT();
	int n = 4;
	// cin>>n;
	bool board[100][100] = {false};

	NQueen(board, 0, n);
	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}