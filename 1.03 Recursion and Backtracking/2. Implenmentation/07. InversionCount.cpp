/*
count all a[i]>a[j] such that for i<j
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

int merge(int a[], int s, int e) {

	int cnt = 0 ;

	int mid = (s + e) / 2;

	int i = s;
	int j = mid + 1;
	int k = s;
	//int k = 0;

	int temp[100];

	while (i <= mid and j <= e) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else { //most imp step
			temp[k++] = a[j++];
			cnt += (mid - i + 1);
		}

	}

	while (i <= mid) {
		temp[k++] = a[i++];
	}

	while (j <= e) {
		temp[k++] = a[j++];
	}

	//copy back
	for (int i = s; i <= e; ++i)
	{
		a[i] = temp[i];
	}

	return cnt;
}

int mergeSort(int a[], int s, int e) {
	//base case
	if (s >= e)
		return 0;

	//1. divide
	int mid = (s + e) / 2;

	//recursisvely sort [s,mid] and [mid+1,e]
	//inversions in halves separately
	int x = mergeSort(a, s, mid);
	int y = mergeSort(a, mid + 1, e);

	//merge two sorted halves
	//cross inversions
	//sorting halves doen't affect relative ordering if we are considering cross inversions (in diff halves)
	int z = merge(a, s, e);

	return x + y + z;
}

int inversion_count(int *a, int s, int e) {
	return mergeSort(a, s, e);
}

int main()
{
	INPUT();
	int n = 6;
	int a[] = {1, 5, 2, 6, 3, 0};

	cout << inversion_count(a, 0, n - 1);
	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}