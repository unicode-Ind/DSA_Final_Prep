#include<iostream>
#include<vector>
using namespace std;

template<typename T>
   // data type T is used
   //template<typename T,typename X>  can be used also
class Stack{
    vector<T> v;
    //vector<X> v2;
public:
    void push(T data){v.push_back(data);}

    bool empty()
    {
        return v.size()==0;
    }
    void pop()
    {
        if(!empty())
            v.pop_back();
    }

    T top(){return v[v.size()-1];}
};

int main()
{
    Stack<char> s;

    //stack<T> s;    T can be int ,float,string ,pair,list.....

    for(int i=70;i<75;i++)
        s.push(i);

    while(!s.empty())
    {
        cout<<s.top()<<" - ";
        s.pop();
    }

    return 0;
}
