#include<iostream>
using namespace std;

int recursiveLinearSearch(int *a, int n, int key) {
    if (n == 0)
        return -1;

    if (a[n - 1] == key)
        return n;

    return recursiveLinearSearch(a, n - 1, key);
}

//or

int lsearch(int *a, int n, int key) {
    if (n == 0)
        return -1;

    //rec case
    int i = lsearch(a + 1, n - 1, key);
    // levae me and find if after me occurs or not

    if (i == -1) {
        //after me doesn't occur

        if (a[0] == key)
            return 0;
        else
            // i'm not what you want
            return -1;
    }

    //here => i returned by sub problem is not -1
    return i + 1;
}
int main(int argc, char const *argv[])
{
    int arr[] = {4, 3, 6, 8, 4, 0, 4, 56, 77};
    int n = sizeof(arr) / sizeof(int);

    int key = 1;
    cout << recursiveLinearSearch(arr, n, key);
    return 0;
}
