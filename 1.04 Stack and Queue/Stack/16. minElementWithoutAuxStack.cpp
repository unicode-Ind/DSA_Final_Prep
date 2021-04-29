#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);

class Stack
{
	stack<int> st;
	int min = -1e7;
public:

	int getMin() {
		return min;
	}

	void push(int value) {
		if (st.empty()) {
			st.push(value);
			min = value;
			return;
		}

		if (value < min) {
			st.push(2 * value - min);
			min = value;
		} else {
			st.push(value);
		}
	}

	void pop() {
		if (s.empty()) return;

		int topEle = s.top();
		s.pop();

		if (topEle < min) {
			min = 2 * min - topEle;
		}
	}

	int top() {

		if (st.empty())
			return INT_MIN;
		/*
		int producerMin = min;
		int topEle = s.top();

		if(topEle < producerMin){
			producerMin = 2*producerMin - topEle;

			topEle = (topEle+producerMin)>>1;

		}
		return topEle;
		*/

		//see topEle = min if(top<min)
		//	else topEle= top
		//				=> max(min,s.top());
		return max(min, st.top());
	}

};

int main()
{
	Stack s;

	return 0;
}
