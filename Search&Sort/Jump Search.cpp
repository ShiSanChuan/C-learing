#include <iostream>
#include <cmath>
/**
 * 跳转搜索
 * @param  arr 数组　必须为排序后
 * @param  n   数组长度
 * @param  x   目标值
 * @return     返回下标，没有值则为－１
 */
int jumpSearch(int arr[], int x, int n) 
{ 
    int step = std::sqrt(n); 
    int prev = 0; 
    while (arr[std::min(step, n)-1] < x){ 
        prev = step; 
        step += std::sqrt(n); 
        if (prev >= n) 
            return -1; 
    } 
    while (arr[prev] < x){ 
        prev++; 
        if (prev == std::min(step, n)) 
            return -1; 
    } 
    if (arr[prev] == x) 
        return prev; 
  
    return -1; 
} 

int main() 
{ 
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 }; 
    int x = 55; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int index = jumpSearch(arr, x, n); 
    std::cout << "\nNumber " << x << " is at index " << index<<std::endl; 
    return 0; 
} 