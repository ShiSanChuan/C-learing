#include <iostream>
#include <algorithm>
/**
 * 冒泡排序
 * @param arr 目标数组
 * @param n   目标数组大小
 */
void bubbleSort(int arr[], int n){ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              std::swap(arr[j], arr[j+1]); 
} 

int main() { 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printf("Sorted array: \n"); 
    for(int i=0;i<n;i++)
    	std::cout<<arr[i]<<"\t";
    return 0; 
} 