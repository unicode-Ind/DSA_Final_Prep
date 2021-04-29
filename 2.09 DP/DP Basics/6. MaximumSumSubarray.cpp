//input 1 4 2 3 , ans=29
//greedy check :2 3 5 1 4 ans=50 (not 49)

#include<iostream>
using namespace std;
#define ll long long

int maxSumSubArray(int *arr,int n){
	int dp[100]={0};

	dp[0]=max(arr[0],0);
	
	for (int i = 1; i < n; ++i)
	{	
		int cur=dp[i-1]+arr[i];
		dp[i]=max(cur,0);
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<dp[i]<<" ";
	}cout<<"\n";
	return dp[n-1];
}

//space optimized form :kadane's algorithm
int kadane(int *arr,int n){
	int csum=0;
	int maxSum=INT32_MIN;

	for (int i = 0; i < n; ++i)
	{
		csum+=arr[i];
		maxSum=max(maxSum,csum);
		csum=max(0,csum);
	}
	return maxSum;
}

int main()
{
	//int arr[]={2,3,-4,1,4};
	int arr[]={-2,-3,-4,-1,-4};
	int n=sizeof(arr)/sizeof(int);

	cout<<maxSumSubArray(arr,n)<<"\n";
	cout<<kadane(arr,n)<<"\n";
	return 0;
}
