/*
    used for range(a,b)
    where a and b are very big , say a=10^10 and b=10^10+10^5
    =>normal sieve can't be build ,reason: array of order 10^10 not possible (memeory) and TLE also

    *** applicable when |b-a|<=10^6
*/

/*
    IDEA is to use two arrays
    1. Shifted array for (a to b) as (0 to b-a), here a is smallest and b is largest both inclusive
        these represent whether no in range[a,b] are prime or not ut with shifting of indices]
    2. Array renges from 2 to sqrt(b): recall to check prime we need to check till sqtr(n)
        now,we will cross all no's in first array which are the multiples of prime no's in 2'nd array
        => first array is requird segmented sieve

    NOTE: max b=10^12
    in this code , we we impliment for this case instead for sqrt(b) to write a general code
    but we can also alter SIZE=sqrt(b) we we want to compute only till sqrt(b) 
*/

#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000005
#define ll long long

bool sieve[SIZE]={false};
void PrimeSieve(){
    cout<<"\nin 1";
    sieve[0]=sieve[1]=false;
    sieve[2]=true;

    //assume all odd no's are prime
    for(int i=3;i<SIZE;i+=2)
        sieve[i]=true;
    //need to check only odd no's
    //as all odd no's are already checked by mod 2
    for(int i=3;i<SIZE;i+=2){
        if(sieve[i]){
            for(int j=i*i;j<SIZE;j+=i)
                sieve[j]=false;
        }
    }
    
}

bool Segmented_Sieve(ll a,ll b,bool *segSieve){
    PrimeSieve();
    cout<<"\nin2";
    for(ll i=2;i*i<b;i++){
        for(ll j=a;j<=b;j++){ //? j+=i => no, as we are not sure a s multiple of i or not => will give incorrect ans 
            if(sieve[i]){
                if(j==i) //handles overlap (if any)
                    continue;
                if(j%i==0)
                segSieve[j-a]=false; // a is shifted to j-a in segSieve array
            }
        }
    }
}

int main(){
    ll a,b;
    cin>>a>>b;
    bool segSieve[b-a+1];
    memset(segSieve,1,sizeof(segSieve));
    cout<<"set done";
    Segmented_Sieve(a,b,segSieve);

    /*
        To find no of primes in range [a,b]
        int res=1;
        for(ll i=a;i<b;i++)
            res+=(int)segSieve[i-a];

        cout<<res<<"\n";
    */

    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        segSieve[n]==true?cout<<"YES\n":cout<<"NO\n";        
    }
    return 0;
}