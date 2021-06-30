/*
You are given an N X M matrix. Your task is to calculate the total number of ways to reach the bottom right point if you are currently at top left point i.e. from (1,1 to N,M). You can only move towards right or towards bottom

Input Format
First line contains T,the number of test cases. Then T lines follow each containing 2 integers N and M

Constraints
1<=T<=100
1<=N,M<=11

Output Format
Print T lines where i'th line corresponds to the total number of ways possible in the i'th test case

Sample Input
2
3 3
2 8
Sample Output
6
8

*/

#include<iostream>
#include<vector>
using namespace std;
#define ll long long

vector<ll> factorial(25, -1);

ll fact(int n) {
	if (factorial[n] != -1)
		return factorial[n];

	return factorial[n] = n * fact(n - 1);
}

int main() {

	int t;
	cin >> t;
	factorial[0] = factorial[1] = 1;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		// non dp solution , using pnc

		cout << fact(n + m - 2) / (fact(n - 1)*fact(m - 1)) << endl;
	}
	return 0;
}

/*
Count Paths

Algorithm:

This question can easily be solved by recursively calling first for bottom and then for right and in the base case we will increase our count. However this has exponential time complexity. To resolve this we can use top down dynamic programming where we make use of memoization and store results of our subproblems. This step greatly reduces time complexity to O(mn) where m and n are the number of rows and columns respectively.

However we can still do better than this.

We can easily observe that the total number of rights that we take is (n-1) and the total number of downs that we take is m-1. It’s just that these are being rearranged and getting added up in our answer. Now the question reduces to a very simple problem of counting the total number of words that can be formed by(m-1 + n-1) characters where m-1 and n-1 are repeating characters. Therefore our answer comes out to be (m+n-2)!/((n-1)!*(m-1)!).

Note:

Here we are calculating n-1 and m-1 because our starting point is itself 1,1 therefore we have to take one less step than the total number of rows and columns.
Also given a word with q characters out of which h and j characters are repeating, then the total permutations that can be formed are q!/(h!*j!);
Here as we have multiple test cases, we can precompute factorials of our numbers.
Solution Link : https://ide.codingblocks.com/s/200772


//Input format
//T test cases
//then t lines having 2 integers n and m
#include <iostream>
using namespace std;

int ways(int i,int j){
    if(i == 0 && j == 0) return 0;
    else if(i == 0 || j == 0) return 1;
    return (ways(i,j-1) + ways(i-1,j));
}

int top_down(int i,int j,int **dp){
    if(dp[i][j] == -1){
        if(i == 0 && j == 0) {
            dp[i][j] = 0;
            return 0;
        }
        else if(i == 0 || j == 0) {
            dp[i][j] = 1;
            return 1;
        }
        dp[i][j] = top_down(i,j-1,dp) + top_down(i-1,j,dp);
        return dp[i][j];
    }
    else return dp[i][j];
}

int bottom_up(int n,int m){
    int **dp  = new int*[n];
        for(int i=0;i<n;i++){
            dp[i] = new int[m];
            for(int j=0;j<m;j++){
                dp[i][j] = -1;
            }
    }

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    for(int j=0;j<m;j++){
        dp[0][j] = 1;
    }
    dp[0][0] = 0;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }

    return dp[n-1][m-1];

}

int main() {
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
       // cout<<ways(n-1,m-1)<<endl;

        int **dp  =new int*[n];
        for(int i=0;i<n;i++){
            dp[i] = new int[m];
            for(int j=0;j<m;j++){
                dp[i][j] = -1;
            }
        }
       // cout<<top_down(n-1,m-1,dp)<<endl;

        cout<<bottom_up(n,m)<<endl;
    }
    return 0;
}
*/