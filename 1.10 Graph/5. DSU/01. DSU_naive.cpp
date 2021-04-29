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

		return findSet(parent[i], parent);
	}

	void unionSet(int x, int y, int parent[]) {
		int S1 = findSet(x, parent);
		int S2 = findSet(y, parent);

		if (S1 != S2) {
			parent[S2] = S1;
		}
	}


	bool containsCycle() {
		//DSU logic to check for cycle

		int *parent = new int[V];
		for (int i = 0; i < V; ++i)
			parent[i] = -1;

		//iterate on edgelist
		for (auto edge : edgeList) {
			int u = edge.first;
			int v = edge.second;

			int S1 = findSet(u, parent);
			int S2 = findSet(v, parent);

			if (S1 != S2) {
				unionSet(S1, S2, parent);
			} else {
				return true;
			}
		}

		delete [] parent;
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
	//g.addEdge(3, 0);

	cout << g.containsCycle();


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}