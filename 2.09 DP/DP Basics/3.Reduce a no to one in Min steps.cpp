//for greedy: check 10

#include<iostream>
#include<algorithm> //for fill()
using namespace std;
#define ll long long
#define inf 1e8

//Top down
int memo[1000];
int ReduceNoTopDown(int n){
    if(n==0) return -1;
    if(n==1) return 0;

    if(memo[n]!=-1) return memo[n];

    int q1=inf,q2=inf,q3=inf;

    if(n%3==0) q1=1+ReduceNoTopDown(n/3);
    if(n%2==0) q2=1+ReduceNoTopDown(n/2);
    q3=1+ReduceNoTopDown(n-1);

    memo[n]=min(q1,min(q2,q3));
    return memo[n];
}

//bottom up
int ReduceNoBottomUp(int n,int *dp){


    if(dp[n]!=-1) return dp[n];
    for(int i=4;i<=n;i++){
        int q1=inf,q2=inf,q3=inf;
        if(i%3==0) q1=1+ReduceNoBottomUp(i/3,dp);
        if(i%2==0) q2=1+ReduceNoBottomUp(i/2,dp);
        q3=1+ReduceNoBottomUp(i-1,dp);

        dp[i]=min(q1,min(q2,q3));
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    fill(memo,memo+1000,-1);

    int dp[1000];
    fill(dp,dp+1000,-1);
    dp[1]=0;
    dp[2]=dp[3]=1;

    cout<<"Min steps requred to reduce "<<n<<" to 1 :"<<ReduceNoTopDown(n);
    cout<<"\nMin steps requred to reduce "<<n<<" to 1 :"<<ReduceNoBottomUp(n,dp);

    /*
    int check=1;
    for(int i=0;i<1000;i++)
    {
        if(ReduceNoBottomUp(i,dp)!=ReduceNoTopDown(i))
        {
            cout<<i;
            check=0;
            break;
        }
    }
    cout<<check;
    */
	return 0;
}
