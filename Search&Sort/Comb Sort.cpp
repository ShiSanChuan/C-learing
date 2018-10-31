#include <iostream>

int getNextGap(int gap) { //数字不一定为１３，可以是１７，１９等质数
    gap = (gap*10)/13; 
    if (gap < 1) 
        return 1; 
    return gap; 
} 
/**
 * 梳子算法　通过冒泡算法改进，改进冒泡算法的每次比较的位置
 * @param a 数组
 * @param n 数组大小
 */
void combSort(int a[], int n) 
{ 
    int gap = n; 
    bool swapped = true; 
    while (gap != 1 || swapped == true){ 
        gap = getNextGap(gap); 
        swapped = false; 
        for (int i=0; i<n-gap; i++){ 
            if (a[i] > a[i+gap]){ 
                std::swap(a[i], a[i+gap]); 
                swapped = true; 
            } 
        } 
    } 
} 

int main(){ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    combSort(arr,n); 
    printf("Sorted array: \n"); 
    for(int i=0;i<n;i++)
    	std::cout<<arr[i]<<"\t";
    return 0; 
}