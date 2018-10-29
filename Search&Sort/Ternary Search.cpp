#include <iostream>
/**
 * 三元搜索　必须为排序数组
 * @param  arr 搜索数组
 * @param  l   左边界
 * @param  r   右边界
 * @param  x   目标值
 * @return     返回数组下标，没有对象则为－１
 */
int ternarySearch(int arr[], int l, int r, int x){ 
   if (r >= l){ 
        int mid1 = l + (r - l)/3; 
        int mid2 = mid1 + (r - l)/3; 
        if (arr[mid1] == x)  return mid1; 
        if (arr[mid2] == x)  return mid2; 
        if (arr[mid1] > x) return ternarySearch(arr, l, mid1-1, x); 
        if (arr[mid2] < x) return ternarySearch(arr, mid2+1, r, x); 
        return ternarySearch(arr, mid1+1, mid2-1, x); 
   } 
   return -1; 
}
//之所以三元慢于二元是因为(二元)2clog2n + O(1)　<　(三元) 4clog3n + O(1)
int main(void){ 
   int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 }; 
   int n = sizeof(arr)/ sizeof(arr[0]); 
   int x = 55; 
   int result = ternarySearch(arr, 0, n-1, x); 
   (result == -1)? std::cout<<"Element is not present in array"<<std::endl
                 : std::cout<<"Element is present at index "<< result<<std::endl; 
   return 0; 
} 