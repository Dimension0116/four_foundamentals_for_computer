/**
	author:萧
	插入排序：顺序的找待排序的一些序列根据已排序序列比较，插入到对应的位置 
	希尔排序： 
*/ 
#include<stdio.h>

//1、插入排序 
void insertSort(int a[],int n){
	//循环待排序序列i(将第一个元素看成有序序列)
	int i,key,j;
	for(i=1;i<n;i++){
		key=a[i];//取出关键字 
		j=i-1;
		while(j>=0&&a[j]>key){
			//j从i-1开始一直往后移动一位 
			a[j+1]=a[j];
			j--;
		}
		//最后留下一位赋值为关键字 
		a[j+1]=key;
		
	} 
}

//2、希尔排序 

void printArr(int a[],int n){
	printf("[");
	for(int i=0;i<n-1;i++){
		printf("%d,",a[i]);
	}
	printf("%d]",a[n-1]);
}
int main(){
	//插入排序 
	int a[20]={10,1,11,19,4,18,6,17,8,9,0,2,12,14,13,15,16,7,5,3};
	insertSort(a,20);
	printArr(a,20);
	
	
	return 0;
} 

 
