#include<iostream>
using namespace std;
#define ll long long

ll memo[1000];

ll fib_TopDownDP(ll n){
	if(n==0 || n==1) return n;

	if(memo[n]!=-1) return memo[n];

	memo[n]=fib_TopDownDP(n-1)+fib_TopDownDP(n-2);
	return memo[n];
}

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	fill(memo,memo+1000,-1);
	cout<<n<<"th fib no :"<<fib_TopDownDP(n);
	return 0;
}