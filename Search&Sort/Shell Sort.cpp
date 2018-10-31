#include <iostream>
/**
 * 插入排序延伸
 * @param  arr 数组
 * @param  n   数组大小
 * @return    
 */
int shellSort(int arr[], int n) 
{
    for (int gap = n/2; gap > 0; gap /= 2){  
        for (int i = gap; i < n; i += 1){ 
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

int main() 
{ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    shellSort(arr,n); 
    printf("Sorted array: \n"); 
    for(int i=0;i<n;i++)
    	std::cout<<arr[i]<<"\t";
    return 0; 
}