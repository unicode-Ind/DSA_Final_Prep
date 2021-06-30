/*
Ramu is a chess champion in his college but he is bored as he can't participate in chess competition during lockdown. One day he came up with an interesting problem on chess, the problem is:
Given a chess board of order n x m and starting points (s1, s2) and end points (e1, e2). The task to find minimum number of moves required by the Knight to go to the end cell . If it is impossible to reach end cell then print -1.
Print the minimum moves required.

Input Format
The first line contains two integer n and m.
Next line contains four integer s1 , s2 , e1 , e2

Constraints
1<=n,m<=10^2

Output Format
Print a single integer equal to minimum moves required.

Sample Input
4 4
4 2 2 3
Sample Output
1
Explanation
It is easy to see that knight will reach destination in one move only.

***** INPUT : 1 BASED INDEXING *****
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int r, int c, int x_start, int y_start, int x_end, int y_end) {

    if (x_end<0 or x_end>r or y_end<0 or y_end>c) {
        return -1;
    }

    if (x_start<0 or x_end>r or y_start<0 or y_start>c)
        return -1;

    vector<vector<int>> board (r, vector<int> (c, INT_MAX));

    // int board[1005][1005]={};
    // for(int i=0;i<r;i++)
    //     for(int j=0;j<c;j++)
    //         board[i][j]=INT_MAX;

    queue< pair<int, int> >q;
    q.push({x_start, y_start});
    board[x_start][y_start] = 0;

    int dx[] = { -2, -2, 2, 2, 1, -1, 1, -1};
    int dy[] = { 1, -1, 1, -1, 2, 2, -2, -2};

    while (!q.empty()) {
        auto position = q.front();
        q.pop();

        int position_x = position.first;
        int position_y = position.second;

        if (position_x == x_end and position_y == y_end)
            return board[position_x][position_y];

        for (int i = 0; i < 8; i++) {
            int next_x = position_x + dx[i];
            int next_y = position_y + dy[i];

            if (next_x >= 0 and next_x<r and next_y >= 0 and next_y < c and board[next_x][next_y] == INT_MAX) {
                board[next_x][next_y] = board[position_x][position_y] + 1;
                q.push({next_x, next_y});
            }
        }

    }

    return -1;
}

int main() {
    /*
    A chessboard is made up of 64 squares,
    arranged in 8 rows (called ranks - ) and
    8 columns (called files).
    */
    int ranks, files;
    cin >> ranks >> files;

    int x_start, y_start;
    int x_end, y_end;
    cin >> x_start >> y_start;
    cin >> x_end >> y_end;

    cout << solve(ranks, files, x_start - 1, y_start - 1, x_end - 1, y_end - 1);
    return 0;
}

/*
X
Explanation: Run a bfs from source to destination.Maintain a queue,initially it will have src point , while queue is not empty remove the front element from the queue and push all unvisited nodes that can be visited in current knight move to the queue.Maintain a distance value as well , for every node.While pushing a value in queue , update tis distance to parent distance ( the one which pushes the current node)+1.
If destination is visited then return its distance
Else print -1


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>p
class Graph{
private:
    map<pair<int,int>,list<pair<int,int> > >m1;
public:
    void addEdge(int p1,int p2,int n,int m){
        pair<int,int>p;
        p = make_pair(p1,p2);
        if(p2+1<m){
            if(p1-2>=0){
                m1[p].push_back(make_pair(p1-2,p2+1));
            }
            if(p1+2<n){
                m1[p].push_back(make_pair(p1+2,p2+1));
            }
        }
        if(p2+2<m){
            if(p1-1>=0){
                m1[p].push_back(make_pair(p1-1,p2+2));
            }
            if(p1+1<n){
                m1[p].push_back(make_pair(p1+1,p2+2));
            }
        }
        if(p2-2>=0){
            if(p1-1>=0){
                m1[p].push_back(make_pair(p1-1,p2-2));
            }
            if(p1+1<n){
                m1[p].push_back(make_pair(p1+1,p2-2));
            }
        }
        if(p2-1>=0){
            if(p1-2>=0){
                m1[p].push_back(make_pair(p1-2,p2-1));
            }
            if(p1+2<n){
                m1[p].push_back(make_pair(p1+2,p2-1));
            }
        }
        return ;
    }

    int bfs(int s1,int s2,int d1,int d2,int n,int m){
         queue<pair<int,int> >q;
         map<pair<int,int>,bool>visited;
         map<pair<int,int>,int>distance;
         pair<int,int>src = make_pair(s1,s2);
         pair<int,int>dest = make_pair(d1,d2);
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 visited[make_pair(i,j)]=false;
                 distance[make_pair(i,j)]=INT_MAX;
             }
         }
         q.push(src);
         visited[src]=true;
         distance[src]=0;
         while(!q.empty()){
             pair<int,int> Node = q.front();
             q.pop();

             for(auto child : m1[Node]){
                 if(!visited[child]){
                     visited[child]=true;
                     distance[child] = distance[Node] + 1;
                     q.push(child);
                 }
             }
         }
         if(distance[dest]==INT_MAX)
            return -1;
         return distance[dest];
    }

};


int main(){
    //code
    int n,m,s1,s2,d1,d2;

        Graph g;
        cin>>n>>m;
        //Make Graph
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                g.addEdge(i,j,n,m);
            }
        }
        cin>>s1>>s2>>d1>>d2;
        s1--;s2--;d1--;d2--;
        cout<<g.bfs(s1,s2,d1,d2,n,m)<<endl;

    return 0;
}

*/