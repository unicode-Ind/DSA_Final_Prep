#include <bits/stdc++.h>
#include "../customIO.h"
using namespace std;

/*
	MAX HEAP
void createMaxHeap(vector<int> &v);           // O(NlogN)
void createMaxHeap_optimised(vector<int> &v); // O(N)
void insert_intoMaxHeap(vector<int> &v);      //O(logN)
void upHeapyfy(vector<int> &v,int idx);      // O(logN)
void downHeapyfy(vector<int> &v,int idx);    // O(logN)
void deletePeak_FromMaxHeap(vector<int> &v);  // O(logN)
*/

class Heap{
	vector<int> v;
	int isMinHeap;

	void upHeapyfy(int idx){
		int parentIdx = (idx-1)/2;

		while(idx != 0 and v[parentIdx] < v[idx]){
			swap(v[parentIdx],v[idx]);
			idx = parentIdx;
			parentIdx = (idx-1)/2;
		}
	}

	void downHeapyfy(int idx){

		int leftidx = idx*2+1;
		int rightidx= idx*2+2;

		int largestidx = idx;

		while(leftidx < v.size()){
			if(v[leftidx]>v[largestidx])
				largestidx=leftidx;

			if(rightidx < v.size() && v[rightidx]>v[largestidx])
				largestidx=rightidx;

			if(largestidx == idx){
				break;
			}else{
				swap(v[idx],v[largestidx]);
				idx = largestidx;
				leftidx=2*idx+1;
				rightidx=2*idx+2;
			}
		}
	}

public:

	Heap(){
		v.clear();
		//v.reserve(default_size); //will not expand till 10 elements are added, need to see
		this->isMinHeap = false;
	}

	Heap(int default_size, bool isMinHeap = false){
		v.clear();
		//v.reserve(default_size); //will not expand till ds elements are added, need to see
		this->isMinHeap = isMinHeap;
	}

	Heap(vector<int> nums, bool isMinHeap = false){
		//createMaxHeap_optimised
		v = nums;
		this->isMinHeap = false;

		int lastIdx = v.size()-1;
		int start = (lastIdx-1)/2;

		for(int i=start;~i;i--){
			downHeapyfy(i);
		}

	}

	void insert(int val){
		v.push_back(val);
		upHeapyfy(v.size()-1);
	}

	void print(){
		for(int i:v) cout<<i<<" ";
		cout<<endl;
	}

	void pop(){
		if(!v.empty()){
			swap(v[0],v[v.size()-1]);
			v.pop_back();

			downHeapyfy(0);

		}
	}
};



int main(int argc, char const *argv[])
{
	INPUT();

	/*
	Heap h;
	int n,input;
	cin>>n;

	for (int i = 0; i < n; ++i){
		cin>>input;
		h.insert(input);
	}

	h.print();
	*/

	Heap h2(vector<int>{10,75,15,13,14}); //createMaxHeap_optimised
	h2.print();


	h2.pop();
	h2.print();
	
	return 0;	
}
