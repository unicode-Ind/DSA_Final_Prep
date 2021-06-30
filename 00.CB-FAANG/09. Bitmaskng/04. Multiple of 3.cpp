//Multiple of 3
/*
Take a binary number , if this number multiple of 3 print 1 otherwise print 0.The given number can range upto 2^100.

To finish the task , it is recommended to use one traversal of input binary String.

Input Format
The first line contains T denoting the number of testcases. Each case contains a string containing 0's and 1's.

Constraints
1<=T<=100, 1<=Length of Input String<=100

Output Format
For each test case, print 1 if string is multiple of 3, else print 0.

Sample Input
2
011
100
Sample Output
1
0
*/

#include<iostream>
using namespace std;

// 		0 	1
// a	a	b
// b	c	a
// c	b	c

char dfa(char cur_state, char cur_input) {
	if (cur_state == 'a') {
		return cur_input == '0' ? 'a' : 'b';
	} else if (cur_state == 'b') {
		return cur_input == '0' ? 'c' : 'a';
	} else {
		return cur_input == '0' ? 'b' : 'c';
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		char cur_state = 'a';
		for (char cur_input : s) {
			cur_state = dfa(cur_state, cur_input);
		}

		cout << (cur_state == 'a') << endl;
	}
	return 0;
}

/*
Editorial
X
Question : Multiple of 3

Time Complexity: O(logn)

Algorithm: The given pattern is in binary representation of the number that can be used to find if number is a multiple of 3. If difference between count of odd set bits (Bits set at odd positions) and even set bits (Bits set at even positions) is multiple of 3 then the number is multiple of 3.

Step 1: Initialize two variables : oddcount=0, evencount=0 and take a string ‘str’ as input .

Step 2: Since we have input as string , calculate total length of the string and store it in a variable len (len=str.length()).

Step 3: Loop through the whole string from right(i=len-1) to left till len>=0 and decrement the i pointer at each step.

Step 4: If the rightmost bit is set (str[i]==’1’) and Bits set at even positions i.e, the position of pointer i is even ((i- len +1)%2==0) then increment the evencount.(evencount++).

Step 5:If the rightmost bit is set (str[i]==’1’) and the Bits set at odd positions i.e, position of pointer i is odd ((i- len +1)%2!=0) then increment the oddcount.(oddcount++).

Step 6 if oddcount minus evencount modulus 3 is equal to 0 ((oddcount - evencount)%3==0), then print 1,else print 0.


#include <iostream>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--){
        string str; cin>>str;
        int odd_places = 0,even_places = 0;
        for(int i=str.length()-1;i>=0;i--){
            if(str[i] == '1'){
                if( (i - str.length() + 1)%2 == 0){
                    even_places++;
                }
                else odd_places++;
            }
        }
        if((odd_places - even_places)%3 == 0){
            cout<<"1\n";
        }
        else cout<<"0\n";
    }
    return 0;
}

*/