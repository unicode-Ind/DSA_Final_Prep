#include <iostream>
#include<stack>
using namespace std;

void reverse(stack<char> &st);
void print(stack<char> &st);
void insertAtBottom(char &data, stack<char> &st);

int main(int argc, char const *argv[])
{
	int t=1;
    cout<<"Number of test cases :";
    cin>>t;

    while(t--){

        stack<char> st;
        cout<<"Enter input for stack(# to end input):";
        
        char in;
        cin>>in;

        while(in!='#'){
            st.push(in);
            cin>>in;
        }

        reverse(st);
        print(st);
    }

	return 0;
}

void reverse(stack<char> &st){
    
    if(st.empty())
        return;
    
    char data=st.top();
    st.pop();

    reverse(st);
    insertAtBottom(data,st);
}

void insertAtBottom(char &data, stack<char> &st){
    if(st.empty()){
        st.push(data);
        return;
    }

    char temp=st.top();
    st.pop();

    insertAtBottom(data,st);
    st.push(temp);
}

void print(stack<char> &st){
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}