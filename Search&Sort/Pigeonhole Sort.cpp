#include <iostream>
#include <vector>
/**
 * 鸽笼排序
 * @param arr 数组
 * @param n   数组大小
 */
void pigeonholeSort(int arr[], int n) 
{ 
    int min = arr[0], max = arr[0]; 
    for (int i = 1; i < n; i++) //找出最大最小范围
    { 
        if (arr[i] < min) 
            min = arr[i]; 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
    int range = max - min + 1; 

    std::vector<int> holes[range]; 
    for (int i = 0; i < n; i++) 
        holes[arr[i]-min].push_back(arr[i]); 
    int index = 0;
    for (int i = 0; i < range; i++){ 
       for (auto it = holes[i].begin(); it != holes[i].end(); ++it) 
            arr[index++]  = *it; 
    } 
} 

int main(){ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    pigeonholeSort(arr,n); 
    printf("Sorted array: \n"); 
    for(int i=0;i<n;i++)
    	std::cout<<arr[i]<<"\t";
    return 0; 
}