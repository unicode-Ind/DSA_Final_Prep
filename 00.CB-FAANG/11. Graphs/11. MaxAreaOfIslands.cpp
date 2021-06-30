/*
Some people have been infected with COVID-19 in Mukesh's locality. Since the virus spreads extremely fast, Mukesh wants to be in the safest group so as to stay away from the infected people.
Since most people in Mukesh's locality are smart and follow social distancing, they are safe.
Give a grid of size m×n, where each cell denotes a house in Mukesh's locality. 0 denotes that the people in that house are infected with Corona Virus and 1 indicates, they are safe.
2 houses are said to be in the same group if they share a common edge and both have the same number in their cell. Mukesh wants to find out the largest group that is safe from Corona Virus. Help him out.

Input Format
First line contains two integers m and n, m representing number of rows and n representing number of columns. Next m lines contains n integers each of 0's and 1's representing the gird map.

Constraints
The length of each dimension in the given grid does not exceed 50.

Output Format
An integer representing maximum area or 0 if not possible.

Sample Input
5 5
1 1 0 0 0
1 0 0 0 1
1 0 0 0 1
0 0 1 1 1
1 1 1 1 1
Sample Output
10
Explanation
Self explanatory
*/

#include<bits/stdc++.h>
using namespace std;

void dfs_helper(vector<vector<int>> &graph, int i, int j, int m, int n, int &cur_area) {
	graph[i][j] = 0;
	cur_area++;

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	for (int shift = 0; shift < 4; shift++) {
		int next_x = i + dx[shift];
		int next_y = j + dy[shift];

		if (next_x >= 0 and next_x<m and next_y >= 0 and next_y < n and graph[next_x][next_y] == 1) {
			dfs_helper(graph, next_x, next_y, m, n, cur_area);
		}
	}
}

int dfs(vector<vector<int>> graph, int m, int n) {
	int max_area = 0;
	int cur_area = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				cur_area = 0;
				dfs_helper(graph, i, j, m, n, cur_area);
				max_area = max(cur_area, max_area);
			}
		}
	}
	return max_area;
}

int main()
{
	int m, n;
	cin >> m >> n;

	vector<vector<int>> graph(m, vector<int> (n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	cout << dfs(graph, m, n);
}

/*
Editorial
X
Max Area Of Island(Depth First Search)

Intuition:- Find the area of each connected shape in the grid then take maximum of all.

Algorithm:-
Stack will be used to explore the land squares(where grid[i][j] == 1) and boolean matrix seen[ ][ ] is used to keep track of already visited land squares. The area here will be the total number of squares explored in that connected shape.


For every starting land square that has not been visited, explore 4 directions around it that are not present in seen[ ][ ] or that are not visited yet.
Add those land squares into the stack, and mark them visited by adding them into the seen[ ][ ] matrix.
Here dr[ ] and dc[ ] arrays are used as 4 directions that are to be explored for every land square, i.e (i + 1)(j), (i - 1)(j), (i)(j - 1), (i)(j + 1) respectively.
A counter shape is used to keep the count of squares visited during exploration which accounts for the area of that connected shape.
Run max on shape to get the maximum possible area of the island.


Time Complexity:- O(Num rows * Num of col) i.e iterating over each grid[i][j] once.
Space Complexity:- O(Num rows * Num of col) i.e space used by seen and stack.




import java.util.Scanner;
import java.util.Stack;

public class Main {
public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

    int m = s.nextInt();
    int n = s.nextInt();
    int[][] grid = new int[m][n];
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j stack = new Stack<>();
                    stack.push(new int[]{r0, c0});
                    seen[r0][c0] = true;
                    while (!stack.empty()) {
                        int[] node = stack.pop();
                        int r = node[0], c = node[1];
                        shape++;
                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if (0 <= nr && nr < grid.length &&
                                    0 <= nc && nc < grid[0].length &&
                                    grid[nr][nc] == 1 && !seen[nr][nc]) {
                                stack.push(new int[]{nr, nc});
                                seen[nr][nc] = true;
                            }
                        }
                    }
                    ans = Math.max(ans, shape);
                }
            }
        }
        return ans;
    }

}


*/