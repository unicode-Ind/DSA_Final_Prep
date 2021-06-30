/*
	Consider a string S, the task is to find if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
If not possible, return the empty string else return the output string.

Input Format
A single line contains the string.

Constraints
Note: The String will consist of lowercase letters and have length in range [1, 500].

Output Format
Print the Output string if possible else print empty string

Sample Input
S = "aab"
Sample Output
aba
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();


int main()
{
	INPUT();
	string s;
	cin >> s;

	int freq[26] = {};
	for (char c : s)
		freq[c - 'a']++;

	priority_queue<pair<int, char>> pq;
	for (int i = 0; i < 26; ++i)
	{
		if (freq[i])
			pq.push({freq[i], i + 'a'});
	}

	string ans = "";
	while (!pq.empty()) {

		if (pq.size() > 1) {
			auto h1 = pq.top();
			pq.pop();
			ans.push_back(h1.second);

			auto h2 = pq.top();
			pq.pop();
			ans.push_back(h2.second);

			if (h1.first > 1)
				pq.push({h1.first - 1, h1.second});

			if (h2.first > 1)
				pq.push({h2.first - 1, h2.second});

		} else if (pq.top().first > 1) {
			ans = "";
			pq.pop();
		} else {
			ans.push_back(pq.top().second);
			pq.pop();
		}

	}

	cout << ans;

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}

/*
Editorial
X
Algorithm To solve this, we will follow these steps −

Make a priority queue of integer character pairs called pq, define one map m

n := size of the string

store the character frequency in map m

for each key-value pair p in m

insert (integer part of p, character part of p)

ans := empty string

while pq is not empty

set one := top pair from pq, and delete the top pair from pq

if pq is empty, then

if integer part of one > 1, then return empty string

ans := ans + character part of one

return ans

two := top pair from pq, and delete the top pair from pq

ans := ans + character part of one

ans := ans + character part of two

increase integer part of one and two by 1

if integer part of one is not 0, then insert one into pq

if integer part of two is not 0, then insert one into pq

return ans

Code:


#include<bits/stdc++.h>
using namespace std;
string reorganizeString(string s) {
    int freq[26]={0};
    for(int i=0;i<s.length();i++)
    {
        freq[(int)(s[i]-'a')]++;
    }

    priority_queue<pair<int,char>> q;
    for(int i=0;i<26;i++)
    {
        if(freq[i]>0)
        {
            q.push(make_pair(freq[i],(char)('a'+i)));
        }
    }
    string ans="";

    while(!q.empty())
    {
        if(q.size()>=2)
        {
            pair<int,char>p1;
            pair<int,char>p2;
            p1=q.top();
            q.pop();
            p2=q.top();
            q.pop();
            ans+=p1.second;
            ans+=p2.second;
            p1.first--;
            p2.first--;
            if(p1.first>0)
                q.push(p1);
            if(p2.first>0)
                q.push(p2);
        }
        if(q.size()==1)
        {
            if(q.top().first>1)
            {
                return "";
            }
            else
            {
                ans+=q.top().second;
                q.pop();
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<reorganizeString(s);
}

*/