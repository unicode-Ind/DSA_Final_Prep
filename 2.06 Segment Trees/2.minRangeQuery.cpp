
#include <bits/stdc++.h>
using namespace std;

void buildTree(int *A,int startingIndexOfA, int endIndexOfA, int *tree, int indexOfTreeArrayToFill){
	//base case : root node of tree array
	if(startingIndexOfA==endIndexOfA)
	{
		tree[indexOfTreeArrayToFill]=A[startingIndexOfA];
		return;
	}

	//recursive calls to left and right subtree
	int mid=(startingIndexOfA+endIndexOfA)/2;
	buildTree(A,startingIndexOfA,mid,tree,2*indexOfTreeArrayToFill);
	buildTree(A,mid+1,endIndexOfA,tree,(2*indexOfTreeArrayToFill)+1);

	tree[indexOfTreeArrayToFill]=min(tree[2*indexOfTreeArrayToFill],tree[2*indexOfTreeArrayToFill+1]);
}

int query(int *tree,int ss,int se,int qs,int qe,int index){
	//ts and te : indices of the array in first call (range related with root node), start and end
				// then	only range related with node under consideration
	//qs and qe : query indces : start and end
	//index : represent current index of a node in segment tree array (tree array)

	//complete overlap
	if(qs<=ss && qe >=se)
		return tree[index];

	//no overlap
	if(qs>se || qe < ss)
		return INT_MAX;

	//partial overlap : call left and right subtree and update ans
	int mid=(ss+se)/2;
	int leftAns=query(tree,ss,mid,qs,qe,2*index);
	int rightAns=query(tree,mid+1,se,qs,qe,2*index+1);
	return min(leftAns,rightAns);
}


int main(int argc, char const *argv[])
{
	int a[]={1,3,2,-5,6,4};
	int n=sizeof(a)/sizeof(int);

	int *tree =new int[4*n+1];
	//size of segement tree : array is max 4n+1 in worst case
	//memset(tree,0,sizeof(tree));
	for (int i = 0; i < sizeof(tree); ++i)
		tree[i]=0;

	buildTree(a,0,n-1,tree,1);
	//starting index of tree is 1 not 0

	//query
	int qs,qe;
	cout<<"\nEnter query range (min range query) :";
	cin>>qs>>qe;

	cout<<query(tree,0,n-1,qs,qe,1);

	return 0;
}