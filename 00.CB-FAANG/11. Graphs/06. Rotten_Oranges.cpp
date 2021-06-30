/*
Given a 2D array of dimension r*c where each cell in the array can have values 0, 1 or 2 which has the following meaning: 0 : Empty cell 1 : Cells have fresh oranges 2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input Format
The first line of input contains an integer T denoting the number of test cases.
Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the array arr and take r*c more inputs in an array arr.

Constraints
1 <= T <= 100
1 <= r <= 100
1 <= c <= 100
0 <= a[i] <= 2

Output Format
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

Sample Input
1
3 5
2
1
0
2
1
1
0
1
2
1
1
0
0
2
1
Sample Output
2
*/

#include <iostream>
#include<queue>
using namespace std;

int solve(int r, int c, vector<vector<int>> &graph) {
	queue< pair<pair<int, int> , int> > q;
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] == 2) {
				q.push({{i, j}, 0});
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		pair<int, int> co_ord = cur.first;
		int time = cur.second;
		ans = max(ans, time);

		for (int i = 0; i < 4; i++) {
			int x = co_ord.first + dx[i];
			int y = co_ord.second + dy[i];

			if (x >= 0 and x<r and y >= 0 and y < c and graph[x][y] == 1) {
				graph[x][y] = 2;
				q.push({{x, y}, time + 1});
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] == 1) {
				return -1;
			}
		}
	}
	return ans;

}

int main() {

	int y;
	cin >> y;
	while (y--) {
		int r, c;
		cin >> r >> c;

		vector<vector<int>> graph(r, vector<int> (c));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> graph[i][j];
			}
		}

		cout << solve(r, c, graph) << endl;
	}

}

/*
Editorial
X
Rotten Oranges
Time Complexity O(r*c), where r is the row of array and c is column of the array

Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following
meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges
So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot
other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to
rot every orange then simply return -1.

Algorithm: Steps:
1.use Breadth First Search(BFS ) algo.
2.Create an empty Queue.
3.Find all rotten oranges and enqueue them to Queue. Also enqueue a delimiter to indicate the beginning of next time frame.
4.While Queue is not empty do following
5.Do following while delimiter in Queue is not reached
Dequeue an orange from the Queue, rot all adjacent oranges. While rotting the adjacent, make sure that the time
is incremented only once. And the time is not incremented if there are no adjacent oranges.

Dequeue the old delimiter and enqueue a new delimiter. The oranges rotten in the previous time frame lie between the two delimiters.
//If Queue was empty than no rotten oranges left to process
if all arranges could not rot
return -1;
8.otherwise return calculated answer using above algo.
Solution Link :https://ide.codingblocks.com/s/202836
Java Code


import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static int[] arr = { 0, 0, -1, 1 };
    public static int[] arr1 = { 1, -1, 0, 0 };

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t-- > 0) {
            int r = s.nextInt();
            int c = s.nextInt();
            int[][] grid = new int[r][c];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    grid[i][j] = s.nextInt();
                }
            }
            int ans = rotting_orange(grid, r, c);
            System.out.println(ans);
        }
    }

    private static int rotting_orange(int[][] grid, int r, int c) {
        // TODO Auto-generated method stub
        Queue<help> queue = new LinkedList<help>();
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 2) {
                    help put = new help(i, j, 0);
                    queue.add(put);
                }
            }
        }

        int ans = 0;
        while (!queue.isEmpty()) {
            help x = queue.remove();
            int row = x.r;
            int col = x.c;
            int inside = x.inside;
            ans = Math.max(ans, inside);
            for (int i = 0; i < arr.length; i++) {
                int new_row = row + arr[i];
                int new_col = col + arr1[i];
                if (new_row >= 0 && new_row < r && new_col >= 0 && new_col < c && grid[new_row][new_col] == 1) {

                    grid[new_row][new_col] = 2;
                    help put = new help(new_row, new_col, inside + 1);
                    queue.add(put);
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
}
class help {
    int r;
    int c;
    int inside;

    public help(int row, int col, int depth) {
        // TODO Auto-generated constructor stub
        this.r = row;
        this.c = col;
        this.inside = depth;
    }
}


C++ Code
#include <bits/stdc++.h>
using namespace std;

int R, C;

bool issafe(int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}

int rotOranges(vector<vector<int>> &v)
{
    bool changed = false;
    int no = 2;
    while (true) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {

                // Rot all other oranges present at
                // (i+1, j), (i, j-1), (i, j+1), (i-1, j)
                if (v[i][j] == no) {
                    if (issafe(i + 1, j) && v[i + 1][j] == 1) {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1) && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j) && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1) && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }

        // if no rotten orange found it means all
        // oranges rottened now
        if (!changed)
            break;
        changed = false;
        no++;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            // if any orange is found to be
            // not rotten then ans is not possible
            if (v[i][j] == 1)
                return -1;
        }
    }

    // Because initial value for a rotten
    // orange was 2
    return no - 2;
}

// Driver function
int main()
{

    int testCases;
    cin >> testCases;
    while (testCases--) {
        cin >> R >> C;
        vector<vector<int>>v(R, vector<int>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> v[i][j];
            }
        }

        cout << rotOranges(v) << endl;
    }


    return 0;
}
*/