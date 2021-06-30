/*
Given a m*n matrix with the three possible values:

-1 means obstacle
0 means shop
2147483647 means a house
Find nearest shop distance to each house. If it is impossible to reach store from a house , then keep it equal to 2147483647. Obvioulsy ,we can't go beyond an obstacle.
Print the final matrix.
Input Format
The first line contains two integer m and n.
Next m lines contains n integers representing element of the matrix.

Constraints
1<=n,m<=10^2

Output Format
Print the final matrix.

Sample Input
2 2
2147483647 0
2147483647 0
Sample Output
1 0
1 0
Explanation
The nearest store to each house is to its right with distance 1 So ,we change house values to 1.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(1005, vector<int> (1005));

int main() {
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] == 0)
				q.push({i, j});
		}
	}

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		int cur_x = cur.first;
		int cur_y = cur.second;

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 and next_x<r and next_y >= 0 and next_y < c and graph[next_x][next_y] == INT_MAX) {
				graph[next_x][next_y] = graph[cur_x][cur_y] + 1;
				q.push({next_x, next_y});
			}
		}

	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
Editorial
X
Explanation:You can use bfs/dfs to solve this question.
Here i have used bfs to solve this.
Use a boolean vector to avoid visiting same node again.


#include <bits/stdc++.h>
using namespace std;

    void wallsAndGates(vector<vector<int>>& rooms)
    {
        queue<pair<int,int>>q;
        vector<vector<int>>v;
        int r=rooms.size();
        if(r==0)
        {
            return;
        }
        int c=rooms[0].size();

        vector<vector<bool>>visited;

        for(int i=0;i<r;i++)
        {
            vector<bool>vis;
            for(int j=0;j<c;j++)
            {
                vis.push_back(false);
            }
            visited.push_back(vis);

        }

        for(int i=0;i<r;i++)
        {
            vector<int>v1;
            for(int j=0;j<c;j++)
            {
                if(rooms[i][j]==0)
                {
                    q.push(make_pair(i,j));
                    v1.push_back(0);
                    visited[i][j]=true;
                }
                else
                    v1.push_back(-1);
            }
            v.push_back(v1);
        }
        while(!q.empty())
        {
            pair<int,int>p;
            p=q.front();
            q.pop();
            if(p.first+1<r&&!(visited[p.first+1][p.second])&&rooms[p.first+1][p.second]!=-1)
            {
                v[p.first+1][p.second]=v[p.first][p.second]+1;
                q.push(make_pair(p.first+1,p.second));
                visited[p.first+1][p.second]=true;
            }
            if(p.first-1>=0&&!(visited[p.first-1][p.second])&&rooms[p.first-1][p.second]!=-1)
            {
                v[p.first-1][p.second]=v[p.first][p.second]+1;
                q.push(make_pair(p.first-1,p.second));
                visited[p.first-1][p.second]=true;
            }
            if(p.second+1<c&&!(visited[p.first][p.second+1])&&rooms[p.first][p.second+1]!=-1)
            {
                v[p.first][p.second+1]=v[p.first][p.second]+1;
                q.push(make_pair(p.first,p.second+1));
                visited[p.first][p.second+1]=true;
            }
            if(p.second-1>=0&&!(visited[p.first][p.second-1])&&rooms[p.first][p.second-1]!=-1)
            {
                v[p.first][p.second-1]=v[p.first][p.second]+1;
                q.push(make_pair(p.first,p.second-1));
                visited[p.first][p.second-1]=true;
            }
        }

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(rooms[i][j]>0)
                {
                    if(v[i][j]==-1)
                    {
                       v[i][j]=2147483647;
                    }
                    rooms[i][j]=v[i][j];
                }

            }
        }


    }


int main() {
    vector<vector<int> >matrix;
    int m,n,d;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int>v;
        for(int j=0;j<n;j++){
            cin>>d;
            v.push_back(d);
        }
        matrix.push_back(v);
    }
    wallsAndGates(matrix);
 for(int i=0;i<m;i++){
      for(int j=0;j<n;j++)
        cout << matrix[i][j] << " ";
      cout << endl;
    }
    return 0;
}

*/