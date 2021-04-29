#include <bits/stdc++.h>
using namespace std;

int n,m;


int ans(vector<int> v){
    
    // -2 -1 0 1 2
    //  t  t t f f

    // -3 -2 -1
    // t   t  t

    int pos=-1;
    int l=0,h=n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        //cout<<mid<<endl;
        if(v[mid]>0){
            pos=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }

    return pos;    
}

int main() {
    
    cin>>n;

    vector<int>  v(n);

    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
    }

    cout<<ans(v);

}