#include <stdio.h>
#include <string.h>
#define d 256
//实际上也是每次比较，不过比较换成了ｈａｓｈ值
//不同的是这种ｈａｓｈ的产生方式具有记忆性
void search(char pat[], char txt[], int q) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0; // hash value for pattern 
    int t = 0; // hash value for txt 
    int h = 1; 
  
    // The value of h would be "pow(d, M-1)%q" 
    for (i = 0; i < M-1; i++) 
        h = (h*d)%q; 
    for (i = 0; i < M; i++) { //计算第一端ｈａｓｈ值
        p = (d*p + pat[i])%q; 
        t = (d*t + txt[i])%q; 
    } 
    for (i = 0; i <= N - M; i++){
        if ( p == t ){ 
            for (j = 0; j < M; j++){ 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
            if (j == M) 
                printf("Pattern found at index %d \n", i); 
        } 
        if ( i < N-M ){ //计算下一段ｈａｓｈ值
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
            if (t < 0) 
            t = (t + q); 
        } 
    } 
} 
int main() 
{ 
    char txt[] = "GEEKS FOR GEEKS"; 
    char pat[] = "GEEK"; 
    int q = 101; // A prime number 
    search(pat, txt, q); 
    return 0; 
} 