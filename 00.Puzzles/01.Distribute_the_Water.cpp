/*
	Author : Arvinder Singh
	https://www.geeksforgeeks.org/puzzle-distribute-the-water/
*/

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void INPUT()
{ 
#ifndef ONLINE_JUDGE
  freopen("C:/Users/arvindersingh/Desktop/Current/input.txt", "r", stdin);
  freopen("C:/Users/arvindersingh/Desktop/Current/output.txt", "w", stdout);
#endif
}

#define ll long long

bool valid(int c1,int c2,int c3){
	return ((c1>=0 and c1<=3) and
			(c2>=0 and c2<=5) and 
			(c3>=0 and c3<=3));
}

void solve() {

	int c1=0,c2=0,c3=8;
	map<vector<int>,bool> visited;
	queue<vector<int>> q;
	visited[{0,0,8}]=true;
	q.push({[0,0,8]});

	int steps = 1;
	while(!q.empty()){
		int cs = q,size();
		while(cs--){
			auto cur = q.front();
			q.pop();
			
		}

		steps++;

	}

	return -1;

	
}

int main(int argc, char const *argv[])
{
	FIO
	INPUT();

	ll t = 1;
	cin >> t;

	while (t--)
	{
		solve();

	}
	return 0;
}
