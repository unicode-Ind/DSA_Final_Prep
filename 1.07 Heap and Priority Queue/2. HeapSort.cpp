#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define fo(i,n) for(int i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define vint vector<int>
#define vfloat vector<float>
#define pb push_back

const long long mod=1e9;
#define PI 3.14159
//const double PI=acos(-1); 

void createMaxHeap_optimised(vector<int> &v);// O(N)
void downHeapyfy(vector<int> &v,int idx);    // O(logN)
void heapSort(vector<int> &v);               //O(NlogN)
int heapSize;

int main(int argc, char const *argv[])
{
	vector<int> heap;
	int n,input;
	cin>>n;

	fo(i,n){
		cin>>input;
		heap.pb(input);
	}

	heapSort(heap); 

	for(int i:heap)
		cout<<i<<" ";	
	return 0;	
}

void createMaxHeap_optimised(vector<int> &v){

	cout<<"in create\n";
	for(int i=v.size()-1;~i;i--){
		cout<<"in create loop :"<<i<<"\n";
		downHeapyfy(v,i);
	}
	cout<<"out create loop"<<"\n";
}

void downHeapyfy(vector<int> &v,int idx){
	int leftidx=2*idx+1;
	int rightidx=2*idx+2;
	if(leftidx>= heapSize && rightidx >=heapSize)
		return;

	int largestidx=idx;
	if(leftidx < heapSize && v[leftidx]>v[largestidx])
		largestidx=leftidx;
	if(rightidx < heapSize && v[rightidx]>v[largestidx])
		largestidx=rightidx;

	if(largestidx==idx) 
		return;

	swap(idx,largestidx);

	cout<<"inside loop downHeapyfy :"<<idx<<endl;
	downHeapyfy(v,largestidx);
}

void heapSort(vector<int> &v){
	heapSize=v.size();
	createMaxHeap_optimised(v);

	cout<<"created"<<"\n";
	
	for (int i = v.size()-1;i>0; --i)
	{
		swap(v[0],v[i]);
		heapSize--;
		downHeapyfy(v,0);
	}
}