// NlogK size
//min heap

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

void INPUT();

void query_print(priority_queue<int, vector<int> , greater<int>> pq) {
	//call by value to extract from copy

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}


int main()
{
	INPUT();
	/*
	Input:
	1 0 2 -1 3 4 5 -1 0 4 10 -1 2

	Output:
	0 1 2
	3 4 5
	4 5 10
	*/

	priority_queue<int, vector<int>, greater<int>> pq;
	int cs = 0;

	int num, k = 3;
	//-1 => query point
	while (scanf("%d", &num) != EOF) {
		//cout << num << " ";
		if (num == -1) {
			query_print(pq);
		}
		else if (cs < k) {
			pq.push(num);
			cs++;
		}
		else {
			if (num > pq.top()) {
				pq.pop();
				pq.push(num);
			}
		}
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