#include<bits/stdc++.h>
using namespace std;

//in log(exp) time for base^exp
int fastPower(int base,int exp){
	if(exp==0) return 1;

	int ans=fastPower(base,exp/2);

	if(exp&1)
		ans=ans*ans*base;
	else
		ans*=ans;

	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int b,e;
		cin>>b>>e;
		cout<<fastPower(b,e)<<"\n";
	}
	return 0;
}