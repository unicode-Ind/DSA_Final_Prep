//Recursive implimentation
// need to maintain visited information : array or map

// easy implimentation
// can't find shortest distance using dfss 
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

  	void dfsHelper(T node,map<T, bool> &visited){
  		//whenever come to a node , mark it visited
  		visited[node]=true;
  		cout<<node<<" ";

  		//try to find out a node which is neighbour ofcurrent node and not yet visited
  		for(T neighbour : adjList[node]){
  			if(!visited[neighbour])
  				dfsHelper(neighbour,visited);
  		}
  	}

  	void dfs(T source){
  		map<T,bool> visited;
      //NOTE: intially all values arre false (by default) in the  => no need to explicitly set them

  		dfsHelper(source,visited); //actual dfs functon
  	}


   
};

int main(int argc, char const *argv[])
{
	graph<int> g; //graph has 5 vertices from 0 to 4
	g.addEdge(0,1); //(u,v, is bidirectional: by default true)
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(2,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(5,3);
	g.dfs(0);
	return 0;
}

//time complexity : O(v+e) for adj list  and O(v^2) for adj matrix
//space complexity: O(v)