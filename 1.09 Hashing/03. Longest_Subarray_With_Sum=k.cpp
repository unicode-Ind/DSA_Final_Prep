#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int fun1(vector<int> &nums, int k) {
	unordered_map<int, int> hm;

	int presum = 0;
	int ans = 0;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		presum += nums[i];
		if (presum == k) {
			ans = max(ans, i + 1);
		} else if (hm.find(presum - k) != hm.end()) {
			ans = max(ans, i - hm[presum - k]);
		}

		//crutial
		if (hm.find(presum) == hm.end()) {
			hm.insert({presum, i});
		}
	}
	return ans;
}

int fun2(vector<int> &nums, int k) {
	unordered_map<int, int> hm;
	hm.insert({0, -1});

	int presum = 0;
	int ans = 0;
	for (int i = 0; i < (int)nums.size(); i++)
	{
		presum += nums[i];

		if (hm.find(presum - k) != hm.end()) {
			ans = max(ans, i - hm[presum - k]);
		}

		//crutial
		if (hm.find(presum) == hm.end()) {
			hm.insert({presum, i});
		}
	}
	return ans;
}


int main()
{
	INPUT();

	int n, k;
	cin >> n >> k;
	vector<int> input(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}

	/*
		hashmap :  key : prefix sum
				value  : fisrt occurrencr of that prefix sum
	*/

	cout << fun1(input, k) << endl;

	cout << fun2(input, k) << endl;


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}