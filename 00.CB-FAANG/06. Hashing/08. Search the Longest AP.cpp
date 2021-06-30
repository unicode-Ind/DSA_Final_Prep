/*
Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i1], A[i2], …, A[ik] with 0 <= i1 < i2 < … < ik <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

Input Format
First line contains list of integers.

Constraints
2 <= A.length <= 2000
0 <= A[i] <= 10000

Output Format
Print the the length of the longest arithmetic subsequence in A.

Sample Input
[20,1,15,3,10,5,8]
Sample Output
4
Explanation
The longest arithmetic subsequence is [20,15,10,5].
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> input){
	int n = input.size();

	if (n < 3)
		return n;

	unordered_map<int, list<int>> hm;
	for (int i = 0; i < n; i++)	hm[input[i]].push_back(i);

	int ans = 2;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int d = input[j] - input[i];
			int next_term = input[j] + d;

			bool next_term_exist = true;
			int index_of_occurence_of_last_term = j;
			//int index_of_occurence_of_next_term = n;
			int cur_ans = 2;

			while (next_term_exist) {

				auto that_list = hm.find(next_term);
				if (that_list == hm.end())
					break;

				next_term_exist = false;

				for (auto index : hm[next_term]) {

					if (index > index_of_occurence_of_last_term) {
						next_term_exist = true;
						index_of_occurence_of_last_term = index;
						cur_ans++;
						next_term = input[index] + d;
						break;
					}
				}

				ans = max(ans, cur_ans);
			}
		}
	}

	return ans;

}

int main() {

	string line;
	getline(cin, line);
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

	cout << solve(input) << endl;

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main() {
	unordered_map<int,list<int>> hm;

	int n;
	cin>>n;
	vector<int> input(n);
	for(int i=0;i<n;i++){
		cin>>input[i];

		hm[input[i]].push_back(i);
	}

	if(n<3){
		cout<<n<<endl;
		return 0;
	}

	int ans=2;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int d = input[j]-input[i];
			int next_term = input[j] + d;

			bool next_term_exist = true;
			int index_of_occurence_of_last_term = j;
			//int index_of_occurence_of_next_term = n;
			int cur_ans=2;

			while(next_term_exist){

				auto that_list = hm.find(next_term);
				if(that_list == hm.end())
					break;

				next_term_exist = false;

				for(auto index : hm[next_term]){
					if(index > index_of_occurence_of_last_term){
						next_term_exist = true;
						index_of_occurence_of_last_term = index;
						cur_ans++;
						ans=max(ans,cur_ans);
						next_term = input[index]+d;
						break;
					}
				}
			}
		}
	}
	cout<<ans;


	return 0;
}

*/
/*
#include<bits/stdc++.h>
using namespace std;
int main() {
	unordered_map<int,list<int>> hm;

	int n;
	cin>>n;
	vector<int> input(n);
	for(int i=0;i<n;i++){
		cin>>input[i];

		hm[input[i]].push_back(i);
	}

	if(n<3){
		cout<<n<<endl;
		return 0;
	}

	int ans=2;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int d = input[j]-input[i];
			int next_term = input[j] + d;

			bool next_term_exist = true;
			int index_of_occurence_of_last_term = j;
			//int index_of_occurence_of_next_term = n;
			int cur_ans=2;

			while(next_term_exist){

				auto that_list = hm.find(next_term);
				if(that_list == hm.end())
					break;

				next_term_exist = false;

				for(auto index : hm[next_term]){
					if(index > index_of_occurence_of_last_term){
						next_term_exist = true;
						index_of_occurence_of_last_term = index;
						cur_ans++;
						ans=max(ans,cur_ans);
						next_term = input[index]+d;
						break;
					}
				}
			}
		}
	}
	cout<<ans;


	return 0;
}

*/

/*
Editorial
X
We can use dp to solve this problem.
We can solve this in O(N^N) time.
Store elements in map/unordered map and try to make longest possible ap for each pair.

Code:


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& ar) {
        map<int,list<int>>m;
        if(ar.size()==1)
            return 1;
        int ans=2,n=ar.size();
        for(int i=0;i<n;i++)
        {
            m[ar[i]].push_back(i);
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff=ar[j]-ar[i];
                int count=2;
                int start=ar[j];
                int curr_index=j;
                while(1)
                {
                    int flag=0;
                    if(m.find(start+diff)!=m.end())
                    {
                        for(auto node:m[start+diff])
                        {
                            if(node>curr_index)
                            {
                                curr_index=node;
                                start=ar[curr_index];
                                count++;
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==0)
                        break;
                }
                if(count>ans){
                    ans=count;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);

        int ret = Solution().longestArithSeqLength(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
*/