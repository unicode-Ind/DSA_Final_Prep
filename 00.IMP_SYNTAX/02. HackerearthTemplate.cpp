/*logic ------------

*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<bitset>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<stdio.h>
#include<queue>
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007 // 10**9 + 7
#define INF 1e9
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, b, a) for (int i = b; i > a; i--)
#define all(v) v.begin(), v.end()
#define GETCHAR getchar_unlocked
#define pi(n) printf("%d\n",n)
#define pll(n) printf("%lld\n",n)
#define rk() int t; scanf("%d",&t); while(t--)
using namespace std;
const double pi = acos(-1.0);
//freopen("in","r",stdin);
//freopen("out","w",stdout);

const int er[8] = {-1,-1,0,1,1,1,0,-1};
const int ec[8] = {0,1,1,1,0,-1,-1,-1};
const int fr[4] = {-1,1,0,0};
const int fc[4] = {0,0,1,-1};
typedef unsigned long long ull;
typedef long long ll;
typedef long l;
typedef pair<int,int> pii;
typedef vector<int> vec;
typedef vector<pii> vpii;
ll po(ll a,ll p)
{ll ret = 1;while(p){if(p&1)ret = (ret*a)%mod;a=(a*a)%mod;p=p>>1;}return ret%mod;}

int dp[1000003];
int a[1000003];
char c[1000004];
int main(){
	//freopen("7.txt","r",stdin);
    //freopen("7out.txt","w",stdout);
	rk(){
		    CLEAR(dp);
		    CLEAR(a);
    		cin>>c;
			int n=strlen(c); 
			int cnt=0,x,maxi;
    		for(int i=0;i<n;i++){ 
        			if(c[i]=='R'){
            				a[i]=-1;
            				cnt++;
       	 			}
        			else a[i]=1;
    		}
    		maxi=dp[0]=a[0];
    		for(int i=1;i<n;i++){ 
        			dp[i]=max(a[i],a[i]+dp[i-1]);
        			maxi=max(dp[i],maxi);
    		}
    		cout<<maxi+cnt<<endl;
    }
    return 0;
}
