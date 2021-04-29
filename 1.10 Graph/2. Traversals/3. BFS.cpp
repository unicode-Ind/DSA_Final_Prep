// BFS is an iterative way like level order traversal in trees
//uses queues : to maintain FIFO
// to maintain visited status : we can maintain an array or a hash map
    // if it is graph of int we can use array
    // but for generic type : we need to maintain a map of visited

// Complexity : time - O(v+E) using adj list
                //space O(v)   , as each vertex is pushed and poped from queue only once

#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

template<typename T>
class graph{
    //using hash map
  map<T ,list<T> > adjList;

  public:
  	graph(){}

  	void addEdge(T u,T v, bool bidirectional=true){
  		adjList[u].push_back(v);
  		if(bidirectional)	adjList[v].push_back(u);
  	}

  	void printAdjList(){
  		for(auto i:adjList){
        cout<<i.first<<" ->";
        for(auto j: i.second) cout<<j<<" ,";
        cout<<"\n";
      }
  	}

    void bfs(T source){
      queue<T> q;
      map<T,bool> visited;

      q.push(source);
      visited[source]=true;

      while(!q.empty()){
        T curNode=q.front();
        cout<<curNode<<" ";
        q.pop();

        //for the neighbours of current node, find out nodes which are unvisited
        for(T neighbour : adjList[curNode]){
          if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour]=true;
          }
        }
      }
    }
};

int main(int argc, char const *argv[])
{
	graph<int> g; //graph has 5 vertices from 0 to 4
	g.addEdge(0,1,1);
	g.addEdge(0,4,1);
	g.addEdge(4,3,1);
	g.addEdge(1,4,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(1,3,1); //(u,v, is bidirectional)
	g.printAdjList();
  cout<<"\n\n";

  g.bfs(0);
	return 0;
}