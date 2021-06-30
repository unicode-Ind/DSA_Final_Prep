/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Input Format
First Line Contains Single integer n (total students) Next N lines contain N integers containing 0 or 1

Constraints
1<=N<=1000

Output Format
Single integer that is the total number friend circles

Sample Input
3
1 1 0
1 1 0
0 0 1
Sample Output
2
Explanation
The 0th and 1st students are direct friends, so they are in a friend circle. The 2nd student himself is in a friend circle. So return 2.
*/

#include<bits/stdc++.h>
using namespace std;

void dfs_helper(unordered_map<int, list<int>> &graph, unordered_map<int, bool> &visited, int src) {
	visited[src] = true;

	for (int friends : graph[src]) {
		if (visited[friends])
			continue;
		dfs_helper(graph, visited, friends);
	}
}

int dfs(unordered_map<int, list<int>> &graph, int n) {
	int groups = 0;
	unordered_map<int, bool> visited;

	for (auto hm : graph) {
		if (visited[hm.first])
			continue;

		groups++;
		dfs_helper(graph, visited, hm.first);
	}

	return groups;
}

int main()
{
	int n;
	cin >> n;

	unordered_map<int, list<int>> graph;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			if (input) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	cout << dfs(graph, n);
}