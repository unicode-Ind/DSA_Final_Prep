#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main()
{
    stack<string> s;

    s.push("First");
    s.push("Second");
    s.push("Third");

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }


    /*
    *******  Non-member function overloads  *****

    std::stack::swap
void swap (stack& x) noexcept
Swap contents
Exchanges the contents of the container adaptor (*this) by those of x.

This member function calls the non-member function swap (unqualified) to swap the underlying containers.

The noexcept specifier matches the swap operation on the underlying container.

    */
  std::stack<int> foo,bar;
  foo.push (10); foo.push(20); foo.push(30);
  bar.push (111); bar.push(222);
  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';
    cout<<foo.top()<<endl;

  foo.swap(bar);

    cout<<foo.top()<<endl;
  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';



    return 0;
}
