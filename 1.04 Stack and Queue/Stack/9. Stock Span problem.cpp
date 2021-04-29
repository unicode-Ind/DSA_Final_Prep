#include <iostream>
#include <stack>
using namespace std;

void printSpan(int arr[], int n){
    stack<int> s;
    int ans[100] = {};
    for(int day = 0; day < n; ++day){
        int curPrice = arr[day];
        while(s.empty() == false && arr[s.top()] < curPrice){
            s.pop();
        }

        int betterDay = s.empty() ? 0 : s.top();
        //to check for first day as we don't have anything to subtract from it
        int span = day - betterDay;
        ans[day] = span;
        s.push(day);
    }

    for(int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    }

    //algo
    /*
            for(day;(0 to n)){
                while(s.top()<cur_price) pop();

                    compute span;
                    push cur_price into stack;
            }

        //span = curr_index - index_g (which is at top);
    */
}

int main(){

    int n = 7;
    int arr[100] = {100, 80, 60, 70, 60, 75, 85};

    //Brute- force approach time: O(n^2)  and space : O(n) (if span array is created) or we can use a variable span also (instead of array) : O(1)
    /*
        int span[n];
        span[0]=1 ,  print 1
        for(int i=1;i<n;i++)
        {
            span[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(a[j]<=a[i])
                    span[i]++;
                else
                    break;
            }
        }
    */


    //Optimised app: time : O(n)  and space: O(n)
    // observation : we need nearest greater elememt (price)
    printSpan(arr, n);

    return 0;
}
