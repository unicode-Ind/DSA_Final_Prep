#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<char> s;
	string input,output=NULL;
	cin>>input;

	char cur,cur2;
	int n=input.length();
	for (int i = 0; i < n; ++i)
	{	
		cur=input[i];
		if( (cur>='a'&& cur<='z') || (cur>='A'&& cur<='z') || (cur>='0'&& cur<='9') )
			output+=cur;
		else if(cur=='' || )
	}

	return 0;
}