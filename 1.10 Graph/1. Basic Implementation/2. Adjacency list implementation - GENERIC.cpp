#include<bits/stdc++.h>
#include<list>
#include<map>
#include<cstring>
using namespace std;

template <typename T>
class graph
{
	map<T,list<T>> adjList;
public:
	//graph();
	void addEdge(T u, T v,bool bidirectonal=true){
		adjList[u].push_back(v);
		if(bidirectonal) adjList[v].push_back(u);
	}
	void printAdjList(){
		//iterate over map
		for(auto i:adjList){
            cout<<i.first<<" -> ";  //gives key
			for(auto entry:i.second)  //i.second gives a linked list
			//data type determined automatically Or we can use : for(T entry:i.second)
				cout<<entry<<",";
			cout<<endl;
		}
	}
	//~graph();

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
	//since we used mao , output will be sorted (in terms of keys)
	g.printAdjList();
	return 0;
}
