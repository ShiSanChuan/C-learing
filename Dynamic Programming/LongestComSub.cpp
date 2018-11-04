#include <iostream>
#include <algorithm>
//迭代求解  这个比较好理解
int lcs( char *X, char *Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + lcs(X, Y, m-1, n-1); 
   else
     return std::max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 
//矩阵求解
int lcs1( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   int i, j; 
   for (i=0; i<=m; i++){ 
     for (j=0; j<=n; j++){ 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = std::max(L[i-1][j], L[i][j-1]); 
     } 
   } 
   return L[m][n]; 
} 

int main() 
{ 
  char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
  
  int m = sizeof(X); 
  int n = sizeof(Y); 
  
  printf("Length of LCS is %d", lcs( X, Y, m, n ) ); 
  printf("Length of LCS1 is %d", lcs1( X, Y, m, n ) ); 
  return 0; 
} 