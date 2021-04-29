//Generate	all	the	strings	of	length	n	drawn	from	0...	k	–	1
//rec rel : k T(n-1)+d
// O(k^n)

#include <iostream>
using namespace std;

void binary(char a[],int n,int k){
	if(n==0){
		cout<<a<<endl;
		return;
	}

	for(int i=0;i<k;i++){
		a[n-1]=i+'0';
		binary(a,n-1,k);
	}

}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	char *a=new char[n];

	binary(a,n,k);
	return 0;
}
