/*
Given a string, find the length of the longest substring without repeating characters.

Input Format
First line contains integer t as number of testcases. Next line contains t strings.

Constraints
None

Output Format
Print the length of the longest substring without repeating characters.

Sample Input
1
abcabcbb
Sample Output
3
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int solve(string &s) {
	unordered_map<char, int> hm;
	for (char cur : s)
		hm[cur] = -1;

	int start = 0, cur_index = 0, ans = 0;
	for (char cur : s) {
		if (hm[cur] != -1) {
			start = hm[cur] + 1;
		}
		hm[cur] = cur_index;
		ans = max(ans, cur_index - start + 1);

		cur_index++;
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string input;
		cin >> input;

		cout << solve(input) << endl;
	}
	return 0;
}


/*
Question : Longest Substring Without Repeating Characters

Time Complexity : Overall time complexity is O(nlogn).

Algorithm: Here using unordered_map we will solve the problem given problem and the steps to solve the problem are given below:

Step 1: Initialize one variable t(int t, number of test cases ),another variable s (string s).

Step 2: Make a function lengthOfLongestSubstring(s) and pass string ‘s’ (call by value) as parameter and the function will return an integer.
lengthOfLongestSubstring(s)
Int lengthOfLongestSubstring(string s)

Step 3: Inside the function declare an unordered map ‘m’ of key of type char and value of type int and a variables sidx=0,maxlen=0,curlen=0 initially.
unordered_map m

Step 4: Loop from i=0 till i less than length of string ‘s’ (i=0;i<s.length();i++) ,on every iteration increment i and inside the loop check whether the character has occured before or not and if the character has not occured before then increment the curlen by 1 and at the key s[i] in map ‘m’ put value equal to i (current index) , else if the element has occured before then store maximum of curlen and maxlen in maxlen and check if sidx is greater than m[s[i]] .If it is so then increment curlen by 1 else inside curlen store value equal to i- m[s[i]] and inside sidx store value equal to m[s[i]]+1.Now at m[s[i]] put value equal to i.

Step 5: When i==s.length() Return maximum of maxlen and curlen which is the required answer.

Solution Link: https://ide.codingblocks.com/s/183292

#include <iostream>
#include<unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int sidx = 0;
        int maxlen = 0,crlen=0;
        for(int i=0;i<s.length();i++)
        {
            // cout<<maxlen<<" "<<crlen<<endl;
            if(m.find(s[i])==m.end())
            {
                crlen++;
                m[s[i]] = i;
            }
            else
            {
                maxlen = max(crlen,maxlen);
                if(sidx > m[s[i]]){
                    crlen++;
                }
                else
                {
                    crlen = i-m[s[i]];
                    sidx = m[s[i]]+1;
                }
                m[s[i]] = i;
            }
            // maxlen = max(crlen,i-m[s[i]]);
        }
                    // cout<<maxlen<<" "<<crlen<<endl;

        return max(maxlen,crlen);
    }
int main() {
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        cout<<lengthOfLongestSubstring(s)<<endl;
    }
}

*/