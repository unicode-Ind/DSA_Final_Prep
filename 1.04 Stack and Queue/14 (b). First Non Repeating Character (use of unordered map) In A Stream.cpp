#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int main() {

    queue<char> q;
    char ch;
    unordered_map<char,int> mp;

    cin>>ch;

     while(ch!='.')
     {
       mp[ch]++;
       q.push(ch);
       while(!q.empty() && mp[q.front()]>1)
                    q.pop();
       if(q.empty())
        cout<<"-1 ";
       else
        cout<<q.front()<<" ";

        cin>>ch;
     }
    return 0;
}
