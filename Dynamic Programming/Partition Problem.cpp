#include <iostream>
//给一组数组，计算分成两边，两边相等
bool isSubsetSum (int arr[], int n, int sum) 
{ 
	if (sum == 0) 
		return true; 
	if (n == 0 && sum != 0) 
		return false; 
	if (arr[n-1] > sum) //末子大于中间值　为什么不直接错,因为可能有负数和极大的正数
	 	return isSubsetSum (arr, n-1, sum); 
	//两种情况，被包含和不被包含
	return isSubsetSum (arr, n-1, sum) ||  
      isSubsetSum (arr, n-1, sum-arr[n-1]); 
} 
  
//计算中间值
bool findPartiion (int arr[], int n) 
{ 
    int sum = 0; 
    for (int i = 0; i < n; i++) 
       sum += arr[i]; 
    if (sum%2 != 0) //奇数无法分
       return false; 
    return isSubsetSum (arr, n, sum/2); 
} 
  
int main() 
{ 
  int arr[] = {3, 1, 5, 9, 12}; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  if (findPartiion(arr, n) == true) 
     printf("Can be divided into two subsets "
            "of equal sum"); 
  else
     printf("Can not be divided into two subsets"
            " of equal sum"); 
  return 0; 
} 