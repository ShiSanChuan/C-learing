#include <iostream>

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l){ 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x); 
        return binarySearch(arr, mid+1, r, x); 
    } 
    return -1; 
} 
/**
 * 指数搜索　排序后数组
 * @param  arr 目标数组
 * @param  n   数组大小
 * @param  x   目标值
 * @return     数组下标，没有则为－１
 */
int exponentialSearch(int arr[], int n, int x){ 
    if (arr[0] == x) 
        return 0; 
    int i = 1; 
    while (i < n && arr[i] <= x) 
        i = i*2; 
    return binarySearch(arr, i/2, std::min(i, n), x); 
} 
 
int main(void){ 
   int arr[] = {2, 3, 4, 10, 40}; 
   int n = sizeof(arr)/ sizeof(arr[0]); 
   int x = 10; 
   int result = exponentialSearch(arr, n, x); 
   if (result != -1) 
       std::cout<<"Element found at index "<<result<<std::endl; 
    else
       std::cout<<"Element not found."<<std::endl; 
   return 0; 
} 