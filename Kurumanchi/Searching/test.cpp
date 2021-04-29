void dfs(unordered_map<int,vector<pair<int,int>>> &adj,unordered_map<int,bool> &visited,unordered_map<int,int> &distance,unordered_map<int,int> &parent,int par,int cur,int d){
    visited[cur]=true;
    distance[cur]=distance[par]+d;
    
    auto x=adj[cur];
    for(int it=0;it<x.size();it++){
        if(visited[x[it].first])
            continue;
        parent[x[it].first]=cur;
        dfs(adj,visited,distance,parent,cur,x[it].first,x[it].second);
    }
    
}


int Solution::solve(int A, vector<vector<int> > &B, int C) {
    priority_queue<int> pq;
    
    unordered_map<int,vector<pair<int,int>>> adj;
    unordered_map<int,bool> visited;
    unordered_map<int,int> distance;
    unordered_map<int,int> parent;
    
    
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back{B[i][1],B[i][2]};
        adj[B[i][1]].push_back{B[i][0],B[i][2]};
        
        distance[v]=0;
        visited[v]=false;
    }
    
    parent[1]=1;
    distance[1]=0;
    //visited[1]=true;
    
    dfs(adj,visited,distance,parent,1,0,0);
        
    }
        
    while(C--)
        pq.pop();
        
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    
    return ans;
}
