/*
A professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping him from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money he can rob tonight without alerting the police.

Input Format
First line contains integer t as number of testcases. Second line contains integer n as size of array. Third line contains a single integer as element of array.

Constraints
None

Output Format
Print the maximum money as output.

Sample Input
1
4
1 2 3 1
Sample Output
4
*/

#include<iostream>
#include<vector>
using namespace std;

int solve(int n, vector<int> &input) {

	if (n == 0) return 0;
	if (n == 1) return input[0];
	if (n == 2) return max(input[0], input[1]);

	vector<int> dp(n);
	//dp[i] = profit robbery from [0,i] : max of ith house looted or not

	dp[0] = input[0];
	dp[1] = max(input[0], input[1]);

	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 2] + input[i], dp[i - 1]);
	}

	return dp[n - 1];

}

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> input(n);
		for (int i = 0; i < n; i++)
			cin >> input[i];

		cout << solve(n, input) << endl;
	}
	return 0;
}

/*
Editorial
X
Smart Robber
Time Complexity: O(N)
Space Complexity: O(N)
Algorithm:
Steps:
1.We have a given array of size N.
2. if the size of the array is zero then the maximum amount of money you can rob tonight without alerting the police. is Zero
3.if the size of the array is one then the maximum amount of money you can rob tonight without alerting the police. is Array[0].
4.f the size of the array is Two then the maximum amount of money you can rob tonight without alerting the police. is Max of Array[0] Array[1].
5.if the size of the array is Greater Than two following these steps House Ith will be robbed or not depending upon the value of the (Ith-2 + Ith )house and value of the Ith-1 house which is maximum.
6.we will iterate over the whole array and update answer on every iteration following these Steps:
I.if the max value is (Ith-2 + Ith )house Ith-2 and Ith House will be robbed.
II.if the max value is (Ith-1 )house Ith-1 House will be robbed.
// we will track never rob adjacent House.
int dp[] = new int[a.length];
dp[0] = a[0];
dp[1] = Math.max(a[0],a[1]);
for(int i=2;i<a.length;i++)

    dp[i] = Math.max(dp[i-2]+a[i],dp[i-1]);
    return dp[a.length-1];
Solution Link :https://ide.codingblocks.com/s/182031


import java.util.*;

public class Main {

    public static int rob(int[] a) {
        if(a.length == 0) return 0;
        if(a.length == 1) return a[0];
        if(a.length == 2) return Math.max(a[0],a[1]);

        int loot[] = new int[a.length];
        loot[0] = a[0];
        loot[1] = Math.max(a[0],a[1]);
        for(int i=2;i<a.length;i++)
            loot[i] = Math.max(loot[i-2]+a[i],loot[i-1]);
        return loot[a.length-1];
    }

    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        while(t-- > 0)
        {
            int n = scn.nextInt();
            int a[] = new int[n];
            for(int i=0;i<n;i++) a[i] = scn.nextInt();
            System.out.println(rob(a));
        }
    }
}


#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> a) {
        if(a.size() == 0) return 0;
        if(a.size() == 1) return a[0];
        if(a.size() == 2) return max(a[0],a[1]);

        vector<int> loot(a.size());
        loot[0] = a[0];
        loot[1] = max(a[0],a[1]);
        for(int i=2;i<a.size();i++)
            loot[i] = max(loot[i-2]+a[i],loot[i-1]);
        return loot[a.size()-1];
}
int main() {
    // your code goes here
    int t;
    cin >> t;

    while(t-- != 0) {
        int n;
        cin >> n;
        vector<int> a;
        for(int i=0;i<n;i++) {
            int inp;
            cin >> inp;
            a.push_back(inp);
        }
        cout << rob(a) << "\n";
    }
    return 0;
}

*/