//https://leetcode.com/problems/subarray-sum-equals-k/

/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Input Format
First line contains input N.
Next line contains a single integer k
Third contains N space separated integers denoting the elements of the array.

Constraints
1<= N <=100000

Output Format
print Number of subarrays having sum exactly equal to k

Sample Input
4
0
0 0 0 0
Sample Output
10
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(vector<int> input, int k) {
	int n = input.size();
	unordered_map<int, int> hm; //<prefixSum, freuency of prefix sum till that index>

	int prefixSum = 0;
	int ans = 0;
	hm[prefixSum]++;

	for (int i = 0; i < n; i++) {
		prefixSum += input[i];

		if (hm.find(prefixSum - k) != hm.end())
			ans += hm[prefixSum - k];

		hm[prefixSum]++;
	}

	return ans;


}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];

	cout << solve(input, k) << endl;
	return 0;
}