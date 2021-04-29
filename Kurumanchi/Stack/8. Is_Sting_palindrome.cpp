#include <iostream>
#include<stack>
using namespace std;

bool solve();

int main(int argc, char const *argv[])
{
	int t=1;
    cout<<"Number of test cases :";
    cin>>t;

    while(t--){
        if(solve())
            cout<<"Palindrome\n";
        else
        {
            cout<<"Not Palindrome\n";
        }
        
    }

	return 0;
}

bool solve(){
    string input;
    cin>>input;

    int l=0,r=input.length()-1;

    while(l<r){
        if(input[l]!=input[r])
            return false;
        
        l++;
        r--;
    }

    return true;

}