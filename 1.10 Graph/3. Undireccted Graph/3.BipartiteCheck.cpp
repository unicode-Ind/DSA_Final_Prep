#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define in insert

const int N=100005,M=22;

vector<int> gr[N];
int visited[N]={};
bool isBipartite=true;

void dfs(int curNode,int parent, int color){
   visited[curNode]=color;

   for(auto child: gr[curNode]){
       if(visited[child]==0){
           dfs(child,curNode, 3-color);
       }
       else if(child!= parent && color == visited[child]){
          //child!= parent => backedge => cycle
          //color == visited[child] => odd length cycle =>not bipartite

          isBipartite= false; 
       }
   }
}

int main(int argc, char const *argv[])
{
    int i,j,k,n,m,ans=0,cnt=0,sum=0;

    cin>>n>>m; //nodes, edges
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        gr[u].pb(v);
        gr[v].pb(u);
    }

    dfs(1,0,1);

    if(isBipartite) cout<<"Bipartite";
    else cout<<"Not Bipartite";
    
    return 0;
}

/*
Input
5 5
1 2
2 3
3 1 
3 4
4 5

    ans=not

5 5
1 2
2 3
4 1 
3 4
4 5

    ans=yes
*/