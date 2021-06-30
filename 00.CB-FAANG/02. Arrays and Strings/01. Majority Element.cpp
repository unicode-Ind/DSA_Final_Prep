/*
You have to given an array A of size N.
Find all the elements which appear more than floor(N/3) times in the given array.
Wait Wait!
There is a condition that you have to do your job in O(N) time complexity and O(1) space complexity.

Input Format
First line contains N ->No. of elements in the array
Second line has N integers denoting the elements of the array A ie A1,A2,A3…….AN.

Constraints
1<=N<=10^7
0<=Ai<=10^9

Output Format
Print a single line containing all the majority elements occurring more than floor(N/3) times.
If there is no majority element then just print "No Majority Elements".

Sample Input
8
2 2 3 1 3 2 1 1
Sample Output
1 2
Explanation
None
*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> input(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int ans[2] = { -1, -1};
    int freq[2] = {0};

    for (int i : input) {
        if (i == ans[0])
            freq[0]++;
        else if (i == ans[1])
            freq[1]++;
        else if (freq[0] == 0) {
            ans[0] = i;
            freq[0] = 1;
        }
        else if (freq[1] == 0) {
            ans[1] = i;
            freq[1] = 1;
        } else {
            freq[0]--;
            freq[1]--;
        }
    }

    int cnt[2] = {0};
    cnt[0] = count(input.begin(), input.end(), ans[0]);
    cnt[1] = count(input.begin(), input.end(), ans[1]);

    if (cnt[0] <= n / 3 and cnt[1] <= n / 3) {
        cout << "No Majority Elements";
    } else {

        vector<int> res;
        if (cnt[0] > n / 3)
            res.push_back(ans[0]);
        //cout<<ans[0]<<" ";

        if (cnt[1] > n / 3)
            res.push_back(ans[1]);
        //cout<<ans[1]<<" ";

        // sort(res.begin(),res.end());
        for (int i : res)
            cout << i << " ";
    }

    cout << endl;
    return 0;
}