/*
We have an array of positive integers. The task is to print the maximum length of Bitonic subsequence.
A bitonic sequence is any sequence which first increases in magnitude and then at a certain point it starts to decrease in magnitude.
For eg: 1 2 3 2 1 is a bitonic sequence while 1 2 3 2 1 2 3 is not, since it first increases, then decreases and then again increases.

Input Format
First line of each input contains T(no. of testcase)
For each testcase first line contains 'n' length of array
For each testcase next 'n' lines contains element a[i]

Constraints
1<=T<=100
1<=N<=100
1<=Ai<=200

Output Format
For each testcase , in a new line, print the length of longest Bitonic sequence.

Sample Input
2
9
1 3 5 7 4 3 5 2 6
11
4 5 6 3 2 7 8 5 4 6 3
Sample Output
7
8
Explanation
In the first test case we can select numbers 1 3 5 7 4 3 2 => ans =7.
In the second testcase we can select numbers 4 5 6 7 8 5 4 3 => ans=8
*/

#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> input(n), left(n, 1), right(n, 1);
		//left(i) : lenght of largest inn subsequence ending at input[i] (including) => input[i] is peak of binotic subsequence
		//right(i) : input[i] is peak of dec part of subsequence, (including)
		// ans = max(right[i]+left[i]-1) => -1 bcz input[i] s counted twice
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (input[i] > input[j])
					left[i] = max(left[i], left[j] + 1);
			}
		}

		for (int i = n - 1; ~i; i--) {
			for (int j = n - 1; j > i; j--) {
				if (input[i] > input[j])
					right[i] = max(right[i], right[j] + 1);
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max (ans, left[i] + right[i] - 1);
		}
		cout << ans << endl;

	}
	return 0;
}


/*
Question : Bitonic SubSequences

Time Complexity : Overall time complexity is O(n^2).

Algorithm: Here using concept of DP we will solve the problem given problem and the steps to solve the problem are given below:

Step 1: Initialize two variables t , n both of integer type. And do the following steps for T number of test cases.

Step 2: Declare an array of size n and take n number of elements. Now Dynamically allocate memory to two arrays dp1 and dp2 of size n.

Step 3: To first check for ascending series:
i) Put dp1[0]=1 then loop from i=1 till i<n (outer loop) ,and inside loop declare a variable d=1 ,then loop from j=i-1 to j>=0 (inner loop) , decrement j after every iteration.
ii) Check if a[i] is greater than a[j] if so then d=max(d,dp1[j]+1).when j is less than 0 put dp1[i]= d and increment i.

Step 4:Now checking for descending series:

i) Put dp2[n-1]=1 then loop fromi=n-2 till i>=0 (outer loop) ,and inside loop declare a variable d=1 , loop from j=n-1 to j>i(inner loop) , decrement j at every iteration.

ii) Check if a[i] is greater than a[j] if so then d=max(d,dp2[j]+1).when j is equal to i put dp2[i]=d and decrement i.

Step 5: Initialize a variable ans=dp1[0]+dp2[0]-1. Loop from i=1 till i<n and update ans=max(ans,dp1[i]+dp2[i]-1) at every Iteration and increment i.

Step 6: When i=n print the value present in ans variable.

Code:


#include<iostream>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int* a = new int[n];
        for(int i=0;i<n;i++)    cin>>a[i];
        int* dp1 = new int[n];
        int* dp2 = new int[n];
        //Ascending Waala Kaam
        dp1[0]=1;
        for(int i=1;i<n;i++){
            int d = 1;
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j])
                    d = max(d,dp1[j]+1);
            }
            dp1[i]=d;
        }
        //Descending waala kaam
        dp2[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int d = 1;
            for(int j=n-1;j>i;j--){
                if(a[i]>a[j])
                    d = max(d,dp2[j]+1);
            }
            dp2[i]=d;
        }
        int ans = dp1[0] + dp2[0] - 1;
        for(int i=1;i<n;i++){
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}

Bitonic SubSequences - <i class="fab fa-facebook"></i> <i class="fab fa-apple"></i> <i class="fab fa-amazon"></i> N <i class="fab fa-google"></i>



*/