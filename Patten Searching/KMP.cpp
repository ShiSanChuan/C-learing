#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void FindNext(char * T,int * next){
	int i=1;
	int j=0;
	for(;i<T[0];){
		if(j==0||T[i]==T[j]){//最开始的两个必是01
			i++;
			j++;
			next[i]=j;
			printf(".i:%d,j:%d,next[i]:%d,%d\n",i,j,next[i],T[i]);
		}
		else j=next[j];
	}
}
int CheckString(char *S,char*T,int pos){
	int i=pos;
	int j=1;
	int next[255]={0};
	FindNext(T,next);
	printf("\n");
	for (int i = 0; i < strlen(T); ++i)
	{
		printf("%d \n",next[i]);
		/* code */
	}
	while(i<=S[0]&&j<=T[0]){
		if(j==0||S[i]==T[j]){
			i++;
			j++;
		}else j=next[j];
	}
	if(j>T[0])return i-T[0];
	else return 0;
}
int main(int argc, char const *argv[])
{
	char T[]={" baa"};
	T[0]=3;
	char S[]={" ababaaaba"};
	S[0]=9;
	int m=CheckString(S,T,0);
	printf("%d\n", m);
	return 0;
}