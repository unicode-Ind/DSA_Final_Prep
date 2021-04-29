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


	bool containsCycle() {
		//DSU logic to check for cycle

		int *parent = new int[V];
		int *rank = new int[V];

		for (int i = 0; i < V; ++i) {
			parent[i] = -1;
			rank[i] = 1;
		}

		//iterate on edgelist
		for (auto edge : edgeList) {
			int u = edge.first;
			int v = edge.second;

			int S1 = findSet(u, parent);
			int S2 = findSet(v, parent);

			if (S1 != S2) {
				unionSet(S1, S2, parent, rank);
			} else {
				return true;
			}
		}

		delete [] parent;
		delete [] rank;
		return false;
	}
};


int main()
{
	INPUT();

	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	cout << (g.containsCycle() ? "cycle" : "no cycle");


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}