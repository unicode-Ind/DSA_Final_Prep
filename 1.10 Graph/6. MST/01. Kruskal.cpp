#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

class DSU
{
	int *parent;
	int *rank;
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; ++i)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i) {
		return (parent[i] == -1 ? i : parent[i] = find(parent[i]));
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x != y) {
			if (rank[x] > rank[y])
				swap(x, y);

			parent[x] = y;
			rank[y] += rank[x];
		}
	}
};

class Graph
{
	int V;
	vector<vector<int>> edgeList ; // (wt,x,y)
public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int wt) {
		edgeList.push_back({wt, x, y}); // wt in starting so that sorted on based of 1st element , avoid custom comparator
	}

	int Kruskal_mst() {
		sort(edgeList.begin(), edgeList.end());

		//init DSU
		DSU dsu(V);

		int ans = 0;
		for (auto edge : edgeList) {
			int wt = edge[0];
			int u = edge[1];
			int v = edge[2];

			//take edge in mst if it doesnot form a cycle
			if (dsu.find(u) != dsu.find(v)) {
				dsu.unite(u, v);
				ans += wt;
			}

		}

		return ans;
	}


};


int main()
{
	INPUT();

	Graph g(4);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 3, 3);
	g.addEdge(3, 2, 4);
	g.addEdge(2, 0, 2);
	g.addEdge(0, 3, 2);
	g.addEdge(1, 2, 2);

	cout << g.Kruskal_mst();


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}