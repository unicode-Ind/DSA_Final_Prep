#include <iostream>
#include<iomanip>
#include <map>
#include <list>
#include <string>
using namespace std;

template<typename T>
class graph
{
	std::map<T, list<T> > adjList;
public:
	void addEdge(T u, T v,bool bidirectonal=true){
		adjList[u].push_back(v);
		if(bidirectonal) adjList[v].push_back(u);
	}

	void indegree(){
		map<T,int> indegree;
		for(auto i: adjList){
			T curNode=i.first;
			for(T neighbour : adjList[curNode])
				indegree[neighbour]++;
		}
	
		cout<<"\nIndegree :\n"<<setw(15)<<"Vertex"<<setw(15)<<"indegree\n";
		for(auto i:indegree)
			cout<<setw(15)<<i.first<<setw(15)<<i.second<<"\n";

		cout<<"\n";
	}

	void indegreeModified(){
		// for nodes with indeg=0
		map<T,int> indegree;
		map<T ,bool> visited;
		for(auto i: adjList){
			T curNode=i.first;
			for(T neighbour : adjList[curNode]){
				indegree[neighbour]++;
				visited[neighbour]=true;
			}

			for(auto i:adjList){
				T curNode=i.first;
				if(!visited[curNode])
					indegree[curNode]=0; //***  NOTE this STEP   ***
			}
		}
	
		cout<<"\nIndegree :\n"<<setw(15)<<"Vertex"<<setw(15)<<"indegree\n";
		for(auto i:indegree)
			cout<<setw(15)<<i.first<<setw(15)<<i.second<<"\n";

		cout<<"\n";
	}

	void outdegree(){
		map<T,int> outdegree;
		int count;
		for(auto i: adjList){
			T curNode=i.first;
			count=0;
			for(T neighbour : adjList[curNode])
				count++;

			outdegree[curNode]+=count;				
		}
	
		cout<<"\nOutdegree :\n"<<setw(15)<<"Vertex"<<setw(15)<<"Outdegree\n";
		for(auto i:outdegree)
			cout<<setw(15)<<i.first<<setw(15)<<i.second<<"\n";

		cout<<"\n";
	}
	
};

int main(int argc, char const *argv[])
{
	graph<string> g;
	g.addEdge("Putin","Trump",false);
	g.addEdge("Putin","Modi",false);
	g.addEdge("Putin","Pope",false);
	g.addEdge("Modi","Trump",true);
	g.addEdge("Modi","Yogi",true);
	g.addEdge("Yogi","XYZ",false);
	g.addEdge("XYZ","Modi",false);
	g.addEdge("Test","XYZ",false);
	g.addEdge("Test2","Test3",false);

	g.indegree();
	//g.indegreeModified();
	g.outdegree();
	return 0;
}