#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);

int nxn = 1000000;
int n;
void solve();
void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvin/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvin/Desktop/Current/output.txt", "w", stdout);
#endif
}

int prec(char cur) {
	if (cur == '^') return 5;
	if (cur == '*' or cur == '/') return 4;
	if (cur == '+' or cur == '-') return 3;

	return -1;
}

int main()
{
	INPUT();
	ll t = 1;
	cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}

void solve() {
	string infix;
	cin >> infix;
	//reverse(infix.begin(), infix.end());

	vector<char> postfix;
	stack<char> stack;

	stack.push('#');

	for (char cur : infix) {
		if ((cur >= 'a' and cur <= 'z') or (cur >= 'A' and cur <= 'Z') or (cur >= '0' and cur <= '9')) {
			postfix.push_back(cur);
		} else if (cur == '(') {
			stack.push(cur);
		} else if (cur == ')') {
			while (stack.top() != '#' and stack.top() != '(') {
				postfix.push_back(stack.top());
				stack.pop();
			}
			if (stack.top() == '(')
				stack.pop();
		} else {
			int curPrec = prec(cur);

			while (stack.top() != '#' and curPrec <= prec(stack.top())) {
				postfix.push_back(stack.top());
				stack.pop();
			}
			stack.push(cur);
		}

	}

	while (stack.top() != '#') {
		postfix.push_back(stack.top());
		stack.pop();
	}

	//reverse(postfix.begin(), postfix.end());

	for (char cur : postfix)
		cout << cur;
	cout << endl;

}


//com.aliendictionary.nitj_btechsyllabus