#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double PI = acos(-1);
void INPUT();

void replace1(char a[], int i) {
	//base
	if (a[i] == '\0' or a[i + 1] == '\0')
		return;

	//look for pi
	if (a[i] == 'p' and a[i + 1] == 'i') {
		//shift + replace
		int j = i + 2;
		while (a[j] != '\0')
			j++;

		//shift
		while (j >= i + 2) {
			a[j + 2] = a[j];
			j--;
		}

		//replace +recurse
		a[i] = '3';
		a[i + 1] = '.';
		a[i + 2] = '1';
		a[i + 3] = '4';
		replace1(a, i + 2);
	} else {
		replace1(a, i + 1);
	}

}

void replace2(char a[], int i, int j) {
	//i =old , j =new
	if (a[i] == '\0' or a[i + 1] == '\0')
		return;

	if (a[i] == 'p' and a[i + 1] == 'i') {
		//shift + replace
		// xpiy
		replace2(a,)
		int j = i + 2;


		//TODO
		replace1(a, i + 2);
	} else {
		replace1(a, i + 1, j + 2);
	}


}


int main()
{
	INPUT();
	char a[1000] = "xpipipxipip";
	replace1(a, 0);
	cout << a;


	return 0;
}


void INPUT()
{
#ifndef ONLINE_JUDGE
	freopen("C:/Users/arvind/Desktop/Current/input.txt", "r", stdin);
	freopen("C:/Users/arvind/Desktop/Current/output.txt", "w", stdout);
#endif
}