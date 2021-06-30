/*
Kartik bhaiya gave monu an array 'nums' of n elements and an integer k .Find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k . monu is not good in maths help monu to solve the problem.
Return true if nums[i] = nums[j] and the absolute difference between i and j is at most k,otherwise return false.

Input Format
First line contains integer n as size of array.
Next N lines contains element of array.
Last line contains value of k.

Constraints
None

Output Format
The output will be of the boolean form (true/false).

Sample Input
4
1
2
3
1
3
Sample Output
true
Explanation
None
*/

#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<long long int>& input) {
	unordered_map<long long int, bool> hm;

	int k;
	cin >> k;

	int i = 0;

	for (auto cur : input) {
		if (hm.find(cur) != hm.end() and i - hm[cur] <= k)
			return true;

		hm[cur] = i;
		i++;
	}

	return false;
}

int main() {
	int n;
	cin >> n;


	vector<long long int> input;
	for (int i = 0; i < n; i++) {
		long long int t;
		cin >> t;
		input.push_back(t);
	}

	if (containsDuplicate(input)) {
		cout << "true";
	} else {
		cout << "false";
	}

	return 0;
}

/**/