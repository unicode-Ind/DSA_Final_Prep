/*
Find the kth largest element in an unsorted array.
Note:It is the kth largest element in the sorted order, not the kth distinct element.

Input Format
First line contains integer n as size of array. Second line contains the value of k. Third line contains n integers as element of array.

Constraints
1 ≤ k ≤ array's length.

Output Format
Print the kth largest element as output.

Sample Input
6
2
3 2 1 5 6 4
Sample Output
5
*/

#include <bits/stdc++.h>
#include<queue>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();


int main()
{
	INPUT();
	int n, k;
	cin >> n >> k;

	int num;
	priority_queue<int, vector<int>, greater<int>> pq;
	int cs = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		if ((int)pq.size() < k) {
			pq.push(num);
		} else if (num > pq.top()) {
			pq.pop();
			pq.push(num);
		}
	}
	cout << pq.top();

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}

/*
Editorial
X
Question : Find kth Largest Number

Time Complexity : Overall time complexity is O(n).

Algorithm: Here using priority queue (max heap) we will solve the problem of finding kth largest number and the steps to solve the problem are given below:

Step 1: Initialize one variable n(int n) , variable k (int k) and vector ‘arr’ of integer type(vector arr).(n is the number of elements to be pushed in the vector ‘arr’ and k is the kth largest number to find in the vector ‘arr’).

Step 2: Make a function findKthLargest and pass ‘arr’ and k as parameters.
findKthLargest(arr,k).
Int findKthLargest(vector& nums,int k).

Step 3: Make a priority queue(max heap) inside the function namely p and initilize a variable count initially whose value =0;
priority_queue,greater>p.
Int count=0

Step 4: loop from i=0 till size of the vector nums (i<nums.size()).

Step 5: Inside the loop check if value of count is less than k if count is less than k then push the element present at nums[i] in the priority queue p and increment the count variable and i pointer as well.

Step 6: Else check if value of count is greater or equal to k and also check if element present at nums[i] is greater the element present at top of priority queue p then pop the top most element from the queue p and push nums[i] into the queue and increment the i pointer.

Step 7: When i=nums.size() return the top most element present in the queue p and print it.
Return p.top()


#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>>p;
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(count<k)
        {
            p.push(nums[i]);
            count++;
        }
        else
        {
            if(nums[i]>p.top())
            {
                p.pop();
                p.push(nums[i]);
            }
        }
    }
    return p.top();
}
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr;
    int a;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    cout<<findKthLargest(arr,k);
}

*/