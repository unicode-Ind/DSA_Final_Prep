#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int nxn = 1000000;
int n;
//vector<int> input(n);
//int input[nxn];

class cmp {
public:
	bool operator()(vector<int> &a, vector<int> &b) {
		if (a[0] + a[1] == b[0] + b[1])
			return a[2] > b[2];

		return a[0] + a[1] > b[0] + b[1];

		//this is wrong
		// if (a[0] == b[0]) {
		// 	if (a[1] == b[1])
		// 		return a[2] < b[2];
		// 	else
		// 		return a[1] > b[1];
		// }

		// return a[0] > b[0];
	}
};

int main()
{
	INPUT();
	int t;
	cin >> t;
	while (t--) {
		int p;
		cin >> p;

		int n;
		cin >> n;
		vector<int> rank(n, 0);
		for (int i = 0; i < n; i++)
			cin >> rank[i];

		//this_time, total_time_worked,rank
		priority_queue<vector<int> , vector<vector<int>>, cmp> pq;
		vector<int> t(3, 0);
		for (int i = 0; i < n; i++) {
			t[0] = rank[i];
			t[2] = rank[i];
			pq.push(t);
		}

		while (p--) {
			auto cur = pq.top();
			pq.pop();

			cur[1] += cur[0];
			cur[0] += cur[2];

			pq.push(cur);
		}

		int ans = 0;

		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();

			ans = max(ans, cur[1]);
		}

		cout << ans << endl;

	}
	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}