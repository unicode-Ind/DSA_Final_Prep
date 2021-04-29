/*
	USING BFS: if we are reaching a node which is already visited => cycle present !

	NOT as simple   1----0    visited 0,1,3  when it comes to 1,
                    |    |    one of it's negihbour 0 is also visited
                    2    3    => will return true , but no cycle is there !!!

    => we need here to make sure,while checking for neighbours we always skip the parent

                            ********************************

    USING DFS: same thing can be done using dfs (visited parent)

    1-----0
    |     |
   	2-----4
   	\     /
   	 \   /
   	   3------5

   	sequence : 0,1,2,3,5,3
   	from 3 we can go to 2 or 4 ,but parent[3]=2 => we go to 4
   	from 4, parent[4]!=2 => if we go there confirm cycle (even when 0--4 edge is not there !!!) 
			but we have cycle (2-3-4-2)
   										OR
   	from 4, since parent[4]!=0 we can also go => cycle (0-1-2-4-0)

   	EG 2 :			1----0      seq; 0,1,2,3,2,4,2,1,0
                    |       	here (parent && visited) conflict is there (parent[3]=2)
                3---2----4		
                				
    to have cycle : for 3, we have to find some other node such that parent[3]!=node
    => we return false at this step ,as we could not find any other node 
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

  	void addEdge(T u,T v, bool bidirectional=true){
  		adjList[u].push_back(v);
  		if(bidirectional)	adjList[v].push_back(u);
  	}

    bool bfsCycleDetectionUndirected(T source){
      queue<T> q;
      map<T,bool> visited;
      map<T,bool> parent;

      q.push(source);
      visited[source]=true;
      parent[source]=source;

      while(!q.empty()){
        T curNode=q.front();
        q.pop();

        //iterating over the neghbours of curNode leaving parent
        for(T neighbour : adjList[curNode]){
          if(visited[neighbour] && parent[curNode]!=neighbour){
          	// handing parent already visited case
            return true;
          }
          else if(!visited[neighbour]){
          	visited[neighbour]=true;
          	parent[neighbour]=curNode;
          	q.push(neighbour);
          }
        }
      }
      return false;
    }


    bool dfsIsCyclicHelper(T curNode, map<T, bool> &visited, T parent){
    	visited[curNode]=true;
    	for(T neighbour:adjList[curNode]){
    		if(!visited[neighbour]){
    			bool cycleDetected = dfsIsCyclicHelper(neighbour,visited,curNode);
    			// curNode is now parent , as they have parent-neighbour relation
    			// => curNode is parent 
    			if(cycleDetected)
    				return true;
    		}
    		// in this case if neighbour is already visited
    		// but we have to check if neighbour!=parent[curNode]
    		// eg 0-----1    : seq : 0,1,0 (sub-seq : 1,0)
    		else if(parent!=neighbour)
    			return true;
    		// also cheeck on cyclic graph 1-2-3-4-1
    		//for seq : 1,2,3,4
    		// now 4-> 1 && 4 is now parent of 1 (already visited) => cycle
    	}
    	return false;
    }

    bool dfsCycleDetectionUndirected(){
    	map<T, bool> visited;

    	//you can call for finding cycle in every dfs tree
    	for(auto i:adjList){
    		T curNode=i.first;
    		if(!visited[curNode]){
    			bool ans=dfsIsCyclicHelper(curNode,visited,curNode);
    			// every starting node is parent of itself
    			if(ans)
    				return true;
    		}
    	}
    	return false;
    }

};

int main(int argc, char const *argv[])
{
	graph<int> g; //graph has 5 vertices from 0 to 4
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(3,4,1);
	g.addEdge(4,1,1);

	cout<<"\n***  USING BFS   ***\n";

	cout<<"g is :";
	if(g.bfsCycleDetectionUndirected(1))
		cout<<"cyclic\n";
	else
		cout<<"not cyclic\n";

	graph<int> g2;
	g2.addEdge(0,1,1);
	g2.addEdge(0,3,1);
	g2.addEdge(1,2,1); //(u,v, is bidirectional)
	g2.addEdge(3,4,1);
	cout<<"g2 is:";
	if(g2.bfsCycleDetectionUndirected(0))
		cout<<"cyclic\n";
	else
		cout<<"not cyclic\n";


	cout<<"\n\n***  USING DFS   ***\n";
	cout<<"g is :";
	if(g.dfsCycleDetectionUndirected())
		cout<<"cyclic\n";
	else
		cout<<"not cyclic\n";
	cout<<"g2 is:";
	if(g2.dfsCycleDetectionUndirected())
		cout<<"cyclic\n";
	else
		cout<<"not cyclic\n";

 
	return 0;
}