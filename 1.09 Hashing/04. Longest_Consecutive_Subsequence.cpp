/*
say input : 4 1 6 3 7 19 2 21 20 2

consecutive aub-seq : [4 1 3 2], [6 7], [19, 21 20]

max_length = 4

note : order is irrelevant, only we need an effective set of consecutive numbers

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int fun1(vector<int> nums) {
	//using sorting
	int ans = 0;
	sort(nums.begin(), nums.end());

	int i = 0, j, uniques;
	while (i < (int)nums.size()) {

		int j = i + 1;
		uniques = 1;

		while (j < (int)nums.size()) {
			if (nums[j] - nums[j - 1] == 0) {
				//noting
			}
			else if (nums[j] - nums[j - 1] == 1) {
				uniques++;
			} else {
				break;
			}

			j++;
		}

		ans = max(ans, uniques);

		// i = i + (j-i);
		i = j;
	}

	return ans;

}

int fun2(vector<int> &nums) {
	//min-max approach

	unordered_set<int> hm;

	int mini = *min_element(nums.begin(), nums.end());
	int maxi = *max_element(nums.begin(), nums.end());

	for (int i : nums)
		hm.insert(i);

	int cnt = 0, ans = 0;

	for (int i = mini; i <= maxi; ++i)
	{
		if (hm.count(i)) {
			cnt++;
		} else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}

	return max(ans, cnt);
}

int fun3(vector<int> &nums) {
	//streaks update approach

	int ans = 0;
	unordered_map<int, int> hm; // <number, lenght of streak with number at one of extreme>


	for (int i : nums) {
		//if a number is considered in a streak, then its duplicate shouldnot be evaluated again ... WHY ???

		//this is most important edge case handle with duplicates
		// eg 1 2 2 3 4 5 in input 4 1 3 7 8 9 2 19 20 5 2
		// when 2nd 2 comes it will take left_len from hm[1] = 5 nad hm[3]=1 => updating hm[1] from 5 to (5+1+1=7) => wrong ans
		if (hm.count(i))
			continue;

		bool left = hm.count(i - 1) > 0 ;
		bool right = hm.count(i + 1) > 0;

		if (left and right) {
			// s1 + i +s2
			int len_left = hm[i - 1];
			int len_right = hm[i + 1];
			int total_streak_len = len_left + 1 + len_right;

			hm[i - len_left] = hm[i + len_right] = hm[i] = total_streak_len;

		} else if (left) {
			int len_left = hm[i - 1];
			int total_streak_len = len_left + 1 ;

			hm[i - len_left] = hm[i] = total_streak_len;

		} else if (right) {
			int len_right = hm[i + 1];
			int total_streak_len = len_right + 1 ;

			hm[i] = hm[i + len_right] = total_streak_len;
		} else {
			//new streak with len 1
			hm[i] = 1;
		}

		//cout << (ans = max(ans, hm[i])) << " ";
	}

	for (auto i : hm)
		ans = max(ans, i.second);


	return ans;
}

int fun4(vector<int> &nums) {
	//optimised O(n) using unordered_map

	//find possble streak head and complete streak

	unordered_set<int> hm;
	int ans = 0;

	//insert into set
	for (int i : nums)
		hm.insert(i);

	for (int i : nums) {
		if (hm.find(i - 1) == hm.end()) {
			// (i-1) is not present => i is head for some streak
			// => iterate over streak

			/*
			int next = i + 1;
			while (hm.find(next) != hm.end())
				next++;

			ans = max(ans, next - i);
			*/
			//OR, alternatively
			int len = 1;
			while (hm.find(i + len) != hm.end())
				len++;

			ans = max(ans, len);

		}
	}


	return ans;
}


int fun5(vector<int> &nums) {
	//streaks update approach

	int ans = 0;
	unordered_map<int, bool> hm; // <number, visited in a streak>
	for (int i : nums)
		hm[i] = false;


	for (int i : nums) {
		if (hm[i])
			continue;

		int cnt = 1;
		hm[i] = true;

		int next = i + 1;
		while (hm.count(next) and !hm[next]) {
			hm[next] = true;
			next++;
			cnt++;
		}

		int prev = i - 1;
		while (hm.count(prev) and !hm[prev]) {
			hm[prev] = true;
			prev--;
			cnt++;
		}

		ans = max(ans, cnt);

	}

	return ans;
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

	cout << fun3(input) << endl;

	cout << fun4(input) << endl;

	cout << fun5(input) << endl;


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}