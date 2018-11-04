#include <iostream>
#include <algorithm>
//寻找一段数组中元素最大的子数组，子数组必须满足递增的条件
//

int lis( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
    for (int i = 1; i < n; i++ ){ 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  //实际上下标为选取的子字符串的位置下标
    }
    // int max=INT_MIN;
    // for(int i=0;i<n;i++)
    // 	if(lis[i]>max)max=lis[i];
    return *std::max_element(lis, lis+n); 
}  

int main()  
{  
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    printf("Length of lis is %d\n", lis( arr, n ) );  
    return 0;  
}