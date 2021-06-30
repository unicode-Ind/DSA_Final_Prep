/*
We are Given a target integer k and list of non-negative numbers.Write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.

Input Format
First line contains list of integers. Second line contains the target k.

Constraints
1<=length of array<=10^4

Output Format
Print the boolean answer True/False.

Sample Input
[23,2,4,6,7]
6
Sample Output
True
Explanation
Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
*/

#include<bits/stdc++.h>
#include<cstring>
using namespace std;

bool solve(vector<int>& nums, int k) {
	//edge case
	if (k == 0) {
		for (int i = 0; i < nums.size() - 1; i++)
			if (nums[i] == 0 and nums[i + 1] == 0)
				return true;
		return false;
	}

	//normal
	unordered_map<int, int> hm;
	hm[0] = -1;

	//long long
	int sum = 0;
	int modedSum, i = 0;
	for (int cur : nums) {
		sum += cur;

		modedSum = sum % k;

		if (hm.find(modedSum) != hm.end()) {
			if (i - hm[modedSum] + 1 > 1)
				return true;
		}

		hm[modedSum] = i;
		// this need not in else block (k=6, nums 6 0)
		// ideally to get largest length we shd not update hm for nums[1]=0,
		// but here doesnot matter bcz min requirement is len=2

		i++;
	}

	return false;
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

	if (solve(input, k))
		cout << "True";
	else
		cout << "False";

	return 0;
}

/*
input:

[23,2,4,6,7]
6

output : True
*/

/*

Code:


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int sum=0;
        int mod;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(k!=0)
            {
                sum+=nums[i];
                mod=sum%k;
                if(m.find(mod)==m.end())
                {
                    m[mod]=i;
                }
                else if(i-m[mod]>1)
                    return true;
            }
            else if(k==0&&nums[i]==0&&i<nums.size()-1&&nums[i+1]==0)
                return true;
        }
        return false;

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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        bool ret = Solution().checkSubarraySum(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

*/