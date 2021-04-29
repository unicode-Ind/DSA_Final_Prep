/*
Given 1 to N snakes and ladder board, start and end of all snakes and ladders.
find out min no of dice thrown to win the game (every time preferred no on dice)
No on dice : 1 to 6
*/

//APPLICATION of Single Source Shortest Path

/*
ladders and snakes form connection between nodes  => equivalent neighbours

NOTE : (1) It is unweighted graph : Because the cost is same (every dice throw) to reach any node (currently at v : possible transitions ={ v+1 , v+2 , ...... ,v+6})
	   (2) Directed graph : fixed direction for ladders and snakes
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


    int bfs(T source, T destination){
      queue<T> q;
      map<T,int> distance;

      //a parent map : to keep track of parents of diff nodes
      std::map<T, T> parent;

      // initialize all distances = infinity
      for(auto i:adjList)
        distance[i.first]=INT8_MAX;

      // for source node
      q.push(source);
      distance[source]=0;

      while(!q.empty()){
        T curNode=q.front();
        //cout<<curNode<<" ";
        q.pop();

        
        for(T neighbour : adjList[curNode]){
          if(distance[neighbour]==INT8_MAX){
            q.push(neighbour);
            
            distance[neighbour]=distance[curNode]+1;
            parent[neighbour]=curNode;
          }
        }
      }

      //printing path
      // You can reach destination and go backwards : as we have already stored the parent
      T temp=destination;
      while(temp!=source){
      	cout<<temp<<" <- ";
      	temp=parent[temp];
      }
      cout<<source<<"\n";

      return distance[destination];
    }
};

int main(int argc, char const *argv[])
{
	int board[50]={0};
	// board[currrent]=jump
	board[2]=13; // ladder from 2 to 15 => jump of 13
	board[5]=2;  // postive jump== ladder
	board[9]=18;
	board[18]=11;
	board[17]=-13; // negative jump == snake
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;

	graph<int> g;
	//graph construction : add pairs )u ,v)
	// board is 6*6
	for (int u= 0; u <= 36; ++u)
	{
		//at every node, you can throw a dice
		for (int dice = 1; dice <= 6; ++dice)
		{
			int v=u + dice + board[u+dice];

			g.addEdge(u,v,false); // unidirectional
		}
	}

	cout<<"\nMin Moves :"<<g.bfs(0,36);
	// we can also make starting point =1 and path will not change

	return 0;
}