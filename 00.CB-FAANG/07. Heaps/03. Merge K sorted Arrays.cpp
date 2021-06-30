/*
Given K sorted arrays each with N elements merge them and output the sorted array

Input Format
First line contains 2 space separated integers K and N.
Next lines contain K*N space separated integers

Constraints
Elements of array <= |10^15|
N <= 10^5
K <= 10

Output Format
Single line consisting of space separated numbers

Sample Input
3 4
1 3 5 7 2 4 6 8 0 9 10 11
Sample Output
0 1 2 3 4 5 6 7 8 9 10 11
Explanation
If we were to combine all the arrays into one and then sort it , the output would be as above.


*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

#define ppi pair<ll, pair<int, int>


int main()
{
	INPUT();

	int n, k;
	cin >> k >> n;

	vector<vector<ll>> v(k, vector<ll>(n, 0));

	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	priority_queue<ppi>, vector<ppi >>,  greater<ppi >> > pq;

	//value, {which array, which index}

	for (int i = 0; i < k; ++i)
	{
		pq.push({v[i][0], {i, 0}});
	}

	//int total = n * k;

	vector<ll> res;
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		res.push_back(cur.first);
		//cout << cur.first << " ";

		int  i = (int)cur.second.first;
		int  j = (int)cur.second.second + 1;

		if (j < n) {
			ll val = v[i][j] ;
			pq.push({val, {i, j}});
		}

	}

	for (ll cur : res)
		cout << cur << " ";

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
Algorithm
Make a priority queue where each node stores three values - the element itself , its row no. and its col no.
Push the first elements of all the rows into this priority queue with their corresponding row and column info.
One by one , take nodes out of this priority queue and insert their values into the final sorted array.
Also push the next element of the same row using the other information into the priority queue.
Repeat this process till the priority queue gets empty.
C++ Code

#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int, pair<int, int>> //Pair to store <Element , < RowNumber , ColNumber > >

vector<int> mergeKSortedArrays(vector<vector<int>> v)
{
    int k = v.size();
    int n = v[0].size();

    vector<int> res;

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for (int i = 0; i < k; i++)
    {
        //Push the first elements of all the rows into the PQ with their row and column number
        pq.push({v[i][0], {i, 0}});
    }

    while (!pq.empty())
    {
        //Take the smallest element out of PQ
        //Insert it into final result and push the next element of its row into the PQ
        ppi t = pq.top();
        pq.pop();
        res.push_back(t.first);
        int rowNo = t.second.first;
        int colNo = t.second.second;
        if (colNo < n - 1)
        {
            //Check whether the current element is last element of its row or not. If so , do nothing.
            pq.push({v[rowNo][colNo + 1], {rowNo, colNo + 1}});
        }
    }

    return res;
}

int main()
{
    int k;  //No of rows
    int n;  //No of cols
    cin >> k >> n;
    vector<vector<int>> v(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> res = mergeKSortedArrays(v);

    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}
Java Code

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Practice {
    static private class Node {
        int data;
        int row;
        int col;

        Node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }

    }

    static ArrayList<Integer> mergeKSortedArrays(int[][] arr) {
        int k = arr.length;
        int n = arr[0].length;

        ArrayList<Integer> res = new ArrayList<>();

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> ((int) (a.data - b.data)));

        for (int i = 0; i < k; i++) {
            // Push the first elements of all the rows into the PQ with their row and column
            // number
            pq.add(new Node(arr[i][0], i, 0));
        }

        while (!pq.isEmpty()) {
            // Take the smallest element out of PQ
            // Insert it into final result and push the next element of its row into the PQ
            Node t = pq.poll();
            res.add(t.data);
            int rowNo = t.row;
            int colNo = t.col;
            if (colNo < n - 1) {
                // Check whether the current element is last element of its row or not. If so ,
                // do nothing.
                pq.add(new Node(arr[rowNo][colNo + 1], rowNo, colNo + 1));
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt(); // No of rows
        int n = sc.nextInt(); // No of cols

        int[][] arr = new int[k][n];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        ArrayList<Integer> res = mergeKSortedArrays(arr);

        for (int x : res) {
            System.out.print(x + " ");
        }
    }
}
*/