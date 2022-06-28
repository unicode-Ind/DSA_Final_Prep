/*
https://cses.fi/problemset/task/1628/

You are given an array of n numbers. In how many ways can you choose a subset of the numbers with sum x?

Input
The first input line has two numbers n and x: the array size and the required sum.
The second line has n integers t1,t2,…,tn: the numbers in the array.

Output
Print the number of ways you can create the sum x.

Constraints
1≤n≤40
1≤x≤109
1≤ti≤109
Example

Input:
4 5
1 2 3 2

Output:
3
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long

void INPUT()
{ 
#ifndef ONLINE_JUDGE
  freopen("C:/Users/arvindersingh/Desktop/Current/input.txt", "r", stdin);
  freopen("C:/Users/arvindersingh/Desktop/Current/output.txt", "w", stdout);
#endif
}

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];

    // solution : meet in the middle
    vector<ll> X(1L<< n/2),Y(1<<(n-n/2));
	
	auto generateSubsets = [&](int limit,int offset){
		for(int i= 1; i<= (1<<limit)-1; i++){

			ll sum = 0;
			for(int j = 0;j<32;j++){
				if(i & (1<<j)){
					sum+= v[j+offset]
				}
			}
		}
	}
}


int main(int argc, char const *argv[])
{
    INPUT();
    int t=1;
    //cin>>t;

    for (int i = 1; i <=t; ++i){
        //cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }

    return 0;
}

