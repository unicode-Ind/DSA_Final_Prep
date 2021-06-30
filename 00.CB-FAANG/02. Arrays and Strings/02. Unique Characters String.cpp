/*
Ramu has an array of strings. He want to find a string s such that it is a concatenation of sub-sequence of given array and have unique characters.Since,he has just started coding so he needs your help.
A sub-sequence of an array is a set of elements that can be obtained by deleting some elements(posssibly none) from the array and keeping the order same.
Print the maximum possible length of s.

Input Format
The first line of input contains an interger n -the length of array.Next n lines contains the element(strings) of the array

Constraints
1 <= n <= 18, 1 <= arr[i].length<= 26

Output Format
Print one integer - the maximum length of s.

Sample Input
3
ab
cd
ab
Sample Output
4
*/

#include <bits/stdc++.h>
using namespace std;

int fun(vector<string> v, string cur, int i = 0) {

	//base
	if (i == v.size()) {
		int freq[26] = {0};
		for (char c : cur) {
			if (freq[c - 'a'] > 0)
				return 0;
			freq[c - 'a']++;
		}
		return cur.length();
	}

	int op1, op2;
	op1 = op2 = INT_MIN;
	//if can include
	if (cur.length() + v[i].length() <= 26)
		op1 = fun(v, cur + v[i], i + 1);
	//dont include
	op2 = fun(v, cur, i + 1);

	return max(op1, op2);

}

int main() {
	int n;
	cin >> n;

	vector<string> input;
	for (int i = 0; i < n; i++) {
		string in;
		cin >> in;
		input.push_back(in);
	}

	cout << fun(input, "", 0);
	return 0;
}