#include <iostream>
//最长的回文子串

int lps(char *seq, int i, int j) 
{ 
   if (i == j) 
     return 1; 
   if (seq[i] == seq[j] && i + 1 == j) 
     return 2; 
   if (seq[i] == seq[j]) 
      return lps (seq, i+1, j-1) + 2; 
  //对比－－－－－－－子串
  //　　　｜－－－－｜
  //　　　－｜－－－－｜
   return std::max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
} 

int main() 
{ 
    char seq[] = "GEEKSFORGEEKS"; 
    int n = sizeof(seq); 
    printf ("The length of the LPS is %d", lps(seq, 0, n-1)); 
    return 0; 
} 