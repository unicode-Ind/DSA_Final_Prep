#include <bits/stdc++.h>
using namespace std;
//https://ide.codingblocks.com/s/4399
void buildSegTree(int *tree,int *a,int s,int e,int index){
	if(s==e){
		tree[index]=a[s];
		return;
	}

	int mid=(s+e)/2;
	buildSegTree(tree,a,s,mid,2*index);
	buildSegTree(tree,a,mid+1,e,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
}

int query(int *tree,int *a,int s,int e,int qs,int qe,int index){
	if(qs<=s && qe>=e)
		return tree[index];

	if(qe<s && qs>e)
		return INT_MAX;

	int mid=(s+e)/2;
	int leftans=query(tree,a,s,mid,qs,qe,2*index);
	int rightans=query(tree,a,mid+1,e,qs,qe,2*index+1);
	return min(leftans,rightans);
	
}

void updateNode(int *tree,int ss,int se,int i,int increment,int index){
    //Leaf updateNode
    //Out of bounds - No Overlap
    if(i>se||i<ss){
        return;
    }
    
    //Leaf Node 
    if(ss==se){
        tree[index] += increment;
        return;
    }
    
    //Left and Right - Call 
    int mid = (ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index){
    //Out of bounds 
    if(l>se || r<ss){
        return;
    }
    
    // Leaf Node 
    if(ss==se){
        tree[index] += inc;
        return;
    }
    
    // Left and Right  Call Otherwise 
    int mid = (ss+se)/2;
    
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);
    
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;

    //here we dont have complete overlap case !!! why?
    // say interval [2,4], we cant't return since we need to update leaf nodes corresponding to 2,3,4 also
    
}

int main(int argc, char const *argv[])
{
	int arr[]={1,2,3,-5,4,6};
	int n=sizeof(arr)/sizeof(int);

	int *tree=new int[4*n+1];
	return 0;
}