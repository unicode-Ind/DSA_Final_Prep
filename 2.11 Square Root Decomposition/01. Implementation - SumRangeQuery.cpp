#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void build(const vector<int>& nums, vector<int>& blocks) {
	int n = nums.size();
	int rn = sqrt(n);

	int blockIdx = -1;
	for (int i = 0; i < n; ++i)
	{
		if (i % rn == 0)
			blockIdx++;

		blocks[blockIdx] += nums[i];
	}

	// for (int i : blocks)
	// 	cout << i << " ";
	// cout << endl;
}

int rangeQuery(const vector<int>& nums, vector<int>& blocks, int qs, int qe) {
	int ans = 0;
	int n = nums.size();
	int rn = sqrt(n);

	while (qs <= qe and qs % rn != 0) {
		ans += nums[qs++];
	}


	// 0 1 2 | 3 4 5 | 6 7 8 | 9 0 0
	// |   |   |   |   |   |

	//qs+rn-1 == qe or qs + rn <= qe
	while (qs + rn <= qe) {
		ans += blocks[qs / rn];
		qs += rn;
	}

	while (qs <= qe)
		ans += nums[qs++];

	return ans;
}

void updatePoint(vector<int>& nums, vector<int>& blocks, int idx, int val) {
	int n = nums.size();
	int rn = sqrt(n);

	blocks[idx / rn] += (val - nums[idx]);
	nums[idx] = val;
}

int main()
{
	INPUT();
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	//build blocks
	int rn = sqrt(n);
	vector<int> blocks(ceil(sqrt(n)), 0);
	build(nums, blocks);

	//queries
	//updatePoint(nums, blocks , 2, 16);
	for (int i : blocks)
		cout << i << " ";
	cout << endl;
	cout << rangeQuery(nums, blocks, 0, 5);

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
10
4 1 6 3 7 19 2 21 20 2
*/
