#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

class Graph
{
	int V;
	int **adjMatrix = NULL;
public:
	Graph(int V) {
		this->V = V;

		adjMatrix = new int* [V];
		for (int i = 0; i < V; ++i)
		{
			adjMatrix[i] = new int [V] {INT_MAX};
		}
	}

	void getGraph() {
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < V; ++j)
			{
				cin >> adjMatrix[i][j];
			}
		}
	}

	void floyadWarshal() {
		for (int k = 0; k < V; ++k)
		{
			for (int i = 0; i < V; ++i)
			{
				if (i == k)
					continue;

				for (int j = 0; j < V; ++j)
				{
					if (j == k)
						continue;

					int dis;
				}
			}
		}
	}


};


int main()
{
	INPUT();
	//ll t=1;
	//cin>>t;

	//while(t--)
	//	solve();

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}