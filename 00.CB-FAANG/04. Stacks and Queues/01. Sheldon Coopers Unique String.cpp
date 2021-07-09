/*
https://leetcode.com/problems/remove-duplicate-letters/submissions/

Sheldon Cooper has a string which consists only of lowercase letters. But, the problem is that he don't like duplicate characters ,so he want to remove duplicate letters so that every letter appears once. Since he is busy with some work at University, he needs your help.
So, you have to print the lexicographically minimum possible string with all unique characters.

Note: You can remove a character only if it appears more than one time.

Input Format
The first and the only line of input contains a string s-the input string.

Constraints
1<=|s|<=10^6

Output Format
Print a single string equal to the lexicographically minimum string possible with all unique characters.

Sample Input
babc
bbbacb
bbbacdbbb
Sample Output
abc
acb
acdb

*/

#include <bits/stdc++.h>
using namespace std;

void fun();
void fun_easy();

int main() {

	//fun();
	fun_easy();
	// cout<<"end"<<endl;

	return 0;
}

void fun() {
	string s;
	cin >> s;

	bool occurredBefore[26] = {false};
	int last_Occurrence[256];
	// memset(last_Occurrence,-1,sizeof(last_Occurrence));
	//find last occurence
	for (int i = 0; i < s.size(); i++) {
		last_Occurrence[s[i] - 'a'] = i;
	}

	stack<char> stk;

	for (int i = 0; i < s.size(); i++) {

		if (occurredBefore[s[i] - 'a'])
			continue;

		while (!stk.empty() && (stk.top() >= s[i] && last_Occurrence[stk.top() - 'a'] > i)) {
			occurredBefore[stk.top() - 'a'] = false;
			stk.pop();
		}
		stk.push(s[i]);
		occurredBefore[s[i] - 'a'] = true;
	}

	vector<char> ans;
	while (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}

	reverse(ans.begin(), ans.end());
	for (char c : ans) {
		cout << c;
	}
}

void fun_easy() {
	string s;
	cin >> s;
	stack<char> stk;

	bool stackContainsAlready[256] = {false};
	int frequencyLeft[256] = {};
	for (char cur : s)
		frequencyLeft[cur]++;

	for (char cur : s) {
		frequencyLeft[cur]--;

		if (stackContainsAlready[cur])
			continue;

		while (!stk.empty() and stk.top() > cur and frequencyLeft[stk.top()] > 0) {
			stackContainsAlready[stk.top()] = false;
			stk.pop();
		}

		stk.push(cur);
		stackContainsAlready[cur] = true;
	}

	vector<char> ans;
	while (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}

	reverse(ans.begin(), ans.end());
	for (char c : ans) {
		cout << c;
	}
}

/*
Algorithm:
1.For every character in a to z,store the index of last occurrence of that character in the string.For that just iterate from left to right and make last index of current character to be equal to current index.
2.In stack,store characters that have occurred that have occurred till now(Obviously stack is initally empty).Also,make an array that stores whether or not a character is in stack.
3.Now,iterate from left to right,for every index one of the four cases arise:
a.If current character is already in stack,do nothing.
b.If stack is empty,just push current character to the stack and mark that this current is present in the stack.
c.If element at the top of the stack is smaller than current character or current index is greater than last index of character at the top of the stack,just insert current character to the stack and mark that this character is in stack..
d.Else,as a long as stack is not empty and last index of the character at the top of the stack is greater than current index,then pop the element from the stack and make its occurrence in the stack to be false.Finally,any of the b) or c) condition will become true.So do accordingly.
4.In the end,stack will contain the lexicographically minimum string but in reverse order.So,one by one pop from stack and add it to the resultant string and then reverse that string.
Code:


#include <iostream>
#include <stack>
using namespace std;
#define N 1000001
#define P(a,n)for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
bool presentInStack[26]={0};
int lastIndex[26]={0};
char ans[30];
int k;

void Calculate(char *a){

    stack<char> s;
    // Calculate the last Index
    for(int i=0;a[i]!='\0';i++){
        lastIndex[a[i]-'a'] = i;
    }

    for(int i=0;a[i]!='\0';i++){
        char ch = a[i];

        if(!presentInStack[ch-'a']){
            while(!s.empty() && ch<s.top() && lastIndex[s.top()-'a']>i){
                presentInStack[s.top()-'a']=false;
                s.pop();
            }
            s.push(ch);
            presentInStack[ch-'a']=true;
        }
    }

    k = s.size();

    ans[k--] = '\0';
    while(!s.empty()){
        ans[k--]=s.top();
        s.pop();
    }
    cout<<ans<<endl;
}

int main(){
    char s[N];
    cin>>s;

    Calculate(s);

    return 0;
}

Time Complexity:O(n) where n is the length of the string.

*/