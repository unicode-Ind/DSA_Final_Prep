#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

bool fun1(vector<int> &nums) {
	unordered_set<int> hm;

	int presum = 0;
	for (int i : nums)
	{
		presum += i;
		if (presum == 0)
			return true;

		if (hm.find(presum) != hm.end()) {
			//cout << presum;
			return true;
		} else {
			hm.insert(presum);
		}
	}
	return false;
}

bool fun2(vector<int> &nums) {
	unordered_set<int> hm;

	hm.insert(0);

	int presum = 0;
	for (int i : nums)
	{
		presum += i;

		if (hm.find(presum) != hm.end()) {
			return true;
		} else {
			hm.insert(presum);
		}
	}
	return false;
}


int main()
{
	INPUT();

	int n;
	cin >> n;
	vector<int> input(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}

	cout << fun1(input) << endl;

	cout << fun2(input) << endl;


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}