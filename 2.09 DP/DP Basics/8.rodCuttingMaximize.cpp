/*
 a rod of length T is given
 we have price of selling different lengths l<=T
 we have to find optimal length combination to maximize profit

 say we have length 4
 prices : 1 2 3 4
 length : 2 3 2 5

 diff combinations : (3,1)=4, (2,2)=6 , (2,1,1)=7 , (1,1,1,1)=8 -max

 complexity O(L^L) without DP

 			assuming if we have options for all [1,L] lenghts
 			O(L^2) 0r O(n^2) with DP - for ith box we have to call all jth boxes ,j<i
*/
#include <bits/stdc++.h>
#include<vector>
using namespace std;

int maxProfittopDown(int len, vector< pair<int,int> > &v, int *dp){
	if(len==0)
		return 0;

	if(dp[len]!=0)
		return dp[len];

	for(auto i:v){
		if(i.first > len)
			break;
		dp[len]=max(dp[len],i.second+maxProfittopDown(len-i.first,v,dp));
	}
	return dp[len];
}

int maxProfitBottomUp(int len, vector< pair<int,int> > &v){
	if(len<=0)
		return 0;

	int dp[100]={0};

	for(int i=1;i<=len;i++){
		dp[i]=0;
		for(auto j:v){
			if(j.first > i)
				break;
			dp[i]=max(dp[i],j.second+dp[i-j.first]);
		}
	}

	return dp[len];
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	
	while(t--){
		int total_lenght,total_options,in_length,in_price;
		vector< pair<int,int> > v;

		cin>>total_lenght>>total_options;

		for (int i = 0; i < total_options; ++i)
		{
			cin>>in_length>>in_price;
			v.push_back({in_length,in_price});


		}

		int dp[100]={0};
		cout<<maxProfittopDown(total_lenght,v,dp)<<"  ";
		cout<<maxProfitBottomUp(total_lenght,v)<<"\n";
	}
	return 0;
}