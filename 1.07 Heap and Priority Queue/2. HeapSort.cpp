#include <bits/stdc++.h>
#include "../customIO.h"
using namespace std;

/*
	MAX HEAP
*/

class HeapSort{
	vector<int> v;
	int heapSize;

	void downHeapyfy(int idx){

		int leftidx = idx*2+1;
		int rightidx= idx*2+2;

		int largestidx = idx;

		while(leftidx < heapSize){
			if(v[leftidx]>v[largestidx])
				largestidx=leftidx;

			if(rightidx < heapSize && v[rightidx]>v[largestidx])
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

	void createMaxHeap_optimised(vector<int> nums){
		//createMaxHeap_optimised
		this->v = nums;
		
		//logic
		int lastIdx = v.size()-1;
		int start = (lastIdx-1)/2;

		for(int i=start;~i;i--){
			downHeapyfy(i);
		}

		print();

	}

public:

	HeapSort(vector<int> nums){
		//createMaxHeap_optimised(nums);
		heapSize = nums.size();
		//int lastIdx = heapSize-1;

		
		//logic: craete heap
		v = nums;
		int lastIdx = v.size()-1;
		int start = (lastIdx-1)/2;

		for(int i=start;~i;i--){
			downHeapyfy(i);
		}

		// deletion

		while(heapSize > 1){
			swap(v[0],v[heapSize-1]);
			heapSize--;
			downHeapyfy(0);
		}

	}

	void print(){
		for(int i:v) cout<<i<<" ";
	}

};



int main(int argc, char const *argv[])
{
	INPUT();
	HeapSort h(vector<int>{10,75,15,13,14,-1}); //createMaxHeap_optimised
	h.print();
	
	return 0;	
}
