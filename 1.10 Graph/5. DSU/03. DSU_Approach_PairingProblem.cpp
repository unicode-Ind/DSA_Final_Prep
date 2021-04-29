/*
	There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input
5 3
0 1
2 3
0 4
Sample Output
6
Explanation
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.


*/

//alternate way : SSC using DFS/BFS  ; ans = nC2 - sum(ways n whic paring is done in same SSC)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

class Graph
{
	int V, E;
	list<pair<int, int>> edgeList; //(u,v)
public:
	Graph(int V, int E = 0) {
		this->V = V;
		this->E = E;
	}

	void addEdge(int u, int v) {
		edgeList.push_back({u, v});
	}

	//dsu logic
	int findSet(int i, int parent[]) {
		if (parent[i] == -1)
			return i;

		//Path Compression Optimization
		return parent[i] = findSet(parent[i], parent);
	}

	void unionSet(int x, int y, int parent[], int rank[]) {

		//rank of node/set = nodes in that set (or height can be used also)
		//uninon by rank attch the samller tree with bigger tree
		//why and how it is optimization ? => so that in smaller tree, we have to update less children in step find

		// we want rank of leader node (ultimate parent) of set

		int S1 = findSet(x, parent);
		int S2 = findSet(y, parent);

		if (S1 != S2) {
			if (rank[S1] < rank[S2]) {
				parent[S1] = S2;
				rank[S2] += rank[S1];
			} else {
				parent[S2] = S1;
				rank[S1] += rank[S2];
			}
		}
	}


	int pairing() {
		//DSU logic to check for cycle

		int *parent = new int[V];
		int *rank = new int[V];

		for (int i = 0; i < V; ++i) {
			parent[i] = -1;
			rank[i] = 1;
		}

		//Logic
		int ans = 0;
		for (auto edge : edgeList) {
			// int u = edge.first;
			// int v = edge.second;

			int s1 = findSet(edge.first, parent);
			int s2 = findSet(edge.second, parent);

			unionSet(s1, s2, parent, rank);
		}

		//here we have structure ready
		//iterare on it
		for (int i = 0; i < V; ++i)
		{
			ans += (V - rank[findSet(i, parent)]);
		}

		return ans / 2;

	}
};


int main()
{
	INPUT();

	int V, E;
	cin >> V >> E;

	Graph g(V, E);

	for (int i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}

	cout << g.pairing();


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}