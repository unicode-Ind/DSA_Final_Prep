/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k.If there isn't one ,return 0 instead.

Input Format
First line contains list of integers. Second line contains the target k.

Constraints
None

Output Format
Print the maximum length of a subarray that sums to k

Sample Input
[-2,-1,2,1]
1
Sample Output
2
Explanation
Because the subarray [-1, 2] sums to 1and is the longest.

*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
	unordered_map<int, int> hm;
	//key : prefix sum, value : index of 1st occurance of that prefix sum
	hm[0] = -1;

	int sum = 0;

	//trick to avoid find function
	for (int i : nums) {
		sum += i;
		hm[sum - k] = -2;
	}

	sum = 0;
	int i = 0, ans = 0;
	for (int cur : nums) {
		sum += cur;
		if (hm[sum - k] == -2) {
			hm[sum] = i;
		} else {
			ans = max(ans, i - hm[sum - k]);
		}

		i++;
	}
	return ans;

}

int main() {
	string line;
	getline(cin, line);

	int k;
	cin >> k;
	vector<int> input;

	line = line.substr(1, line.size() - 2);
	//cout<<line;

	// stringstream class check1
	stringstream check1(line);
	string intermediate;
	// Tokenizing w.r.t. space ','
	while (getline(check1, intermediate, ','))
	{
		input.push_back(stoi(intermediate));
	}

	cout << solve(input, k);

	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        vector<int>prefixSum;
        unordered_map<int,int>pos;
        int sum=0;
        prefixSum.push_back(0);
        pos[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            prefixSum.push_back(sum);
            pos[sum]=i;
        }
        int ans=0;
        for(int i=0;i<prefixSum.size();i++)
        {
            if(pos.find(k+prefixSum[i])!=pos.end())
            {
                int index=pos[k+prefixSum[i]];
                if(index-i+1>ans)
                {
                    ans=index-i+1;
                }
            }

        }
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    if (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().maxSubArrayLen(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

*/

