#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();


class Graph
{
	int V;
	vector<pair<int, int>> *adjList ; // u - > (v,wt)
public:
	Graph(int V) {
		this->V = V;
		adjList = new vector<pair<int, int>>[V];
	}

	void addEdge(int x, int y, int wt) {
		adjList[x].push_back({y, wt});
		adjList[y].push_back({x, wt});
	}

	int prim_mst() {

		//init min heap
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

		//visited array , denotes whether node is included in MST
		bool *visited = new bool[V] {0};
		int ans = 0 ;

		//begin
		pq.push({0, 0}); // wt, node

		while (!pq.empty()) {
			//pick out edge with min wt

			auto best = pq.top();
			pq.pop();

			int to = best.second;
			int wt = best.first;

			if (visited[to])
				continue; //discard edge

			visited[to] = true;
			ans += wt;

			//add new new edges in queue (active edges)
			for (auto x : adjList[to]) {
				if (visited[x.first] == false) {
					pq.push({x.second, x.first});
				}
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

	cout << g.prim_mst();


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}