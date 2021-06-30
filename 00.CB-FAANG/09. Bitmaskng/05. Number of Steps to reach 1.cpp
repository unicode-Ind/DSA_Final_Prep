/*
Given a positive number N your task is to bring this number to 1 by performing only a set of operations. The operations can be either dividing the number by 2 only if the number is even or you can add or subtract 1 only if the number is odd.
More Precisely:
1) N=N/2 (if N is even)
2)N=N+1/ N=N-1 (if N is odd)
Your task is to minimize these number of operations.

Input Format
A single positive integer N

Constraints
n<=100000

Output Format
Print on a single line the minimum number of steps needed to reach 1 by performing the given operations.

Sample Input
8
Sample Output
3
Explanation
8->4->2->1
*/

#include<iostream>
#include<cmath>
using namespace std;

int cnt = 0;
int dp[100005] = {};
int solve_recursive(int n) {
	//cout<<n<<endl;
	if (n == 1)
		return 0;

	if (dp[n])
		return dp[n];
	//cnt++;
	if (n & 1)
		dp[n] = min(solve_recursive(n - 1), solve_recursive(n + 1)) + 1;
	else
		dp[n] = solve_recursive(n / 2) + 1;

	return dp[n];
}

int solve_bitwise(int n) {
	if (n == 1)
		return 0;

	if (n % 2 == 0)
		return solve_bitwise(n / 2) + 1;

	if (n == 3 or n % 4 == 1)
		return solve_bitwise(n - 1) + 1;

	return solve_bitwise(n + 1) + 1;
}

int main() {
	int n;
	cin >> n;

	//cout<<solve_recursive(n);
	cout << solve_bitwise(n);

	//WA
	// if(n==0){
	//     cout<<1;
	//     return 0;
	// }
	// double t=log2(n);
	// int ans=t;

	// if(t-ans>0)
	//     ans++;
	// cout<<ans;
	return 0;
}

/*
Editorial
X
Number of Steps to Reach 1

Algorithm:

This is a standard recursion problem. We have to call the recursive function for n/2 if n is even and if n is odd we have to call the function for both n-1 and n+1 and then return the minimum of what we got. If we memoize this, we can easily get our answer but there exists a better way. If we look closely, the whole problem reduces to us making a decision of choosing either n+1 or n-1. We know that we will get max benefit when the number is divisible by 2. Analyzing odd numbers we can say that they can be written in the form of 4n+1. We will utilize this property. It simply means that if n+1 is divisible by 4 we will call for n+1 and if n-1 is divisible by 4 we will call for n-1. We do this because a number divisible by 4 can be divided by 2 at least two times hence reducing our steps,i.e if a number is divisible by 4 and if we divide it by 2, the result will also be even simply meaning we can divide it by 2 one more time. However, there is a base case to it. If we reach 3 we don't want to go to 4 but we can directly return 2 as 3->2->1;


#include <iostream>
using namespace std;
class Solution {
public:
    int integerReplacement(int n) {
        if(n==2147483647)
            return integerReplacement(n-1);
        if(n==1)
            return 0;
        if(n%2==0)
            return integerReplacement(n/2)+1;
        else
        {
            if(n==3||n%4==1)
            {
                return integerReplacement(n-1)+1;
            }
            else
            {
                return integerReplacement(n+1)+1;
            }
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().integerReplacement(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
*/