#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> coins={1,2,5,10,20,50,100,200,500,2000};
//top down
int memo[10000];
int coinChangeTopDownDP(int n){

	// f(n)= min [(n-coins[i])] +1 , for all i such that (n-coins[i])>=0 
	// dp[n]=min[dp[n-coins(i)]] +1 for all i
	if(n==0) return 0;

	if(memo[n]!=0)
		return memo[n];

	int min_coins=INT8_MAX;
	for(int i:coins){
		if(i>n)
			break;
		int cur=1+coinChangeTopDownDP(n-i);
		min_coins=min(min_coins,cur);
	}
	memo[n]=min_coins;
	return memo[n];
}

//bottomUp
int coinChangeBottomUpDP(int n,int *dp){

	if(n==0) 
		return 0;
	if(dp[n]!=0) 
		return dp[n];

	for (int i = 1; i <= n; ++i)
	{	
		int min_coins=INT8_MAX;
		for(int j:coins){
			if(j>i)
				break;
			dp[i]=min(min_coins,coinChangeBottomUpDP(i-j,dp)+1);
		}
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	//memset(memo,0,sizeof(memo));// for top down

	int dp[10000]={0}; //for bottom up

	while(t--){
		int n;
		cin>>n;
		//cout<<n<<"  :"<<coinChangeTopDownDP(n)<<"\n";
		cout<<n<<"  :"<<coinChangeBottomUpDP(n,dp)<<"\n";
	}
	return 0;
}// O(Tn) for both