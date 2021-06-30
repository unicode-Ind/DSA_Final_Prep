/*
Jake is solving a problem. He is given two words, a begin word and an end word(both are non empty and distinct) and a dictionary of words(all the word are lowercase with same length and there are no duplicates in dictionary). Now he has to reach the end word from begin word using the given dictionary and find the length of shortest possible transformation to do so.

There are two conditions which he has to follow:-
1.Only one letter can be changed at a time.
2.Each transformed word must exist in word list.

Jake is a beginner in problem solving, so he wants your help to solve this problem.


Input Format
First two lines contains a String each which denotes begin word and end word respectively. Third line contains an integer N denoting size of dictionary, next line contains list or dictionary of N words.

Constraints
None

Output Format
An integer denoting a length of shortest transformation if not possible return 0

Sample Input
hit
cog
6
hot dot dog lot log cog
Sample Output
5
Explanation
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
*/


#include <bits/stdc++.h>
using namespace std;

int solve(string src, string dest, unordered_map<string, int> &distance) {
	//unordered_map<string,bool> visited;
	queue<string> q;
	q.push(src);
	//visited[src]=true;
	distance[src] = 1;

	while (!q.empty()) {
		string cur = q.front();
		q.pop();

		if (cur == dest)
			return distance[cur];

		int size = cur.size();
		for (int i = 0; i < size; i++) {
			string start = cur.substr(0, i);
			string end = cur.substr(i + 1, size - i - 1);
			for (char c = 'a'; c <= 'z'; c++) {
				string word_formed = start + c + end;

				if (distance.find(word_formed) != distance.end() and distance[word_formed] == INT_MAX) {
					distance[word_formed] = distance[cur] + 1;
					q.push(word_formed);
				}
			}
		}
	}

	return 0;
	// return distance[dest];
}

int main() {

	string src, dest;
	cin >> src >> dest;

	int n;
	cin >> n;

	unordered_map<string, int> distance;
	for (int i = 0; i < n; i++) {
		string inp;
		cin >> inp;
		distance[inp] = INT_MAX;
	}

	// int ans = solve(src,dest,distance);
	// if(ans == INT_MAX)
	// 	cout<<0<<endl;
	// else
	// 	cout<<ans<<endl;

	cout << solve(src, dest, distance);

	return 0;
}

/*
X
Word Ladder(BFS):-
Approach:-
The start and end nodes here can represent two nodes of the graph and the wordlist determines the intermediate nodes through which end node can be reached from the start node. Now the problem is to find the shortest distance between start node and end node iff end node exists. So this can be easily solved using bfs or breadth first search.

Algorithm:-
A queue and a pair of words and the level of each word, and a set of words present in the wordlist are used here. Add beginWord into the queue and set its level as 1. Now until the queue is empty, remove the front word from the queue, say currentWord. Now using transform function, transform the currentWord character by character till it matches the word in words set. Remove the matched word from the words set to mark it visited and avoid duplication and add that word into neighbours arraylist. Iterate over all the neighbours, if any neighbour matches with endWord it means the destination is reached and return currentWord’s level incremented by one as graph is being traversed level by level. Else add the neighbour with level incremented into the queue and repeat from step 2. If endWord is not reachable after traversing the whole graph, return 0;

Time Complexity:- O(M*N) where M is the length of each word and N is the total number of input words in the input list. Transform takes M iterations to transform each of the N words. In the worst case that is unreachability of endWord, the bfs traversal may process each of the N words.

Solution Link:- https://ide.codingblocks.com/s/213873
*/