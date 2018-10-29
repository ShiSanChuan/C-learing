#include <iostream>
/**
 * 线性搜索
 * @param  arr 数组
 * @param  n   数组长度
 * @param  x   目标值
 * @return     返回下标，没有值则为－１
 */
int search(int arr[], int n, int x){ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
         return i; 
    return -1; 
}
int main(int argc, char const *argv[]){
	int arr[]={5,12,9,46,78,25,36,15};
	int x=36;
	int index=search(arr,sizeof(arr)/sizeof(arr[0]),x);
	std::cout<<"find: "<<aim<<" in "<<index<<std::endl;
	return 0;
}