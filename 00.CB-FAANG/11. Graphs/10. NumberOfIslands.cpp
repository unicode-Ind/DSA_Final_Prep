/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Input Format
First line contains two integers m and n denoting rows and columns of the grid map respectively. Following m lines contains n characters each '1' or '0'.

Constraints
None

Output Format
An integer denoting the number of distinct islands.

Sample Input
4 5
11000
11000
00100
00011
Sample Output
3
Explanation
Self Explanatory
*/

#include<bits/stdc++.h>
using namespace std;

void dfs_helper(vector<vector<char>> &graph, int i, int j, int m, int n) {
	graph[i][j] = '0';

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	for (int shift = 0; shift < 4; shift++) {
		int next_x = i + dx[shift];
		int next_y = j + dy[shift];

		if (next_x >= 0 and next_x<m and next_y >= 0 and next_y < n and graph[next_x][next_y] == '1') {
			dfs_helper(graph, next_x, next_y, m, n);
		}
	}
}

int dfs(vector<vector<char>> graph, int m, int n) {
	int groups = 0;
	//vector<vector<int>> visited(1005,vector<int> (1005,false));


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == '1') {
				groups++;
				dfs_helper(graph, i, j, m, n);
			}
		}
	}
	return groups;
}

int main()
{
	int m, n;
	cin >> m >> n;

	vector<vector<char>> graph(m, vector<char> (n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	cout << dfs(graph, m, n);
}

/*
Editorial
X
No of islands Approach :- It is a variation of the problem “Counting the number of connected components of an undirected graph”. Algorithm:- Traverse each index(r, c) of the given 2D grid. Check if the value at grid[r][c] is 1. At first the count of islands is set to the number of ones in the grid, considering each 1 as an island while UnionFind is initialized.. Traverse the grid again, traversing each index(i,j). If the value is 1, set grid[r][c] to 0, making grid[r][c] as visited. Check all 4 neighbours of grid[r][c] i.e:-

Upper neighbour(r - 1, c) Lower neighbour(r + 1,c) Left neighbour(r, c -1) Right neighbour(r, c + 1)

If any of grid[r][c]’s neighbours is equal to 1 then take its union with that neighbour to group the connected components together i.e neighbouring 1’s and islands count is reduced to the actual number of islands as described in the problem statement.

Complexity Analysis:- Time complexity:- Initializing UnionFind will take O(mn) time and processing L positions will take a total of O(L) time, taking O(1) time for each union. So total time will be O(mn + L). Space complexity:- O(m*n) as taken by UnionFind data structure.

Solution link:- https://ide.codingblocks.com/s/212219
*/