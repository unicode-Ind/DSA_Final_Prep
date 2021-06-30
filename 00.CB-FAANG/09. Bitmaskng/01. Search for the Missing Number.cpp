/*
Given an array containing n distinct numbers taken from 0, 1, 2, …, n. Find the one that is missing from the array.

Input Format
First line contains integer n as size of array. Next n lines contains a single integer as element of array.

Constraints
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity.

Output Format
Print the required output.

Sample Input
3
3 0 1
Sample Output
2
*/

#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int input;
	int total = 0;

	for (int i = 1; i <= n; i++) {
		cin >> input;
		total ^= (i ^ input);
		//or
		//total += (i-input);
	}
	cout << total;
	return 0;
}

/*
Editorial
X
Question: Search for the missing number

Time Complexity: Time complexity of this solution is O(n).

Algorithm: We are given a list of integers and these integers are in the range of 0 to n. There are no duplicates in the list. One of the integers is missing in the list. An efficient Algorithm to find the missing integer is as :

Using concept of XOR operation we will solve the problem as: Step 1: Initialize one variable n (int n),vector ‘nums’ of integer type(vector nums).(n is the number of elements to be pushed in the vector ‘nums’) and a variable ‘a’.

Step 2: Make a function missingNumber and pass ‘nums’ as parameter(call by refrence).
Ie, missingNumber(nums)
Int missingNumber(vector& nums)

Step 3: Inside the function Initialize two variables x and y both equal to zero initially.

Step 4: XOR all the numbers from 0 to n, let the result be x. i)Loop from i=0 till i< size of vector ‘nums’ (i=0;i<nums.size(); i++) ,and xor i with value of ‘x’ and store the result in ‘x’ on every iteration.

Step 5: XOR all the vector elements , let the result y. i)Loop from i=0 till i< size of vector ‘nums’ (i=0;i<nums.size(); i++) ,and xor nums[i] with value of ‘y’ and store the result in ‘y’ on every iteration.

Step 6: XOR of x and y gives the missing number.
Return the xor of x and y;

Solution link: https://ide.codingblocks.com/s/183412
*/