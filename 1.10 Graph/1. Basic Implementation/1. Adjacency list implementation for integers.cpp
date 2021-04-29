#include<iostream>
#include<list>
using namespace std;

class graph
{
	int v; //no of vertices
	list<int> *l; //pointer to list of integers
public:
	graph(int v=5){
		//we can make a dynamic array of linked list
		this->v=v;
		l=new list<int>[v]; //an array of size v ,each object is a LL of int type
	}
	void addEdge(int u,int v,bool bidirectional=true){
		l[u].push_back(v);
		if(bidirectional) l[v].push_back(u);
	}

	void printAdjList(){//not useful, just to see contents
		//iterate over all array elements, and for every array/pos print the corresponding LL
		for(int i=0;i<v;i++){
            cout<<i<<" -> ";
			//l[i] is alinked list
			for(int vertex: l[i])
				cout<<vertex<<", ";

			cout<<endl;
		}
	}
	//~graph();

};

int main()
{
	graph g(5); //graph has 5 vertices from 0 to 4
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.printAdjList();

	return 0;
}
