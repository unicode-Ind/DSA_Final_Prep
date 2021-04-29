/*
	DIJKSTRA'S Shortest Path algo
	-This is efficient implimentation of algo using set and adjList (out of various ways) 
	-which works in O(e log(v))
	-using adjMatrix is not very time efficient

	-To find shortest path b/w any 2 nodes
	-works for weighted graphs ,both directional and undirectional
		(for unweighted we have bfs)
	-graph must have no negative weight cycle 

	- to find min distance : 
		.array :linear search O(n)
		. p.queue/set O(log(n)) - we will not use p.queue (why?)
	
	STEP 1:
	- distance[source,source]=0 and rest=infinity (initially)
	-distance[node]=dstance[parent]+edge weight
	STEP 2:
	-node with min distance (using 

	set)
*/

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

  	void addEdge(T u,T v,int dis bool bidirectional=false){
  		adjList[u].push_back(v);
  		if(bidirectional)	adjList[v].push_back(u);
  	}

  	   
};

int main(int argc, char const *argv[])
{
	graph<string> g; 
	g.addEdge("Amritsar","Delhi",1);
	g.addEdge("Amritsar","Jaipur",4);
	g.addEdge(0,4,1);
	g.addEdge(4,3,1);
	g.addEdge(1,4,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(1,3,1); //(u,v, is bidirectional)
	g.printAdjList();
  cout<<"\n\n";
	return 0;
}