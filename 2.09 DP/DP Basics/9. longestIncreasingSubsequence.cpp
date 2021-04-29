#include <bits/stdc++.h>
using namespace std;

//O(n^2)
// dp[i]=1+ max[lis(prev states)]

int maxBottomUp(vector<int> &v){
	int dp[100]={1};

	int ans=1;

	for (int i = 1; i < v.size() ; ++i)
	{
		dp[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if(v[j]<=v[i]) // jth element can be absorbrd by i
				dp[i]=max(dp[i], 1+dp[j]);
		}
		ans=max(ans,dp[i]);
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	
	while(t--){
		int n,in;
		cin>>n;

		vector<int> v;
		
		for (int i = 0; i < n; ++i)
		{
			cin>>in;
			v.push_back(in);
		}

		//cout<<maxTopDown(v)<<"  ";
		cout<<"Length of LIS :"<<maxBottomUp(v)<<"\n";
	}
	return 0;
}

/*
input
4
2
3 2
5
3 10 2 1 20
6
50 3 10 7 40 50
10
10 22 9 33 21 50 41 60 80 6



output: 1,3,4,6
*/