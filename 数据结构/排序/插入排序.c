
/**
	作者：萧
	
	插入排序：
	算法思想：从第二个元素开始一个个作为key关键字，用一个指针遍历key之前的元素，如果比key大，则后移一位，
	最后一直移到比key小的元素那么key插入这个元素屁股后面，或者没有比他小的，即指针变为-1，那么key插入到第一个位置 

*/

#include<stdio.h>


void insertSort(int arr[],int n){
	//从第二个元素开始循环 
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		//查找符合条件的后移一位 
		while(j>=0&&key<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		//最后插入key 
		arr[j+1]=key;
		printf("第%d趟排序：",i); 
		printArray(arr,n);
		printf("\n\n");
	}
} 
void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[10]={3,1,2,8,7,5,9,4,6,0}; 
	insertSort(arr,10);
	return 0;
}
