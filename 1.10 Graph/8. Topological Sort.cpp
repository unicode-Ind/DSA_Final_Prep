/*
	1. simple algo. that outputs linear ordering of vertices, such that for every edge (u->v)
	   vertex u comes before vertex in the ordering.
	2. Can be done using slightly modified BFS and DFS
	3. Works only on DAG's (Directed Acyclic Graphs) 
*/

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

  	void addEdge(T u,T v, bool bidirectional=false){
  		adjList[u].push_back(v);
  		if(bidirectional)	adjList[v].push_back(u);
  	}

  	void dfsHelper(T node,map<T, bool> &visited, list<T> &ordering){
  		visited[node]=true;
  		//will call dfs on unvisited neighbours of current node

  		for(T neighbour : adjList[node]){
  			if(!visited[neighbour])
  				dfsHelper(neighbour,visited,ordering);
  		}

  		// add just 1 line for Topological Sort
  		// At this point all the children of curNode have been visited
  		// So we can add current node to list head
  		ordering.push_front(node);
  	}

  	void dfsTopologicalSort(){
  		map<T,bool> visited;
      //NOTE: intially all values arre false (by default) in the  => no need to explicitly set them

  		list<T> ordering; //output

  		for(auto i:adjList){
  			//i is a pair (node,list of nodes)
  			T node=i.first;
  			if(!visited[node])
  				dfsHelper(node,visited,ordering);
  		}

  	// print all the elements in ordering (after T.sort)
  	for(T element : ordering)
  		cout<<element<<" --> ";
  	}


  	void bfsTopologicalSort(){
  		// KAHN's algo
  		// enqueue all vertices with indegree = 0 int queue => also need to maintain indegree
  		map<T,bool> visited;
  		map<T,int> indegree;
  		queue<T> q; // we can use priority queue here if we want to sort acc to a specific criteria (eg. lexiog. sorting)

  		for(auto i: adjList){
  			//i is a pair (node,list of nodes)
  			T curNode =i.first;
  			visited[curNode]=false;
  			indegree[curNode]=0; // start with 0, we will find indegrees later 
  		}

  		//Init indegrees of all nodes
  		for(auto i:adjList){
  			T u=i.first;
  			for (T v:adjList[u])
  				indegree[v]++;
  		}

  		//find all nodes with 0 indegree
  		for(auto i:adjList){
  			T curNode=i.first;
  			if(indegree[curNode]==0)
  				q.push(curNode);
  		}

  		// Start with algorithm

  		while(!q.empty()){
  			// remove front and pop it
  			T curNode=q.front();
  			q.pop();
  			cout<<curNode<<" --> ";

  			// reduce indegree of all neighbours of curNode by 1
  			for(T neighbour: adjList[curNode]){
  				indegree[neighbour]--;

  				if(indegree[neighbour]==0)
  					q.push(neighbour);
  			}
  		}
  	}


   
};

int main(int argc, char const *argv[])
{
	graph<string> g; 
	g.addEdge("English","Programming"); //(u,v, is bidirectional: by default false ,here)
	g.addEdge("Maths","Programming");
	g.addEdge("Programming","HTML");
	g.addEdge("Programming","Python");
	g.addEdge("Programming","Java");
	g.addEdge("Programming","Js");
	g.addEdge("Python","WebD");
    g.addEdge("HTML","CSS");
    g.addEdge("CSS","Js");
    g.addEdge("Js","WebD");
    g.addEdge("Java","WebD");
	g.addEdge("Python","WebD");

	cout<<"using dfs\n";
	g.dfsTopologicalSort();
	cout<<"\nusing bfs\n ";
	g.bfsTopologicalSort();
  
	return 0;
}
