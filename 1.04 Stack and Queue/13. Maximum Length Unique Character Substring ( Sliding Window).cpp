/*
    Given a string str, find the length of the longest substring without repeating characters.

For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
*/
/*
    Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input
the number n denoting number of elements in the array then after a new line we have the numbers of the array and then k in a new line

n < 10^6
k < 10^5
1 <= k <= n

and each element of the array is between 0 and 10^6

(Edited: In fact, n <= 10^5)

Output
print the output array

Example
Input:
9
1 2 3 1 4 5 2 3 6
3

Output:
3 3 4 5 5 5 6

*/

#include <iostream>
#include<cstring>
#include<deque>
using namespace std;

int main() {
    //string s;
    //cin>>s;

    //Brute force: O(n^3) : n^2 permutaions of sub-strings possible and each take O(n) to iterate

    //Efficient approach : Sliding window : linear time

    // we need to keep track of
      //1. max_length of string (sub_string so far)
      //2. index of current char , when it occured last (can be done using Hash_Map or array (as a map))


//abcdefcghijkzyxz
    char a[] = "abbacdeb";

    int n = strlen(a);
    int current_len = 1;
    int max_len = 1;

    int visited[256];

    for(int i=0;i<256;i++){
        visited[i] = -1;
    }


    visited[a[0]] = 0;

    for(int i=1;i<n;i++){
        int last_occ = visited[a[i]];

        //Expansion
        if(last_occ==-1||i-current_len>last_occ){
            current_len += 1;
            //max_len = max(current_len,max_len);
        }
        //Expansion + Contraction
        else{
            if(current_len>max_len){
                max_len = current_len;
            }
            current_len = i - last_occ;
        }
        visited[a[i]] = i;
    }

     if(current_len>max_len){
                max_len = current_len;
    }
    cout<<max_len<<endl;


    return 0;
}
