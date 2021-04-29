#include<iostream>
using namespace std;
#define ll long long

ll fib_TopDownDP(ll n){
    ll dp[1000];
    fill(dp,dp+1000,-1);
	dp[0]=0;
	dp[1]=1;

	for(ll i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	cout<<n<<"th fib no :"<<fib_TopDownDP(n);
	return 0;
}
