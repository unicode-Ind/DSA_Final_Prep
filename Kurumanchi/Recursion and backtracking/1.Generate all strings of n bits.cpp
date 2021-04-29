#include <iostream>
using namespace std;

void binary(char a[],int n){
	if(n==0){
		cout<<a<<endl;
		return;
	}

	a[n-1]='0';
	binary(a,n-1);


	a[n-1]='1';
	binary(a,n-1);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char *a=new char[n];

	binary(a,n);
	return 0;
}

//rec rel : 2 T(n-1)+d
// O(2^n)
