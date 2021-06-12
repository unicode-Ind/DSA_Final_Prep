#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;


void INPUT();

int nxn = 1000000;
int n;
//vector<int> input(n);
//int input[nxn];

template<class T>
class graph
{
	map<T, vector<T>> adj;
	unordered_map<T, int> indegree;


public:
	graph() {};
	~graph() {};

	void addEdge(T u, T v) {
		//u->v
		adj[u].push_back(v);
		indegree[v]++;
	}

	vector<T> toplogicalSort(T src) {
		vector<T> res;

		queue<T> q;
		//init
		for (auto pr : adj) {
			T cur = pr.first;
			if (indegree[cur] == 0)
				q.push(cur);
		}

		//bfs
		while (!q.empty()) {
			T cur = q.front();
			q.pop();

			res.push_back(cur);

			for (T nbr : adj[cur]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0)
					q.push(nbr);
			}
		}

		return res;
	}

};

int main()
{
	INPUT();

	graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	auto out = g.toplogicalSort(0);
	for (auto i : out)
		cout << i << " ";

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}