#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void merge(int a[], int s, int e) {

	int mid = (s + e) / 2;

	int i = s;
	int j = mid + 1;
	int k = s;
	//int k = 0;

	int temp[100];

	while (i <= mid and j <= e) {
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];

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



}

void mergeSort(int a[], int s, int e) {
	//base case
	if (s >= e)
		return;

	//1. divide
	int mid = (s + e) / 2;

	//recursisvely sort [s,mid] and [mid+1,e]
	mergeSort(a, s, mid);
	mergeSort(a, mid + 1, e);

	//merge two sorted halves
	merge(a, s, e);
}

int main()
{
	INPUT();
	int n;
	int a[100];

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	mergeSort(a, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}