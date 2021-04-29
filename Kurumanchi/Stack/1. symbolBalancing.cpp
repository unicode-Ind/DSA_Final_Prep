//CAUTION : mistake was at line 37 : cur2 should have opening symbol => order : check(cur2,cur)

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool check(char a,char b){
	return (a=='(' && b==')') ||(a=='{' && b=='}') || (a=='[' && b==']');
}

int main(int argc, char const *argv[])
{
	stack<char> s;
	string str;
	cin>>str;

	char cur,cur2;
	bool flag=true;
	int n=str.length();
	for (int i = 0; i < n; ++i)
	{	cur=str[i];
		if(cur=='('   || cur=='{' || cur=='['){
			s.push(cur);
			//cout<<s.top()<<"\n";
		}
		else if (cur==')'   || cur=='}' || cur==']'){
			if(s.empty()){
				flag=false;
				//cout<<"1\n";
				break;
			}
			else{

				cur2=s.top(); // can contain only opening braces character
				s.pop();
				if(!check(cur2,cur)){
					flag=false;
					//cout<<cur<<" "<<cur2<<" 2\n";
					break;
				}
			}
		}
	}

	if(s.empty() && flag)
		cout<<"\nExpression is balanced";
	else
		cout<<"\nUnbalanced Expression";
	//cout<<"\n"<<s.empty()<<" "<<flag;
	return 0;
}