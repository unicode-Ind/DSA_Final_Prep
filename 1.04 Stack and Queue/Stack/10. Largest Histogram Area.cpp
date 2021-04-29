#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main()
{
    //BRUTE FORCE ; O(n^2)
    // two indexes i and j ,b/w i and j find min_height
    // area = (j-1)*min_height and hence max_area out of all

    //Divide and Conquer : O(nlog(n))  //TO do

    //Stack based soln : O(n)
        /*
            1. Push the current bar into stack , if it is higher in value or equal than s.top()
            2. OTHERWISE : pop all the bars of greater height

            note: During pop , when popping, we consider current bar as min height bar
                : area= min_h * (r-l-1)
                : area = min_h * right     //when stack s empty (why?): spl case consider bar (3 2 1 2 3) for this
        */

        /*
    Given an array representing height of bar in bar graph, find max histogram
 * area in the bar graph. Max histogram will be max rectangular area in the
 * graph.
 *
 * Maintain a stack
 *
 * If stack is empty or value at index of stack is less than or equal to value at current
 * index, push this into stack.
 * Otherwise keep removing values from stack till value at index at top of stack is
 * less than value at current index.
 * While removing value from stack calculate area
 * if stack is empty
 * it means that till this point value just removed has to be smallest element
 * so area = input[top] * i
 * if stack is not empty then this value at index top is less than or equal to
 * everything from stack top + 1 till i. So area will
 * area = input[top] * (i - stack.peek() - 1);
 * Finally maxArea is area if area is greater than maxArea.
 *
 *
 * Time complexity is O(n)
 * Space complexity is O(n)
 *
        */
    return 0;
}
