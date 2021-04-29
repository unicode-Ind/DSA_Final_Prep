#include <iostream>
#include<stack>
using namespace std;

void showBin(int n){
	stack<int> s;

	while(n){
		s.push(n&1);
		n>>=1;
	}

	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
	cout<<"\n";
}

int setbits(int n){
	int ans=0;
	while(n){
		if(n&1)
			ans++;
		n>>=1;
	}
	return ans;

	//O(no of bits)
}

int setbitsOptimised(int n){
	int ans=0;
	while(n){
		ans++;
		n&=(n-1);
	}
	return ans;

	//O(no of set bits)
}

void setBit(int &n,int i){
	int mask=1<<i;
	n|=mask;
}

bool isSet(int n,int i){
	int mask=1<<4;
	return n&=mask!=0?true:false;
}

void unsetBit(int &n,int i){
	int mask = ~(1<<i);
	n&=mask;
}

void updateBit(int &n,int i,int v){
	int mask = v<<i;
	n|=mask;
}

void clearLastiBits(int &n,int i){
	int mask = -1<<i; // -1 == ~0 == all bits set
	n&=mask;
}

void clearRange(int &n,int i,int j){
	int leftPart,rightPart;
	leftPart= -1<<(j+1);
	rightPart= (1<<i)-1;
	int mask = leftPart | rightPart;
	n&=mask;
}


int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the number :";
	cin>>n;

	cout<<"\nNo in binary rep. :";
	showBin(n);

	//no of set bits
	cout<<"\nNo of set sits :";
	cout<<setbits(n)<<endl;
	cout<<setbitsOptimised(n)<<endl;
	cout<<__builtin_popcount(n)<<"\n\n";

	//set ith bit (int is 32-bit)
	setBit(n,4); //say setting 4th bit from RHS, (numbering 0,1,2,3....)
	cout<<"\nAfter setting 4th bit :"<<n<<endl;

	//check if ith bit is set or not (say i=4 for eg)
	cout<< (isSet(n,4)==true?"Bit is set\n":"Bit not set\n");

	//unset ith bit (int is 32-bit)
	unsetBit(n,4); //say unsetting 4th bit from RHS, (numbering 0,1,2,3....)
	cout<<"\nAfter unsetting 4th bit :"<<n<<endl;

	//update ith bit to v, (v=0/1)
	int v=1; // here v=1 for e.g.
	updateBit(n,4,v); //say unsetting 4th bit from RHS, (numbering 0,1,2,3....)
	cout<<"\nAfter updating 4th bit :"<<n<<endl;


	//unset/clear last i bits (from RHS)
	clearLastiBits(n,4); // we are clearing last 4 bits
	cout<<"\nAfter clearing last 4 bits :"<<n<<endl;

	// clearing bits in range [i,j] - taken R to L
	clearRange(n,2,6); // we are clearing last 4 bits
	cout<<"\nAfter clearing Range :"<<n<<endl;

	return 0;
}