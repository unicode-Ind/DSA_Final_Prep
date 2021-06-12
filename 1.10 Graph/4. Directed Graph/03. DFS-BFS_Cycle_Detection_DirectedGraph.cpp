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


    //-------DFS------
    bool checkCyclic(T curNode, map<T, int> &visited) {
        visited[curNode] = EXPLORED;

        for (auto nbr : adjList[curNode]) {
            if (visited[nbr] == EXPLORED) {
                return true;
            }
            else if (visited[nbr] == UNVISITED) {
                bool milaKya = checkCyclic(nbr, visited);

                if (milaKya)
                    return true;
            }
        }

        visited[curNode] = VISITED;
        return false;
    }

    bool usingDFS() {
        // map<T,int> visited;
        // auto it = adjList.begin();
        // auto startNode = it -> first;
        // return checkCyclic(startNode,visited);

        map<T, int> visited;
        bool mila = false;
        for (int i = 0; i < V and !mila; i++) {
            if (visited[i] == UNVISITED)
                mila = mila or dfs(i, adj, visited);
        }

        return mila;
    }

    ////////-------------- BFS ----------------
    bool usingBFS(int V) {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int to : adj[i]) {
                indegree[to]++;
            }
        }

        queue<int> q;
        int visitedCnt = 0;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                //visitedCnt++;
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visitedCnt++;
            //cout<<cur<<endl;

            for (int nbr : adj[cur]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                    //visitedCnt++;
                }
            }
        }

        return  !(visitedCnt == V);
    }

public:
    Graph() {}

    void addEdge(T u, T v) { adjList[u].push_back(v); }

    bool isCyclic(int V) {
        //return usingBFS(V);
        return usingDFS();

    }
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

    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);

    // // edge causing cycle;
    // g.addEdge(0,2);

    if (g.isCyclic(N))
        cout << "g is Cyclic\n";
    else
        cout << "g is not cyclic";

    Graph<int> g2;

    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);

    // edge causing cycle;
    //g.addEdge(0,2);

    if (g2.isCyclic())
        cout << "g2 is Cyclic\n";
    else
        cout << "g2 is not cyclic";

    return 0;
}