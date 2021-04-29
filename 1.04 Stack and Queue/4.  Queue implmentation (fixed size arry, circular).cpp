#include<iostream>
using namespace std;

template<typename T>
class Queue{
    T *arr;
    int f,r,ms,cs;
public:
    //constructor
    Queue(int default_size=10)
    {
        f=0;
        ms=default_size;
        r=ms-1;
        arr=new T[ms];
        cs=0;
    }

    bool isFull(){return cs==ms;}

    bool isEmpty(){return cs==0;}

    void push(T data)
    {
        //Enqueue which inserts data at rear +1
        if(!isFull())
        {
            r=(r+1)%ms;
            arr[r]=data;
            cs++;
        }
    }

    void pop()
    {
        if(!isEmpty())
        {
            f=(f+1)%ms;
            cs--;
        }
    }

    T getFront(){return arr[f];}
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
