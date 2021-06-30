/*
Given an array of strings, group anagrams together.
Note:All inputs will be in lowercase.
The order of your output does not matter. go to this link Anagrams_Together leetcode

Input Format
First line contains integer n as size of String array. Next n line contains single string as element of array.

Constraints
None

Output Format
Print the anagrams together.

Sample Input
6
eat
tea
tan
ate
nat
bat
Sample Output
eat tea ate
bat
tan nat
*/

class Solution {
public:

    vector<vector<string>> intial(vector<string>& input) {
        unordered_map<string, vector<string>> hm;
        int i = 0;
        for (auto cur : input) {
            sort(cur.begin(), cur.end());

            if (hm.find(cur) == hm.end()) {
                vector<string> t(1, input[i]);
                hm[cur] = t;
            }
            else
                hm[cur].push_back(input[i]);
            i++;
        }
        vector<vector<string>> ans;
        for (auto l : hm) {
            ans.push_back(l.second);
        }
        return ans;

    }

    vector<vector<string>> groupAnagrams(vector<string>& input) {

        //return inital(input);

        unordered_map<string, vector<string>> hm;

        int i = 0;
        for (auto cur : input) {
            sort(cur.begin(), cur.end());

            hm[cur].push_back(input[i]);
            i++;
        }
        vector<vector<string>> ans;
        for (auto l : hm) {
            ans.push_back(l.second);
        }
        return ans;


    }
};