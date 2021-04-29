#include<iostream>
using namespace std;
#define SIZE 1000005

bool sieve[SIZE]={false};

bool PrimeSieve(){
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
    
}//O(nloglog(n)) - approx linear

int main(){
    int t;
    cin>>t;
    PrimeSieve();
    while(t--){
        int n;
        cin>>n;

        sieve[n]==true?cout<<"YES\n":cout<<"NO\n";        
    }
    return 0;
}