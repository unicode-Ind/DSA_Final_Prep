/*
Monu is very weak in maths so kartik bhaiya gave him a simple task to check whether a given number n is a power of two.Help Monu and return boolean answer.

Input Format
Input a number n

Constraints
None

Output Format
Return true if n is is a power of two,else return false

Sample Input
218
Sample Output
false
Explanation
None
*/

#include<iostream>
#define ll long long
#include<algorithm>
using namespace std;
int main()
{
	ll n;
	cin >> n;

	if (__builtin_popcountll(n) == 1)
		cout << "true";
	else
		cout << "false";
	return 0;

}

/*
X
Question : Is Power of Two.

Time Complexity: (-)(logn) (Theta of logn)

Algorithm: A simple algorithm is to loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count and if setbit count is equal to one return true else return false.
Step 1: Initialize one variable n (int n) denoting the number to be checked whether it is a power of two or not.
Step 2: Make a function isPowerOfTwo(n) and pass n as parameter(call by value). isPowerOfTwo(n) Bool isPowerOfTwo(int n)
Step 3: Inside the function Initialize one variable c (int c) equal to 0 initially.
Step 4: Check if value of n is less than zero then return false.
Step 5: Loop while the number is greater than 0 and everytime add the setbit to the variable ‘c’ and right shift n.
while(n){
if(n&1){
C++ }
n>>=1
}

Step 6: If value of c is equal to 1 return true else return false.


#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
        int c=0;
        if(n<0){
            return false;
        }
        while(n){
            if(n&1){
                c++;
            }
            n>>=1;
        }
        if(c==1){
            return true;
        }
        else{
            return false;
        }
    }

int main() {
    int n;
    cin>>n;
    if(isPowerOfTwo(n)){
        cout<<"true"<<endl;
    }
    else{
        cout <<"false"<<endl;
    }
}


*/