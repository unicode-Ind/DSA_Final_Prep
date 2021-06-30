/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Input Format
First line contain T test cases. The following T lines contains a String and a integer k each.

Constraints
The problem should be done in linear time.

Output Format
An integer value returning the the length.

Sample Input
1
eceba 3
Sample Output
4
Explanation
"eceb" is a substring of length 4 with 3 distinct characters.
*/


#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

int solve(string &s, int k) {
	unordered_map<char, int> hm;
	queue<char> q;

	int ans = 0;

	for (char cur : s) {
		q.push(cur);
		hm[cur]++;

		while (hm.size() > k and !q.empty()) {
			char f = q.front();
			q.pop();
			hm[f]--;
			if (hm[f] == 0)
				hm.erase(f);
		}

		ans = max(ans, (int)q.size());
		//q.size() => size_t not int

	}

	return ans;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		int k;
		cin >> k;

		cout << solve(s, k) << endl;
	}
	return 0;
}

/*
Editorial
X
Longest substring with at most k distinct characters
Algorithm(Two pointer, Sliding Window):-
The key idea of the solution is to use two pointers, start and end to maintain a "sliding window" and use a HashMap to store all the characters in the window.
Each time move forward the "start" pointer and increase the size of the sliding window until the size of the window is greater than K. Then the size of the window can be easily calculated which contains at most K distinct characters.
The next step is to shrink the window by moving forward the "end" pointer if window size is greater than k. In order to get the maximum window size, move the end pointer minimum number of steps.
So at each step of the end pointer, update the map and remove the character out of the sliding window. The stop condition is that when the window size is again equal to the K, which means the window contains K distinct characters. That's the minimum steps we need to move forward the end pointer i.e when the window is again shrunk to size k.


The only trick here is to check at the last that if the start pointer is out of boundary, there is still a need to check if it is the largest window size.
Time Complexity:- O(n)
Space Complexity:- O(k)


Java Solution:-



import java.util.*;
class Main {
    public static int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (s == null || s.length() == 0 || k <= 0) {
            return 0;
        }

        Map map = new HashMap<>();
        int i = 0;
        int j = 0;
        int maxLen = 0;

        for (i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                int freq = map.get(c);
                map.put(c, freq + 1);
            } else {
                map.put(c, 1);
            }

            if (map.size() > k) {
                maxLen = Math.max(maxLen, i - j);
                while (map.size() > k) {
                    char endC = s.charAt(j);
                    int freq = map.get(endC);
                    if (freq == 1) {
                        map.remove(endC);
                    } else {
                        map.put(endC, freq - 1);
                    }
                    j++;
                }
            }
        }

        if (j < s.length()) {
            maxLen = Math.max(maxLen, i - j);
        }

        return maxLen;
    }

    public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int t = s.nextInt();
    while(t-- != 0)
    {
        String str= s.next();
        int k = s.nextInt();
        System.out.println(lengthOfLongestSubstringKDistinct(str,k));
    }
    }
}
*/