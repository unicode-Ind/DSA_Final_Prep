/*
Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

Input Format
Single line containing an integral value 'n'.

Constraints
1<=n<=11

Output Format
Print the balanced parentheses strings with every possible solution on new line.

Sample Input
2
Sample Output
()()
(())
*/

#include<iostream>
using namespace std;

void print(int n, char *out, int curIdx, int open, int close) {
	if (curIdx == 2 * n) {
		out[2 * n] = '\0';
		cout << out << endl;
		return;
	}

	//the order of close and open will change order of output
	if (close < open) {
		out[curIdx] = ')';
		print(n, out, curIdx + 1, open, close + 1);
	}
	if (open < n) {
		out[curIdx] = '(';
		print(n, out, curIdx + 1, open + 1, close);
	}

}

int main() {
	int n;
	cin >> n;

	char out[2 * n + 1];
	print(n, out, 0, 0, 0);
	return 0;
}

/*
Editorial
X
Algorithm:

Keep track of counts of open and close brackets.

Initialize these counts as 0.

Recursively call the generateParenthesis() function until open bracket count is less than the given n.

If open bracket count becomes more than the close bracket count, then put a closing bracket and recursively call for the remaining brackets.

If open bracket count is less than n, then put an opening bracket and call _printParenthesis() for the remaining brackets.

Lang - Cpp

#include <iostream>
using namespace std;

void generateParenthesis(int n, int openB, int closeB, string str) {
    if(closeB == n) {
        cout<<str<<endl;
        return;
    }
    if(openB > closeB) {
        generateParenthesis(n, openB, closeB+1, str+')');
    }
    if(openB < n) {
        generateParenthesis(n, openB+1, closeB, str+'(');
    }
}

int main(int argc, char const *argv[])
{
    int n;    cin >> n;
    generateParenthesis(n, 0, 0, "");
    return 0;
}

Lang - Java

public static void printParenthesis(int n, String ans, int close, int limit, int open) {

        if (n == 0) {
            System.out.println(ans);
            return;
        }

        if(close < open && open != 0) {
            printParenthesis(n - 1, ans + ")", close + 1, limit, open);
        }
        if (open < limit) {
            printParenthesis(n - 1, ans + "(", close, limit, open + 1);
        }
    }
Python Code
class Solution:
    def generate(self,s,open,close,n):
        if close==n:
            self.res.append(s)
            return
        if open < n:
            self.generate(s+'(',open+1,close,n)
        if close < open:
            self.generate(s+')',open,close+1,n)

    def generateParenthesis(self, n: int):
        self.res = []
        self.generate("",0,0,n)
        return self.res
*/