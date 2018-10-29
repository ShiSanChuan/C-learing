#include <iostream>
/**
 * 二元搜索　必须为排序数组
 * @param  arr 搜索数组
 * @param  l   左边界
 * @param  r   右边界
 * @param  x   目标值
 * @return     返回数组下标，没有对象则为－１
 */
int binarySearch(int arr[], int l, int r, int x) { 
   if (r >= l) { 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x)   
            return mid;  
        if (arr[mid] > x)  
            return binarySearch(arr, l, mid-1, x); 
        return binarySearch(arr, mid+1, r, x); 
   } 
   return -1; 
} 
  
int main(void){ 
   int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 }; 
   int n = sizeof(arr)/ sizeof(arr[0]); 
   int x = 55; 
   int result = binarySearch(arr, 0, n-1, x); 
   (result == -1)? std::cout<<"Element is not present in array"<<std::endl
                 : std::cout<<"Element is present at index "<< result<<std::endl; 
   return 0; 
} 