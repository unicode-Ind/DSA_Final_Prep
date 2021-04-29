#include<iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;

template<typename T>
class Graph{
    private:
        int v;
        map<T,list<T>> adjList;

        bool checkCyclic(T curNode, map<T,bool> &visited, T parent){
            visited[curNode]=true;

            for(auto nbr: adjList[curNode]){
                if(!visited[nbr]){
                    bool cycle_mila= checkCyclic(nbr,visited,curNode);
                    if(cycle_mila == true)
                        return true;
                }
                else if(nbr != parent)
                    return true;   // is visited and not parent => cycle
            }
            return false;
        }
    public:
        Graph(){}

        void addEdge(T u,T v,bool bidirec=true){
            adjList[u].push_back(v);
            if(bidirec)
                adjList[v].push_back(u);
        }

        bool isCyclic(){
            map<T,bool> visited; //bt deafault all bool values=fasle

            auto it = adjList.begin();
            auto startNode = it -> first;
            return checkCyclic(startNode,visited,startNode);
        }
};

int main(){
    Graph<int> g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);

    // edge causing cycle;
    g.addEdge(0,2);

    if(g.isCyclic())
        cout<<"g is Cyclic\n";
    else
        cout<<"g is not cyclic";

    Graph<int> g2;

    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(3,4);

    // edge causing cycle;
    //g.addEdge(0,2);

    if(g2.isCyclic())
        cout<<"g2 is Cyclic\n";
    else
        cout<<"g2 is not cyclic";
    
    return 0;    
}