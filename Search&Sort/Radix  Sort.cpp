#include <iostream>
//取数组最大值
int getMax(int arr[], int n){ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
/**
 * 基排序
 * @param arr 数组
 * @param n   数组大小
 * @param exp 基数
 */
void countSort(int arr[], int n, int exp){ 
    int output[n];
    int i, count[10] = {0}; 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
    for (i = n - 1; i >= 0; i--){ 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
void radixsort(int arr[], int n) 
{ 
    int m = getMax(arr, n); 
    for (int exp = 1; m/exp > 0; exp *= 10) //每次取个位、十位、百位排序
        countSort(arr, n, exp); 
} 
int main() 
{ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    radixsort(arr,n); 
    printf("Sorted array: \n"); 
    for(int i=0;i<n;i++)
    	std::cout<<arr[i]<<"\t";
    return 0; 
}