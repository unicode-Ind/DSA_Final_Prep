#include <iostream>
#include<cstring>
#include<deque>
using namespace std;

int main() {

    string s;
    cin>>s;
    int a[256];
    memset(a,0,sizeof(a));
    int i=0;
    char ch;

    deque<char> q;

     while(i<=s.size())
     {
       ch=s[i++];
       a[ch]++;
       if(a[ch]==1)
       q.push_back(ch);
       while(!q.empty() && a[q.front()]>1)
                    q.pop_front();
       if(q.empty())
        cout<<"-1 ";
       else
        cout<<q.front()<<" ";
     }
    return 0;
}
