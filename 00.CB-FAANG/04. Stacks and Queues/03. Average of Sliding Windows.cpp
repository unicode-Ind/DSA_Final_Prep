/*
You have to given a data stream terminated by -1 and the size of sliding window. For each variation in sliding window you need to tell the average of data in current sliding window. Print 4 digits after the decimal point.

Input Format
First line contains an integer denoting the size of sliding window.
Second line has a data stream terminated by -1.

Constraints
None

Output Format
Print average of each sliding window.

Sample Input
5
51 62 24 51 79 33 72 78 84 42 -1
Sample Output
51.0000 56.5000 45.6667 47.0000 53.4000 49.8000 51.8000 62.6000 69.2000 61.8000
Explanation
None
*/

#include <iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main() {

	//alternate : circular queue, normal queue;
	//here : two pointer approach
	int k, cur, n = 0;
	cin >> k;

	vector<float> input;
	cin >> cur;
	while (cur != -1) {
		input.push_back(cur);
		n++;
		cin >> cur;
	}

	float sum = 0.0;

	int l = -1, h = -1;
	//l => till l not included
	//h => l+1 to h included
	while (h < n - 1) {
		sum += input[++h];
		if (h - l > k) {
			sum -= input[++l];
		}

		cout << fixed << setprecision(4) << sum / (h - l) << " ";
	}
	return 0;
}

/*
Average of Sliding Windows
Use queue datastructure to solve it easily.
Take elements of data stream and add to the end of queue as well as sum.
Whenever size of queue exceeds the size of window then pop element at the front and subtract from sum.
Find average at each data entry of the stream and print it
Code :


#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
public:
    // Initialize your data structure here.
    queue<int> q;
    int ms;
    int sum;

    MovingAverage(int size) {
        ms=size;
        sum=0;
    }

    double next(int val) {
        q.push(val);
        sum+=val;
        if(q.size()>ms){
            sum-=q.front();
            q.pop();
        }
        double ans=(double)(sum)/q.size();
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int ws;
    cin>>ws;
    MovingAverage odj(ws);
    int num;
    cin>>num;
    while(num!=-1)
    {
        cout<<odj.next(num)<<" ";
        cin>>num;
    }

    return 0;
}
*/