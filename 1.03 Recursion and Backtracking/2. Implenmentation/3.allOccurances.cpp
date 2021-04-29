#include<iostream>
using namespace std;

void allOccurance(int *a, int i, int n, int key) {
	if (i == n)
		return ;

	if (a[i] == key) cout << i << " ";
	allOccurance(a, i + 1, n, key);
}


//j is size of output array(no of occurrences)
int storeOcc(int *a, int i, int n, int key, int *out, int j) {
	if (i == n)
		return j;

	if (a[i] == key) {
		out[j] = i;
		//increment j to accomaodate current occurence
		return storeOcc(a + 1, i + 1, n, key, out, j + 1);
	}

	//dont increment j
	return storeOcc(a + 1, i + 1, n, key, out, j + 1);
}

int main(int argc, char const *argv[])
{
	int arr[] = {4, 3, 6, 8, 4, 0, 4, 56, 77};
	int n = sizeof(arr) / sizeof(int);

	int key = 4;
	allOccurance(arr, 0, n, key);
	return 0;
}
