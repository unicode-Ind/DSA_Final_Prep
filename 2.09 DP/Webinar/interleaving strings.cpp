#include<bits/stdc++.h>
using namespace std;

bool interleave(string s1,string s2, string s3,int i,int j,int k){
    if(s1.size()+s2.size()!=s3.size())
        return false;
        //what if one string is exausted - can include extra base cases

    if((s1[i]==s3[k]) && interleave(s1,s2,s3,i+1,j,k+1)) ||((s1[j]==s3[k]) && interleave(s1,s2,s3,i,j+1,k+1))
        return true;
    else
        return false;
}

int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    cout<<interleave(s1,s2,s3,0,0,0);
}
