/*
    we can implement this using array of list OR a hash map
    here we will use array of list
*/

#include<iostream>
#include<list>
#include<vector>
using namespace std;

class graph{
    int v;
    list<int> *l;

  public:
  	graph(int v){
  		this->v=v;
  		l=new list<int>[v];
  	}

  	void addEdge(int u,int v, bool bidirectional=false){
  		l[u].push_back(v);
  		if(bidirectional)
  			l[v].push_back(u);
  	}

  	void printAdjList(){
  		for (int i = 0; i < v; ++i)
  		{
  			cout<<i<<" ->";
  			//l[i] is alinked list
  			for (int vertex:l[i])
  			{
  				cout<<vertex<<" ,";
  			}
  			cout<<"\n";
  		}
  	}
};

int main(int argc, char const *argv[])
{
	graph g(5); //graph has 5 vertices from 0 to 4
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