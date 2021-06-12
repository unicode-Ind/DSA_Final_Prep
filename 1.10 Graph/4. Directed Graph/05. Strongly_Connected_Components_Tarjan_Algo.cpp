#include<iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;

#define UNVISITED 0;
#define EXPLORED 1;
#define VISITED 2;

template<typename T>
class Graph {
private:
    int v;
    map<T, list<T>> adjList;

public:
    Graph() {}

    void addEdge(T u, T v) { adjList[u].push_back(v); }


};

int main() {
    Graph<int> g;

    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; ++i)
    {
        int from, to;
        cin >> from >> to;
        g.addEdge(from, to);
    }



    return 0;
}