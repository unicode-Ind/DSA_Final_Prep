/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Input Format
First line contains single integer n.
Second line contains n integers Ai.

Constraints
1<=n<=1e5 1<=Ai<=1e6

Output Format
Single line containing single integer

Sample Input
6
100 4 200 1 3 2
Sample Output
4
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 0;
	vector<pair<int, bool>> input;
	unordered_map<int, int> hm;

	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;

		input.push_back({in, false});
		hm[in] = i;
	}

	//int number=0;

	for (int i = 0; i < n; i++) {
		if (input[i].second)
			continue;
		//number++;
		input[i].second = true;
		int cur_ans = 1;
		int next = input[i].first + 1;
		int prev = input[i].first - 1;
		while (hm.find(next) != hm.end()) {
			input[hm[next]].second = true;
			cur_ans++;
			next++;
		}

		while (hm.find(prev) != hm.end()) {
			input[hm[prev]].second = true;
			cur_ans++;
			prev--;
		}

		ans = max(ans, cur_ans);
	}
	cout << ans << endl;
	// cout<<number;
	return 0;
}

