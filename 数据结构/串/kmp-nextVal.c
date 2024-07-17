/*
在 KMP 算法中，next 数组用于记录模式字符串中每个位置的下一个匹配位置。当在文本字符串中进行匹配时，如果当前字符不匹配，就可以通过 next 数组快速地找到下一个可能匹配的位置。
然而，在某些情况下，使用 next 数组可能会导致一些不必要的字符比较。例如，当模式字符串中存在多个相同的字符时，next 数组可能会指向相同的位置，从而导致在匹配过程中进行多次相同的字符比较。
nextval 数组通过对 next 数组进行优化，避免了这种不必要的字符比较。具体来说，nextval 数组的计算过程中会考虑模式字符串中字符的重复性，对于重复的字符，nextval 数组会指向一个更合适的位置，从而减少字符比较的次数。
总的来说，nextval 数组相比 next 数组可以提高字符串匹配的效率，特别是在模式字符串中存在较多重复字符的情况下。但是，计算 nextval 数组的过程相对复杂一些，需要更多的计算资源。因此，在实际应用中，可以根据具体情况选择使用 next 数组或 nextval 数组。
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

void get_nextVal(SString S,int nextVal[]){
	int i=0,j=-1;
	nextVal[0]=-1;//第一个值一定为-1 
	while(i<S.length-1){
		if(j==-1||S.ch[i]==S.ch[j]){
			//移动指针并且给next赋值 
			i++;
			j++;
			if(S.ch[i]!=S.ch[j]){
				//不等于则为j 
				nextVal[i]=j; 
			}
			else{
				//也就是去重操作，防止重复的地方一直搞 
				//否则找到j对应的nextval,nextval 数组的计算过程中会考虑模式字符串中字符的重复性，对于重复的字符，nextval 数组会指向一个更合适的位置，从而减少字符比较的次数。 
				nextVal[i]=nextVal[j];
			}
		}
		else{
			//指针j退回对应next
			j=nextVal[j]; 
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
//	int next[t.length];
//	get_next(t,next);
	int nextVal[t.length];
	get_nextVal(t,nextVal);
	int ans=Index(s,t,nextVal);
	printf("%d",ans);
	return 0;
	
} 
