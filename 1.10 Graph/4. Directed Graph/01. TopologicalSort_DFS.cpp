#include <iostream>
#include <vector>
#include <stack>
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

	void dfs(T x, unordered_map<T, bool> &visited, stack<T> &outTime)
	{
		visited[x] = true;

		for (auto& i : adj[x])
		{
			if (visited[i] == false)
			{
				dfs(i, visited, outTime);
			}
		}

		outTime.push(x);
	}
public:
	graph() {};
	~graph() {};

	void addEdge(T u, T v) {
		//u->v
		adj[u].push_back(v);
	}

	vector<T> toplogicalSort(T src) {
		vector<T> res;
		stack<T> outTime;
		unordered_map<T, bool> visited;

		dfs(src, visited, outTime);

		while (!outTime.empty()) {
			res.push_back(outTime.top());
			outTime.pop();
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