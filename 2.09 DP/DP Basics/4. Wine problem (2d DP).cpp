//input 1 4 2 3 , ans=29
//greedy check :2 3 5 1 4 ans=50 (not 49)

#include<iostream>
using namespace std;
#define ll long long

int wineProblemTopDown(int *arr,int i,int j,int year,int (*dp)[100]){
	if(i>j)
		return 0;
	//year can also be calculated as year=N-(j-i) 

	if(dp[i][j]!=0)
		return dp[i][j];

	int fromStarting=arr[i]*year+ wineProblemTopDown(arr,i+1,j,year+1,dp);
	int fromEnding=arr[j]*year+ wineProblemTopDown(arr,i,j-1,year+1,dp);

	return dp[i][j]=max(fromStarting,fromEnding);
}

int wineProblemBottomUp(int *arr,int n){
	int dp[10][10]={0};

	int year=n;
	for(int i=0;i<n;i++)
		dp[i][i]=arr[i]*year;


	for (int i = n-2,add=1; ~i; --i,++add)
	{
		year--;
		for (int row=0; row<=i; row++)
		{	
			int op1=dp[row][row+add-1]+arr[row+add]*year;
			int op2=dp[row+1][row+add]+arr[row]*year;
			dp[row][row+add]=max(op1,op2);
		}
	}

	/*
	// just to view internal values of dp array
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}cout<<"\n";
	*/
	return dp[0][n-1];
}

int main()
{
	int arr[]={2,3,5,1,4};
	int n=sizeof(arr)/sizeof(int);

	int dp[100][100]={0};

	cout<<wineProblemTopDown(arr,0,n-1,1,dp)<<"\n";
	cout<<wineProblemBottomUp(arr,n);
	return 0;
}
