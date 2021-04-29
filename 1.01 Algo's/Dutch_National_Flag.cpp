#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)

//const double PI=acos(-1); 
#define vint vector<int>
#define vfloat vector<float>

#define pb push_back

const long long mod=1e9;

#define PI 3.14159  
#define vint vector<int>
#define vfloat vector<float>

void read(vector<int>&v,int n);

void solve3(){
 
	//for 3 colors (0,1,2)
	int n;
	cin>>n;
	vector<int> input(n);
	read(input,n);

	//algo
	int l=0,m=0,h=n-1;
	// for 0,1,2 resp

	while(m<=h){
		switch(input[m]){
			case 0:
				swap(input[l++],input[m++]);
				break;
			case 1:
				m++;
				break;
			case 2:
				swap(input[m],input[h--]);
				break;
		}
	}

	for(int i:input)
		cout<<i<<" ";

}

void solve4(){

	/*0 0 0 0 1 2 3

	        l
	          m
	            n
	          o
 
	//for 4 colors (0,1,2,3)*/

	int n;
	cin>>n;
	vector<int> input(n);
	read(input,n);

	//algo
	int l=0,m1=0,m2=0,h=n-1;
	// for 0,1,2,3 resp

	while(m2<=h){
		switch(input[m2]){
			case 0:
				swap(input[l],input[m2]);
				break;
			case 1:
				swap(input[m1],input[m2]);
				break;
			case 2:
				break;
			case 3:
				swap(input[m2],input[h]);
				break;
		}

		while(input[l]==0){
			l++;
			m1=m2=l;
		}
		while(input[m1]==1){
			m1++;
			m2=m1;
		}
		while(input[m2]==2){
			m2++;
		}
		while(input[h]==3)
			h--;
	}

	for(int i:input)
		cout<<i<<" ";

}

int main(int argc, char const *argv[])
{
	//cout<<"changed\n";
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t=1;
	cin>>t;

	while(t--)
	{	
		//cout<<solve()<<endl;
		solve3();cout<<endl;
		//solve4();cout<<endl;

	}	
	return 0;	
}

void read(vector<int>&v,int n){
	//int inp;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
}