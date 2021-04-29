#include<iostream>
#include<list>
#include<map>
#include<queue>
#include <string>
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

      int componenet=1;
  		dfsHelper(source,visited); //actual dfs functon
      cout<<"\n";

      for(auto i:adjList){
        T city=i.first;
        if(!visited[city]){
          dfsHelper(city,visited);
          componenet++;
        }

      }

      cout<<"\nTotal componenets in graph ="<<componenet;
  	}


   
};

int main(int argc, char const *argv[])
{
	graph<string> g; 
	g.addEdge("Amritsar","Jaipur"); //(u,v, is bidirectional: by default true)
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Delhi","Jaipur");
	g.addEdge("Mumbai","Jaipur");
	g.addEdge("Mumbai","Bhopal");
	g.addEdge("Delhi","Bhopal");
	g.addEdge("Mumbai","Bangalore");
  g.addEdge("Delhi","Agra");

  g.addEdge("Andaman","Nicobar");

	g.dfs("Amritsar");
  //g.dfs("Nicobar");
	return 0;
}
