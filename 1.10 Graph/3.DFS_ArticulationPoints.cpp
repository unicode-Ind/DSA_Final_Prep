#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define in insert

set<int> articulationPt;
vector<pair<int,int> >bridge;
//set to avoid duplicates

const int N=100005,M=22;

vector<int> gr[N];
int discoveryTime[N],low[N];
int Time=1;

void dfs(int curNode,int parent){
    discoveryTime[curNode] = low[curNode]= Time++;
    
    int no_child=0;
    for(auto child: gr[curNode]){
        //not visited => discovery Time=0
        if(discoveryTime[child]==0){
            dfs(child,curNode);
            no_child++;
            low[curNode] =min(low[curNode], low[child]);

            //art point
            if(parent!=0 && low[child]>=discoveryTime[curNode])
                articulationPt.insert(curNode);

            //bridge
            if(low[child]>discoveryTime[curNode])
                bridge.pb({curNode,child});

        }
        else if(child != parent){
            // edge pointing to visited node => might be backedge (point to other than parent) or en edge child->parent
            // backedge=> cycle
            low[curNode] = min(low[curNode],discoveryTime[child]);
        }
    }

    //separate case for root of dfs as art.Point
    if(parent==0 && no_child>=2)
        articulationPt.insert(curNode);

    return;
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

    Time=1;
    dfs(1,0);

    for(auto x:articulationPt)
        cout<<x<<" ";
    
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

    ans= 3,4
*/