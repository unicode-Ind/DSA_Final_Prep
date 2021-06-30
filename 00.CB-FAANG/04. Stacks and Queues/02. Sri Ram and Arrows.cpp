/*
The fierce battle of Lord Sri Ram and Ravan is going on. They both are constantly shooting arrows towards each other not necessarily turn by turn. It means that they can shoot multiple arrows at a time.

You are given an array of integers. Here the sign of the integer represents the direction of the arrow, '+' : right and '-' : left. The absolute value represents the size of the arrow. A collisions will take place if an arrow is moving towards right and the next arrow moves in the left direction. At each collision the arrow with larger size destroys the smaller sized arrow and continues the path. If both the arrows have same size then they both are destroyed.

Note: Arrows moving in the same direction (-,- +,+) never collide and neither do the arrows moving away from each other (-,+) collide. The only arrows that collide are the arrows that move towards each other (+,-).

Your task is to help Lord Ram decode the final state of the arrows, So that he can know how many more arrows he needs to shoot.

Input Format
1st line represents the number of elements N in the given array. Next line contains N integers

Constraints
N<=100000
1<= Size of Arrows <=1000

Output Format
Print on a single line space separated, the final state of the arrows

Sample Input
10
1 -1 2 -5 7 -6 -5 3 -5 10
Sample Output
-5 7 10
Explanation
First -1 and 1 both get destroyed, then we add 2 but on the next step -5 will destroy 2, next we encounter 7 where no collision takes place then we encounter -6 which gets destroyed by 7 and the same thing happens to -5 as well, then we encounter 3, nothing happens but on the next step we encounter -5 which successfully destroys 3 but gets destroyed by 7 after which we simply add 10 which does nothing. The numbers in bold are the arrows which do not get destroyed by any other arrow


*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int input;
	stack<int> stk;

	for (int i = 0; i < n; i++) {
		cin >> input;

		bool shdBePush = true;

		// if(stk.empty()){
		//     stk.push(input);
		//     continue;
		// }

		//collision only if stack.top +ve and cur = -ve
		while (!stk.empty() and stk.top() > 0 and input < 0) {
			if (stk.top() == abs(input)) {
				stk.pop();
				shdBePush = false;
				break;
			} else if (stk.top() < abs(input)) {
				stk.pop();
			} else {
				shdBePush = false;
				break;
			}
		}

		if (shdBePush)
			stk.push(input);

	}

	vector<int> ans;
	while (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}

	reverse(ans.begin(), ans.end());
	for (int c : ans) {
		cout << c << " ";
	}

	return 0;
}

/*

*/