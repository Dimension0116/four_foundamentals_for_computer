/*
kmp算法-使用next数组
算法思想：
kmp算法是利用模式字符串的自身特征，避免在匹配过程中进行不必要的字符比较，从而提高匹配效率。
具体来说，KMP 算法通过构建一个 next 数组来记录模式字符串中每个位置的下一个匹配位置。在匹配过程中，当遇到不匹配的字符时，通过 next 数组可以快速地找到下一个可能匹配的位置，而不需要回溯到模式字符串的开头重新开始比较。
这种方法的优点是可以在大多数情况下避免不必要的字符比较，从而提高匹配效率。特别是在模式字符串较长或者文本字符串较大的情况下，KMP 算法的优势更加明显。

求next数组,指定i和j两个指针，i一直向右移动，如果j在初始位置或者i和j相等两者都移动并且给j赋值，否则j退回next[j];如此反复。
*/

#include<stdio.h>
#include<string.h>
#define MaxSize 255
typedef struct{
	char ch[MaxSize];
	int length;
}SString;


void get_next(SString S,int next[]) {
	int i=0,j=-1;
	next[0]=-1;//第一个值一定为-1 
	while(i<S.length-1){
		if(j==-1||S.ch[i]==S.ch[j]){
			//移动指针并且给next赋值 
			i++;
			j++;
			next[i]=j; 
		}
		else{
			//指针j退回对应next
			j=next[j]; 
		}
	}
}



int Index(SString S,SString T,int next[]){
	int i=0,j=0;
	while(i<S.length&&j<T.length){
		if(j==-1||S.ch[i]==T.ch[j]){
			i++;
			j++;
		}
		else{
			//重新匹配 
			j=next[j];
		}
	}
	if(j>=T.length){
		return i-T.length;
	} 
	return -1;
}

int main(){
	SString s,t;
	int index=0;
	for (index = 0; index < 10; index++) {
        s.ch[index] = "abbcddabbc"[index];
    }
	s.length=10;
	for (index = 0; index < 3; index++) {
        t.ch[index] = "dab"[index];
    }
	t.length=3;
	int next[t.length];
	get_next(t,next);
	int ans=Index(s,t,next);
	printf("%d",ans);
	return 0;
	
} 
