// here instead of maintaining a visited array , we should maintan a distance array /map => need not to maintain visited
//initaially distance between
//:starting and all the remaining nodes is infinity
// for starting node it is = 0

// logic : distance(child)=distance(parent)+1
// we check if a node is assigned distance or not
// if unassigned => not visited => assign distance
// else equivalent to already visited

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

template<typename T>
class graph {
  //using hash map
  map<T , list<T> > adjList;

public:
  graph() {}

  void addEdge(T u, T v, bool bidirectional = true) {
    adjList[u].push_back(v);
    if (bidirectional) adjList[v].push_back(u);
  }

  void printAdjList() {
    for (auto i : adjList) {
      cout << i.first << " ->";
      for (auto j : i.second) cout << j << " ,";
      cout << "\n";
    }
  }

  void singleSourceShortestPath(T source) {
    queue<T> q;
    map<T, int> distance;

    //a parent map : to keep track of parents of diff nodes
    std::map<T, T> parent;

    // initialize all distances = infinity
    for (auto i : adjList)
      distance[i.first] = INT8_MAX;

    // for source node
    q.push(source);
    distance[source] = 0;

    while (!q.empty()) {
      T curNode = q.front();
      cout << curNode << " ";
      q.pop();

      //for the neighbours of current node, find out nodes which are unvisited
      //here neighbour node is equivalent to child node
      for (T neighbour : adjList[curNode]) {
        if (distance[neighbour] == INT8_MAX) {
          q.push(neighbour);
          //visited[neighbour]=true;
          distance[neighbour] = distance[curNode] + 1;
          parent[neighbour] = curNode;
        }
      }
    }

    // printing the distance of all nodes from source node
    for (auto i : adjList) {
      T curNode = i.first;
      cout << "\nDistance of " << curNode << " from " << source << " is :" << distance[curNode];
    }
  }
};

int main(int argc, char const *argv[])
{
  INPUT();
  graph<int> g;
  g.addEdge(0, 1, 1);
  g.addEdge(0, 4, 1);
  g.addEdge(4, 3, 1);
  g.addEdge(1, 4, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 3, 1);
  g.addEdge(1, 3, 1); //(u,v, is bidirectional)
  g.printAdjList();
  cout << "\n\n";

  g.singleSourceShortestPath(0);
  return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
  freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
  freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}