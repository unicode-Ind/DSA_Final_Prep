/*
Reaching to the top of a staircase, it takes n steps.
The task can be accomplished either by climbing 1 step or 2 steps at a time.
In how many different ways can you climb to the top.
Note: n will be a positive integer.

Input Format
First line contains an integer n.

Constraints
None

Output Format
Print the total number of distinct ways you can climb to top.

Sample Input
2
Sample Output
2
Explanation
None
*/

#include<iostream>
#include<vector>
using namespace std;

int solve(int n) {
	vector<int> dp(n + 1, 1);

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}

/*
Question : Climbing Stairs

Time Complexity:The loop runs from i=n-1 till i>=0.So overall time complexity is O(n).

Algorithm: We can easily find recursive nature in above problem. The person can reach n’th stair from either (n-1)’th stair or from (n-2)’th stair. Let the total number of ways to reach n’t stair be ‘ways(n)’. The value of ‘ways(n)’ can be written as following.
ways(n) = ways(n-1) + ways(n-2)

So we can use function for fibonacci numbers to find the value of ways(n). Following are the steps of the above idea.

Step 1: Initialize one variable n (int n) denoting total steps to reach the top.

Step 2: Make a function climbStairs and pass n as parameter(call by value).
climbStairs(n)
Int climbStairs(int n)

Step 3: Inside the function check if value of n is less than 3 then return n.

Step 4: Make an array ‘dp’ of integer type (by dynamic allocation) with size equal to n+1.
Int *dp=new int[n+1]

Step 5: Initialize first element of array ‘dp’ with 0,second element with 1 and third element with 2.
dp[0]=0
dp[1]=1
dp[2]=2

Step 6:loop from i=3 till i<=n and at every increment of i at dp[i] store value equal to sum of previous two elements of dp array (use of fibonacci function). i.e,
dp[i] = dp[i-1] + dp[i-2]

Step 7: when i becomes greater than n return the value dp[n].
Return dp[n]

Solution link: https://ide.codingblocks.com/s/182363


#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    if(n<3)   return n;
    int* dp = new int[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n);
}
*/