/*
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
*/

#include<iostream>
#include<vector>
using namespace std;
#define ll long long

ll mod = 10e9 + 7;

int fun(int n) {
    // if(n==0)
    //  return 1;
    // if(n==1)
    //  return 2;

    // return fun(n-1)+fun(n-2);


    //NOTE : Prateek's video approach not working here ????
    vector<ll> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }

    return dp[n];

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 0)
            cout << 0 << endl;
        else
            cout << fun(n) << endl;
    }
    return 0;
}


/*
#include <iostream>
using namespace std;

#define int long long
int countStrings(int n)
{
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}

void solve(){
    int n;
    cin>>n;
    cout<<countStrings(n)<<endl;
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
Approach 2
// C++ program to count all distinct binary strings // without two consecutive 1's

#include <iostream>
#define ll unsigned long long int
using namespace std;

ll countStrings(int n)
{
    ll a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = (ll)(a[i-1] + b[i-1]);
        b[i] = (ll)a[i-1];
    }
    return (ll)(a[n-1] + b[n-1]);
}


// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        cout << countStrings(n) << endl;
    }
    //cout << countStrings(3) << endl;
    return 0;
}
*/