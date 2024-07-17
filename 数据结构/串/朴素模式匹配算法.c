#include<stdio.h>
#include<string.h>
#define MaxSize 255
typedef struct{
	char ch[MaxSize];
	int length;
}SString;

int Index(SString S,SString T){
	int i=0,j=0;
	while(i<S.length&&j<T.length){
		if(S.ch[i]==T.ch[j]){
			i++;
			j++;
		}
		else{
			//重新匹配 
			i=i-j+1;
			j=0;
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
	int ans=Index(s,t);
	printf("%d",ans);
	return 0;
	
} 
