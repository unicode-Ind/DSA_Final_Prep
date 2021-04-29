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

const int size=61;


struct point
{
	int x,y;

	bool operator < (point& p){
		if(p.x==x) return y<p.y;

		return x<p.x;
	}

	bool operator < (point& p){
		return (x==p.x && y==p.y);
	}
};

bool cw(point a,point b,point c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0;
}

bool ccw(point a,point b,point c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;
}

bool col(point a,point b,point c){
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)==0;
}

vector<point> fun(list<point> &l){
	if(l.size()<=2) return;
	l.sort();

	int i=1,n=l.size();
	point p1= *(p.begin());
	point p2;

	for(auto it :l){
		p2=it;	
	}

	l.pop_front();
	l.pop_back();


	n=l.size();

	vector<point> up,down;
	up.pb(p1);
	down.pb(p1);

	for(auto it: l){
		if(i==n) break;

		if(i==n-1 || ccw(p1,it,p2)){
			while(up.size()>=2 && ccw([up[up.size()-2],up[up.size()-1]],it)){
				up.pop_back();
			}
			up.pb(it);
		}

		if(i==n-1 || cw(p1,it,p2)){
			while(down.size()>=2 && ccw([down[down.size()-2],down[down.size()-1]],it)){
				down.pop_back();
			}
			down.pb(it);
		}

		i++;
	}

	for(i=0;i<down.size();i++){
		up.pb(down[i]);
	}

	sort(up.begin(),up.end());
	up.resize(unique(up.begin(),up.end()) - up.begin());

	for(auto val:up){
		l.remove(val);
	}

	return up;
}

void solve(){
	int n;
	cin>>n;
	list<point> l;

	point temp;

	for (int i = 0; i < n; ++i)
	{
		cin>> temp.x >>temp.y;
		l.pb(temp);
	}

	vector< vector<point> > layers;
	std::vector<point> v;

	int i=0;
	while(l.size()>2){
		v= fun(l);

		for(auto it:v){
			layers[i].pb(it);
		}
		i++;
	} 
}

int main(int argc, char const *argv[])
{
	//cout<<"changed\n";
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t=1;
	cin>>t;

	while(t--)
	{	
		solve();

	}	
	return 0;	
}