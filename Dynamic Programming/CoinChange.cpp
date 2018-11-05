#include <iostream>

int count( int S[], int m, int n ) 
{ 
    if (n == 0) //币种凑成面额
        return 1; 
    if (n < 0) 
        return 0; 
    if (m <=0 && n >= 1) 
        return 0;
    //两种情况　该币种没被用　和　被用
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] ); 
}
int main() 
{ 
    int i, j; 
    int arr[] = {1,2,5,10,20,50,100}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    printf("%d ", count(arr, m, 139)); 
    return 0; 
} 