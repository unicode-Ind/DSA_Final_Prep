#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int>&s,stack<int>&temp,int n)
{
        while(n--)
        {
            temp.push(s.top());
            s.pop();
        }
}

void reverseStack(stack<int>&s)
{
    stack<int> temp;
    int n=s.size();

    for(int i=0;i<n;i++)
    {
        int x=s.top();
        s.pop();
        transfer(s,temp,n-i-1);
        s.push(x);
        transfer(temp,s,n-i-1);
    }
}

int main()
{
// Three ways: 1. 2 stacks, 2. using 1 stack , 3. Recursion
//(1) 2 extra stacks A->B->C then C->A (tarnsfer means pop and transfer)


//(2) 1 extra stack  A->B  B will countain reverse, if done simultaneously OR pop top-> hold it-> A to B -> push holded one in A -> B to A, now repeat it for n-1 elements
      /*
      for(int i=0;i<s.size();i++)
      {
      int x=s.top();
      s.pop();

      int vacate=n-i-1;
      for(0:n)
      push s-> temp stack (empty s);

      s.push(x);
      push temp-> s stack (empty temp);
      }
      */

      stack<int> s;

    for(int i=1;i<6;i++)
        s.push(i);

        reverseStack(s);

        while(!s.empty())
        {
        cout<<s.top()<<endl;
        s.pop();
        }
    return 0;
}
