#include <iostream>
#include <algorithm>

void heapify(int arr[], int n, int i){ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i){ 
        std::swap(arr[i], arr[largest]);  
        heapify(arr, n, largest); 
    } 
} 
/**
 * 堆排序
 * @param arr 数组
 * @param n   数组大小
 */
void heapSort(int arr[], int n){ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i=n-1; i>=0; i--){ 
        std::swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 

int main() { 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    heapSort(arr, n); 
    printf("Sorted array: \n"); 
    for(int i=0;i<n;i++)
    	std::cout<<arr[i]<<"\t";
    return 0; 
} 