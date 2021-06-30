/*
Given an array of n elements, check if the array contains any duplicates.
The function should return true if there are duplicates,otherwise return false.

Input Format
First line contains integer n as size of array.
Next line contains a n integer as element of array.

Constraints
None

Output Format
The output will be of the boolean form.

Sample Input
4
1 2 3 1
Sample Output
true

*/

#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<long long>& input) {
	unordered_map<long long, bool> hm;

	if (input.size() < 2)
		return false;

	for (long long cur : input) {
		if (hm.find(cur) == hm.end())
			hm[cur] = true;
		else
			return true;
	}

	return false;
}

int main() {

	/*
	int n,input;
	cin>>n;
	unordered_map<int,int> hm;
	for(int i=0;i<n;i++){
		cin>>input;

		if(hm[input]){
			cout<<"true";
			return 0;
		}
		hm[input]=1;
	}
	cout<<"false";
	return 0;
	*/
	int n;
	cin >> n;

	long long t;
	vector<long long> input;
	for (int i = 0; i < n; i++) {
		cin >> t;
		input.push_back(t);
	}


	cout << containsDuplicate(input) << endl;
	return 0;
}


/*
Question : Duplicate Values I

Time Complexity: O(n).

Algorithm:A simple approach to solve the problem is by using unordered map as it will keep track whether the element has occured before or not and if the element has occured before,the function will return true,otherwise returns false.

Step 1: Initialize one variable n (int n)and vector ‘nums’ of integer type(vector nums).(n is the number of elements to be pushed in the vector ‘nums’).

Step 2: Make a function containsDuplicates and pass ‘nums’ as parameter(call by refrence).
Ie, containsDuplicates(nums)
Int containsDuplicates(vector& nums)

Step 3: Inside the function declare an unordered map ‘m’ of key of type int and value of type bool.
unordered_map m

Step 4: Loop from i=0 till i less than size of vector nums (i=0;i(m.find(nums[i])==m.end()) and if the element has not occured before then make its value ‘true’ (m[nums[i]]=true), else if the element has occured before return true (return true).

Step 5: If i==nums.size() return false.


#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int>& nums){
    unordered_map<int,bool> m;
    for(int i=0;i<nums.size();i++){
        if(m.find(nums[i])==m.end()){
            m[nums[i]]=true;
        }
        else{
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    if(containsDuplicate(nums)){
        cout << "true"<<endl;
    }
    else{
        cout << "false"<<endl;
    }
    return 0;
}
*/