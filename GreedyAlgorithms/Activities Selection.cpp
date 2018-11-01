#include <iostream>
//1. 将活动结束时间按照从小到大排序
//２．从第一个开始选择不重叠活动
//start[]  =  {1, 3, 0, 5, 8, 5};
// finish[] =  {2, 4, 6, 7, 9, 9};
//
void printMaxActivities(int s[], int f[], int n) 
{ 
    int i, j; 
    i = 0; 
    printf("%d ", i); 
    for (j = 1; j < n; j++){
      if (s[j] >= f[i]){ 
          printf ("%d ", j); 
          i = j; 
      } 
    } 
} 

int main() 
{ 
    int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 
    int n = sizeof(s)/sizeof(s[0]); 
    printMaxActivities(s, f, n); 
    return 0; 
} 