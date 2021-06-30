/*
Given an array of non-negative integers arr.You are initially at a particular index(1-based indexing) given by an integer start.
Now , from that index you want to reach any index such that the value of array at that particular index is 0 . But , when you are at a particular index i , you can only go to i + arr[i] index or i - arr[i] index. Obviously at any step,you can't go outside the array.
Print "YES"(without quotes) if it is possible to reach any index with value 0 , else print "NO".

Input Format
First line contains two integer - n (size of the array) and start (starting index).
Next line contains n space separated non-negative integers.

Constraints
1 <= A.length <= 5 * 10^4
0 <= A[i] < A.length
0 <= s < A.length

Output Format
Print "YES"(without quotes) if it is possible to reach any index with value 0 , else print "NO".

Sample Input
6 3
1 2 1 1 0 1
Sample Output
YES
Explanation
None
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {

	unordered_map<int, list<int>> adjList;
public:
	void addNode(int b) {
		adjList[b] = list<int>();
	}
	void addEdge(int p, int c) {
		adjList[p].push_back(c);
	}

	void print() {
		for (auto i : adjList) {
			cout << i.first << " ->";
			for (auto j : i.second) {
				cout << j << " ";
			}
			cout << endl;
		}
	}

	bool bfs(int src, vector<int> &values) {
		unordered_map<int, bool> visited;
		queue<int> q;

		visited[src] = true;
		q.push(src);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (values[cur] == 0)
				return true;

			for (auto child : adjList[cur]) {

				if (visited[child])
					continue;

				visited[child] = true;
				q.push(child);
			}
		}

		return false;
	}

};

int main() {
	int n, src;
	cin >> n >> src;

	Graph g;

	vector<int> values(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
		g.addNode(i);
	}

	//g.addNode(0);

	for (int i = 0; i < n; i++) {
		//1 based indexing => not include 0
		if (i - values[i] > 0) //values +ve => i-values[i]<n =>no need
			g.addEdge(i, i - values[i]);

		if (i + values[i] < n)
			g.addEdge(i, i + values[i]);
	}

	if (g.bfs(src, values))
		cout << "YES";
	else
		cout << "NO";



	return 0;
}

