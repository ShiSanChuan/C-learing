#include <iostream>
#include <algorithm>
/**
 * 选择排序
 * @param arr 目标数组
 * @param n   目标数组大小
 */
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        std::swap(arr[min_idx], arr[i]); 
    } 
} 

int main() 
{ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n); 
    printf("Sorted array: \n"); 
    for(int i=0;i<n;i++)
    	std::cout<<arr[i]<<"\t";
    return 0; 
} 