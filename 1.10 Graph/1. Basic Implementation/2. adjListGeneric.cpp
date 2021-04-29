#include<iostream>
#include<list>
#include<map>
using namespace std;

template<typename T>
class graph{
    //using hash map
  map<T ,list<T> > adjList;

  public:
  	graph(){}

  	void addEdge(T u,T v, bool bidirectional=true){
  		adjList[u].push_back(v);
  		if(bidirectional)
  			adjList[v].push_back(u);
  	}

  	void printAdjList(){
  		for(auto i:adjList){
        cout<<i.first<<" ->";
        for(auto j: i.second)
          cout<<j<<" ,";
        cout<<"\n";
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
	return 0;
}