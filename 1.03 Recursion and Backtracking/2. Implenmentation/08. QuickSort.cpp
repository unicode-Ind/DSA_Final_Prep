/*
in palce => still extra space due to recusrion
worst case  n^2
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();


int partition(int a[], int s, int e) {

	//inpace (no extra space)
	int i = s - 1;
	//int j=s;
	int pivot = a[e];

	//we have two regions =>smaleer than and larger than pivot
	// i => [0,i] => s,aller
	//[i+1,j] =>larger
	// j+1 to (n-2) is un explored
	// n-1 th element is pivot element

	for (int j = s; j <= e - 1; ++j)
	{
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}

	//palce pivot on its place
	swap(a[++i], a[e]);

	return i;

}

void qsort(int a[], int s, int e) {
	if (s >= e)
		return;

	int p = partition(a, s, e);

	qsort(a, s, p - 1);
	qsort(a, p + 1, e);
}

int main()
{
	INPUT();
	int n = 6;
	int a[] = {1, 5, 2, 6, 3, 0};

	qsort(a, 0, n - 1);

	for (int i = 0; i < 6; ++i)
	{
		cout << a[i] << " ,";
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