/*
Given a graph . Check whether or not the given graph is bipartite or not ?

A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.

Input Format
Single Integer n denoting number of nodes Next n lines contain two integers u and v where there is an edge between u and v.

Constraints
1<-N<=10000

Output Format
Single integer 0 if not bipartite and 1 if bipartite

Sample Input
4
1 3
0 2
1 3
0 2
Sample Output
1
Explanation
{0,2} and {1,3} are two independent sets
*/


#include <bits/stdc++.h>
using namespace std;

class Graph {

	unordered_map<int, list<int>> adjList;
public:
	void addNode(int b) {
		adjList[b] = list<int>();
	}
	void addEdge(int p, int c) {
		adjList[p].push_back(c);
	}

	void print() {
		for (auto i : adjList) {
			cout << i.first << " ->";
			for (auto j : i.second) {
				cout << j << " ";
			}
			cout << endl;
		}
	}

	int bfs(int src) {
		unordered_map<int, int> color;
		queue<int> q;

		color[src] = 1;
		q.push(src);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto child : adjList[cur]) {

				if (color[child] == 0) {
					color[child] = 3 - color[cur];
					q.push(child);
				} else {
					if (color[child] == color[cur])
						return 0;
					//return false;
				}
			}
		}

		return 1;
		// return true;
	}

};

int main() {
	int n;
	cin >> n;

	Graph g;

	int u, v;
	cin >> u >> v;
	g.addEdge(u, v);
	g.addEdge(v, u);

	int src = u;

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g.addEdge(u, v);
		g.addEdge(v, u);
	}

	cout << g.bfs(src);

	return 0;
}

/*
Editorial
X
A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.

Algorithm to check if a graph is Bipartite:
One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem.
Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS).
1. Assign RED color to the source vertex (putting into set U).
2. Color all the neighbors with BLUE color (putting into set V).
3. Color all neighbor’s neighbor with RED color (putting into set U).
4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite)
CODE:

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void dfs(vector<vector<int>>& graph,unordered_map<int,bool> &visited,bool &ans,bool clr,int i)
    {
        visited[i] = clr;
        for(int j=0;j<graph[i].size();j++)
        {
            if(visited.find(graph[i][j])==visited.end())
                dfs(graph,visited,ans,!clr,graph[i][j]);
            else
            {
                if(clr == visited[graph[i][j]])
                    ans = false;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,bool> visited;
        bool ans = true;
        for(int i=0;i<graph.size();i++)
        {
            if(visited.find(i)==visited.end())
                dfs(graph,visited,ans,true,i);
        }
        return ans;
}
int main() {
    int n; cin>>n;
    vector<vector<int>> graph;
    for(int i=0;i<n;i++){
        vector<int> temp(2);
        cin>>temp[0]>>temp[1];
        graph.push_back(temp);
    }
    cout<<isBipartite(graph);
    return 0;
}
*/