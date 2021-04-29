#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

template<typename T>
class graph {
	//using hash map
	map<T , list<pair<T, int>> > adjList;

public:
	graph() {}

	void addEdge(T u, T v, int weight, bool bidirectional = true) {
		adjList[u].push_back({v, weight});
		if (bidirectional)	adjList[v].push_back({u, weight});
	}



	void dijkstra(T src) {
		unordered_map<T, int> dist;

		//Set all distance to infinity
		for (auto j : adjList) {
			dist[j.first] = INT_MAX;
		}

		//Make a set to find a out node with the minimum distance
		set<pair<int, T> > s;

		dist[src] = 0;
		s.insert(make_pair(0, src));

		while (!s.empty()) {

			//Find the pair at the front.
			auto p =   *(s.begin());
			T node = p.second;

			int nodeDist = p.first;
			s.erase(s.begin());


			//Iterate over neighbours/children of the current node
			for (auto childPair : adjList[node]) {

				if (nodeDist + childPair.second < dist[childPair.first]) {


					//In the set updation of a particular is not possible
					// we have to remove the old pair, and insert the new pair to simulation updation
					T dest = childPair.first;
					auto f = s.find( make_pair(dist[dest], dest));
					if (f != s.end()) {
						s.erase(f);
					}

					//Insert the new pair
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest], dest));

				}

			}
		}
		//Lets print distance to all other node from src
		for (auto d : dist) {

			cout << d.first << " is located at distance of  " << d.second << endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	INPUT();
	graph<int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);

	g.dijkstra(1);
	return 0;
}

void INPUT() {
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}