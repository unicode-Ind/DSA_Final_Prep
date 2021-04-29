#include<iostream>
#include<list>
using namespace std;

template<typename T>
class Queue{
    list<T> qu;
    int cs;
    //no need of max_size for list , list is ever growing ds
    //but optionally we can add max_size
public:
    //constructor
    Queue()
    {
        this->cs=0;
    }

   // bool isFull(){return cs==ms;}

    bool isEmpty(){return cs==0;}

    void push(T data)
    {
        qu.push_back(data);
        cs++;
    }

    void pop()
    {
        if(!isEmpty())
        {
            cs--;
            this->qu.pop_front();
        }
    }

    T getFront(){return this->qu.front();}
};

int main()
{
    //For circular queue
    //front=(front+1)%n;
    //Rear=(Rear+1)%n;

    //for this we need two more parameters : current size (cs) and max_size (ms)
    // cs < ms should be true for insertion

    //why cs and ms ?
    //Ans: we don't need to care about front and rear position with these

    Queue<int> q;
    //why not q(); ???
    //Queue<int> q(6); also valid

    for(int i=0;i<7;i++)
        q.push(i*2);

    while(!q.isEmpty())
    {
        //e.empty , q.front in stl
        cout<<q.getFront()<<" ";
        q.pop();
    }

    return 0;
}
