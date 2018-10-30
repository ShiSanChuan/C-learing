#include <iostream>
/**
 * 插入排序
 * @param arr 数组
 * @param n   数组大小
 */
void insertionSort(int arr[], int n){ 
   int i, key, j; 
   for (i = 1; i < n; i++){ 
       key = arr[i]; 
       j = i-1; 
       while (j >= 0 && arr[j] > key){ 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 

int main(){ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    insertionSort(arr, n); 
    printf("Sorted array: \n"); 
    for(int i=0;i<n;i++)
    	std::cout<<arr[i]<<"\t";
    return 0; 
} 