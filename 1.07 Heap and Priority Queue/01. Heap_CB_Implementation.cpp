#include <bits/stdc++.h>
#include "../customIO.h"
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

void createMaxHeap(vector<int> &v);           // O(NlogN)
void createMaxHeap_optimised(vector<int> &v); // O(N)
void insert_intoMaxHeap(vector<int> &v);      //O(logN)
void upHeapyfy(vector<int> &v,int idx);      // O(logN)
void downHeapyfy(vector<int> &v,int idx);    // O(logN)
void deletePeak_FromMaxHeap(vector<int> &v);  // O(logN)

int main(int argc, char const *argv[])
{
	INPUT()
	vector<int> heap;
	int n,input;
	cin>>n;

	fo(i,n){
		cin>>input;
		heap.pb(input);
	}

	createMaxHeap(heap); 

	for (std::vector<int>::iterator i = heap.begin(); i != heap.end(); ++i)
		{
			cout<<*
			i<<" ";
		}	
	return 0;	
}


void createMaxHeap(vector<int> &v){
	for (int i = 0; i < v.size(); ++i)
	{
		upHeapyfy(v,i);
	}
}

void createMaxHeap_optimised(vector<int> &v){
	for(int i=v.size()-1;~i;i--)
		downHeapyfy(v,i);
}

void upHeapyfy(vector<int> &v,int idx){
	if(idx==0)
		return;

	int parentIdx= (idx-1)/2; //floor value
	if(v[parentIdx] < v[idx]){
		swap(v[parentIdx],v[idx]);
		upHeapyfy(v,parentIdx);
	}
}

void downHeapyfy(vector<int> &v,int idx){
	int leftidx=2*idx+1;
	int rightidx=2*idx+2;
	if(leftidx>= v.size() && rightidx >=v.size())
		return;

	int largestidx=idx;
	if(leftidx < v.size() && v[leftidx]>v[largestidx])
		largestidx=leftidx;
	if(rightidx < v.size() && v[rightidx]>v[largestidx])
		largestidx=rightidx;

	if(largestidx==idx) 
		return;

	swap(idx,largestidx);
	downHeapyfy(v,largestidx);
}

void insert_intoMaxHeap(vector<int> &v){
	int input;
	cin>>input;

	v.push_back(input);
	upHeapyfy(v,v.size()-1);
}

void deletePeak_FromMaxHeap(vector<int> &v){
	if(v.size()<2){
		v.clear();
		return;
	}

	swap(v[0],v[v.size()-1]);
	v.pop_back();

	downHeapyfy(v,0);
}