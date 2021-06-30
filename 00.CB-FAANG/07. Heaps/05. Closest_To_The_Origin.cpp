/*
https://leetcode.com/problems/k-closest-points-to-origin

We have a list of points on the plane. Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You print the answer in sorted order. The answer is guaranteed to be unique (except for the order that it is in.)

Input Format
First line contains single integer n Next n lines contain n pairs of x and y Last line contains single integer k

Constraints
1 <= n <=10000

Output Format
Print k lines containing 2 integers

Sample Input
3
3 3
5 -1
-2 4
2
Sample Output
-2 4
3 3
Explanation
(-2,4) and (3,3) are the 2 closest points to origin
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

#define pint pair<int,int>

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {

		int n = v.size();
		priority_queue<int> pq;

		for (int i = 0; i < n; ++i)
		{
			int x, y;
			x = v[i][0];
			y = v[i][1];

			//PQ logic
			int dist = x * x + y * y;

			if (pq.size() < k) {
				pq.push(dist);
			} else if (dist < pq.top()) {
				pq.pop();
				pq.push(dist);
			}

		}

		int threshold = pq.top();
		int i = 0, j = n - 1;

		while (i <= j) {

			int x = v[i][0];
			int y = v[i][1];

			int dist = x * x + y * y;

			if (dist <= threshold) {
				i++;
			} else {
				swap(v[i], v[j]);
				j--;
			}

		}

		vector<vector<int>> res(v.begin(), v.begin() + k);
		sort(res.begin(), res.end());
		return res;

	}
};


int main()
{
	INPUT();
	//prefer editorial

	int n, k;
	cin >> n;

	vector<pint> v;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});

	}

	cin >> k;
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		x = v[i].first;
		y = v[i].second;

		//PQ logic
		int dist = x * x + y * y;

		if (pq.size() < k) {
			pq.push(dist);
		} else if (dist < pq.top()) {
			pq.pop();
			pq.push(dist);
		}

	}

	int threshold = pq.top();
	int i = 0, j = n - 1;

	while (i <= j) {

		int x = v[i].first;
		int y = v[i].second;

		int dist = x * x + y * y;

		if (dist <= threshold) {
			i++;
		} else {
			swap(v[i], v[j]);
			j--;
		}

	}

	vector<pint> res(v.begin(), v.begin() + k);
	sort(res.begin(), res.end());

	for (auto cur : res)
		cout << cur.first << " " << cur.second << endl;


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}

/*
Editorial
X
What we can use here is a min heap

We can store the distance of various points in the heap and maintain its size to be of K . At the end we can just pop out and print the k most near points.

Just need to have a pair of point index and its distance and push it in heap and make the heap according to distance.

CODE:

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n=points.size();
        priority_queue<int> q;
        for(int i=0;i<n;i++){
            int dist=pow(points[i][0],2)+pow(points[i][1],2);
            if(q.size()<K || dist<q.top() ){
                if(q.size()==K){
                    q.pop();
                }
                q.push(dist);
            }
        }
        int num=q.top();
        int i=0,j=n-1;
        while(i<=j){
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(dist<=num){
                i++;
            }
            else{
                swap(points[i],points[j]);
                j--;
            }
        }
        points.erase(points.begin()+K,points.end());
        return points;
    }

int main() {
    int n,k;
    cin>>n;
    vector<vector<int>> points;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        points.push_back(temp);
    }
    cin>>k;
    points=kClosest(points,k);
    sort(points.begin(),points.end());
    for(int i=0;i<k;i++){
        cout<<points[i][0]<<" "<<points[i][1]<<endl;
    }
    return 0;
}
*/