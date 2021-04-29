#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define in insert

const int N=100005,M=22;

vector<int> gr[N];

void bfs(int source,int n,int &ans){
    vector<int> distance(n+1,INT_MAX);
    queue<int> q;

    q.push(source);
    distance[source]=0;

    while(!q.empty()){
        int curNode = q.front();
        q.pop();

        for(auto nbr: gr[curNode]){
            if(distance[nbr]==INT_MAX){
              // dis== int_max => not visited
              distance[nbr]=distance[curNode]+1;
              q.push(nbr);

            } 
            else if(distance[nbr] >= distance[curNode] )
            // if distance(nbr) >= distance(curNode) =>not pointing to parent => backedge
            ans=min(ans, distance[nbr]+distance[curNode]+1);
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

    ans=n+1;
    for(int i=1;i<=n;i++){
        bfs(i,n,ans);
    }

    if(ans== n+1)
    cout<<"No cycle";
    else
    cout<<"Shortest Lenght cycle is :"<<ans;

       
    return 0;
}

/*
Input
5 6
1 2
1 3
2 4
2 5
4 5
5 3

    ans= len =3

*/