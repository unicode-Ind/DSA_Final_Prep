/*
Given an string and pattern. print the starting index of every sub-string in entered string which matches exactly with entered pattern
input: aabaacaadaabaaabaa aaba (string, pattern)
output: 0,9,13
*/

#include<iostream>
#include<cstring>

using namespace std;
int main(int argc, char const *argv[])
{
	string str,pattern;
	cin>>str>>pattern;

	int size_str=str.size();
	int size_pat=pattern.size();
	int i,j;

	/*
	//first try
	for(i=0;i<=size_str-size_pat;){
		for(j=0;j<size_pat;)
		{
			if(str[i++]!=pattern[j++])
				break;
		}

		i=i-j+1;
		if(j==size_pat)
			cout<<i-1<<",";
	}
	*/

	//better way of writing above
	for(i=0;i<=size_str-size_pat;i++){
		for(j=0;j<size_pat;j++)
		{
			if(str[i+j]!=pattern[j])
				break;
		}
		if(j==size_pat)
			cout<<i<<",";
	}

	return 0;
}
