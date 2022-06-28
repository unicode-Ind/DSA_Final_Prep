
int arr1[] = {1, 2, 3};
  int arr2[] = {4, 5, 6};
  int n = sizeof(arr1)/sizeof(arr1[0]);
  int res[n];
 
  // Single line code to add arr1[] and arr2[] and
  // store result in res[]
  transform(arr1, arr1+n, arr2, res, plus<int>());


transform() in C++ is used in two forms: 
 

Unary Operation : Applies a unary operator on input to convert into output 
transform(Iterator inputBegin, Iterator inputEnd, 
         Iterator OutputBegin, unary_operation)

int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Apply increment to all elements of
    // arr[] and store the modified elements
    // back in arr[]
    transform(arr, arr+n, arr, increment)

Binary Operation : Applies a binary operator on input to convert into output 
transform(Iterator inputBegin1, Iterator inputEnd1, 
         Iterator inputBegin2, Iterator OutputBegin, 
         binary_operation)

