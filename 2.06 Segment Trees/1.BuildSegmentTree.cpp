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

	for (int i = 1; i <=13; ++i)
	{
		cout<<tree[i]<<" ";
	}

	return 0;
}