#include<iostream>
using namespace std;

int recursiveLinearSearch(int *a,int n,int key){
    if(n==0)
        return -1;
    
    if(a[0]==key)
         return 0;
    
    int i=recursiveLinearSearch(a+1,n-1,key);
    if(i==-1);
        //return i;
    else
        i=i+1;
    
    return i;
}

//or

int lsearch(int *a,int i,int n,int key){
    if(i==n)
        return -1;

    if(a[i]==key)
        return i;
    
    return lsearch(a,i+1,n,key);
}
int main(int argc, char const *argv[])
{
    int arr[]={4,3,6,8,4,0,4,56,77};
    int n= sizeof(arr)/sizeof(int);

    int key=56;
    cout<<recursiveLinearSearch(arr,n,key);
    return 0;
}
