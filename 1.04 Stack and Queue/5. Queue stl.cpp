#include<iostream>
#include<queue>

#include<iomanip>
using namespace std;

int main()
{
    queue<char> q;

    for(int i=65;i<75;i++)
        q.push(i);

    cout<<setw(8)<<"Front"<<setw(8)<<"Back";
    cout<<endl;
    while(!q.empty())
    {
        cout<<setw(8)<<q.front()<<setw(8)<<q.back();
        cout<<endl;
        q.pop();
    }

    return 0;
}
