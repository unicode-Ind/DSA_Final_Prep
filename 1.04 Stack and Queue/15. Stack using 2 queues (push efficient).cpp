#include <iostream>
//#include<cstring>
#include<queue>
using namespace std;

class Stack{
queue<int> primary,secondary;
//primary=new queue<int>;
//secondary=new queue<int>;
public:
    void Push(int data)
    {
        primary.push(data);
    }

    void Pop()
    {
        if(!primary.empty()){
        while(primary.size()!=1)
        {
            secondary.push(primary.front());
            primary.pop();
        }
        primary.pop();

        //swap primary and sec
        swap(primary,secondary);
        }
    }

    int Top()
    {
       if(!primary.empty()){
        while(primary.size()!=1)
        {
            secondary.push(primary.front());
            primary.pop();
        }
        int t=primary.front();
         secondary.push(primary.front());
            primary.pop();

         swap(primary,secondary);

        return t;
    }
};


int main() {
    Stack s;

    s.Push(1);
    cout<<s.Top()<<endl;

    s.Push(2);
    cout<<s.Top()<<endl;
    s.Push(3);
    cout<<s.Top()<<endl;
    s.Push(4);
    cout<<s.Top()<<endl;

    s.Pop();
    cout<<s.Top()<<endl;
    return 0;
}
