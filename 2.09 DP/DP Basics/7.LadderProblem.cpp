/*
there are n steps n ladder
the person can take max jump of k steps at every step

total how many wats are to reach the top
*/

#include<iostream>
using namespace std;
#define ll long long

int ladderTopDown(int n,int k,int *dp){
	//if(n<0) return 0; already handled in for loop via if condition
	if(dp[n]!=0)
		return dp[n];

	int ways=0;
	for (int i = 1; i <= k; ++i)
	{	
		if(n-i>=0) //or if(n<i) break;
		ways+=ladderTopDown(n-i,k,dp);
	}
	return dp[n]=ways;
}

int ladderBottomUp(int n,int k){
	int dp[100]={1};

	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{	
			if(j>i)
				break;
			dp[i]+=dp[i-j];
		}
	}
	return dp[n]; 
}

int ladderOptimised(int n,int k){
	// from O(k.n) to O(n+k) => approx O(n) if n>>k

	//inspired from bottom-up approach OR (similar to Nth fibonacci using just 2 variables)
	// more likely sliding window type

	//dp[n+1]=dp[n]-dp[n+1- k-1] + dp[n]
	//dp[n+1]= 2*dp[n]-dp[n-k]            for this we dont need loop , thus reducing O(k) factor to O(1)
	int dp[100]={1,1};

	for(int i = 2; i <=k; ++i)
		dp[i]=2*dp[i-1];// dp[i-k-1] will have -ve index => handling necessary
							 // give dp[any -ve index]=0

	for (int i = k+1; i <=n ; ++i)
		dp[i]=2*dp[i-1]-dp[i-k-1];
	
/*
	//or we can do so in one loop
	for (int i = 2; i <=n; ++i)
	{
		if(i<=k)
			dp[i]=2*dp[i-1]; // dp[i-k-1] will have -ve index => handling necessary
							 // give dp[any -ve index]=0
		else
		 dp[i]= 2*dp[i-1] - dp[i-k-1];
	}
*/
	return dp[n]; 

}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int dp[100]={1,1};
		cout<<ladderTopDown(n,k,dp)<<" "<<ladderBottomUp(n,k)<<" "<<ladderOptimised(n,k)<<"\n";
		// O(k.n)
	}
	return 0;
}
