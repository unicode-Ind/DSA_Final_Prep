#include<bits/stdc++.h>
using namespace std;

void INPUT()
{ 
#ifndef ONLINE_JUDGE
  freopen("C:/Users/arvindersingh/Desktop/Current/input.txt", "r", stdin);
  freopen("C:/Users/arvindersingh/Desktop/Current/output.txt", "w", stdout);
#endif
}

bool isVisited(int setOfCities, int cityMask){
    return (setOfCities & (1<<cityMask));
}

int tsp(vector<vector<int>> &dist,int setOfCities, int curCity, int n){
    //base case
    int mask_all_cities_visited = (1<<n)-1;
    if(setOfCities == mask_all_cities_visited){
        return dist[curCity][0];
    }

    int ans = INT8_MAX;

    for(int nxtCity = 0; nxtCity<n; nxtCity++){
        if(isVisited(setOfCities,nxtCity) == false){
            int new_setOfCities = (setOfCities | (1<<nxtCity));
            int subAns = dist[curCity][nxtCity] + tsp(dist,new_setOfCities,nxtCity,n);
            ans = min(ans,subAns);
        }
    }

    return ans;
}

int tsp_dp(vector<vector<int>> &dist,int setOfCities, int curCity, int n,dp){
    //base case
    int mask_all_cities_visited = (1<<n)-1;
    if(setOfCities == mask_all_cities_visited){
        return dist[curCity][0];
    }

    if(dp[setOfCities][curCity] != -1){
        return dp[setOfCities][curCity];
    }

    int ans = INT8_MAX;

    for(int nxtCity = 0; nxtCity<n; nxtCity++){
        if(isVisited(setOfCities,nxtCity) == false){
            int new_setOfCities = (setOfCities | (1<<nxtCity));
            int subAns = dist[curCity][nxtCity] + tsp_dp(dist,new_setOfCities,nxtCity,n,dp);
            ans = min(ans,subAns);
        }
    }

    dp[setOfCities][curCity]=ans;
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> adj;
    int n = adj.size();

    cout<<tsp(adj,1,0,n);

    return 0;
}