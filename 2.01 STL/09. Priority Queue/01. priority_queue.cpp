#include <iostream>
#include <queue>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
    freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif

    priority_queue<int> pq_max; //max priority queue
    priority_queue<int, vector<int>, greater<int> >  pq; //min priority queue

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int no;
        cin >> no;
        pq.push(no); //O(LogN)
    }

    //Remove the elements from the heap
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}