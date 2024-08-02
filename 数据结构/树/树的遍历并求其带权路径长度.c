/**
	作者:萧
	
	实现：前序遍历、中序遍历、后序遍历打印遍历结果并求二叉树带权路径长度
	
	思路：root为根节点
		  对root采用前序遍历，先访问根节点，再访问左子树，在访问右子树，分别对左右子树递归前序遍历操作
		  递归函数传入结点结构，当前深度以及带权路径长度累加结果
		  当左右子树为NULL时即叶子节点，此时计算结点的带权路径长度累加到结果中

*/
#include<stdio.h>
#include<stdlib.h> 
//二叉树链表结构
typedef struct DLNode{
	int data;
	int weight;//权值 
	struct DLNode *lchild,*rchild;
}DLNode; 

//输入数组构建二叉树（层次遍历的顺序插入） 
void newNode(DLNode** root,int av,int wv){
	DLNode* rootTemp=(DLNode*)malloc(sizeof(DLNode));
	rootTemp->data=av;
	rootTemp->weight=wv;
	rootTemp->lchild=NULL;
	rootTemp->rchild=NULL;
	*root=rootTemp;
}

void createDTree(DLNode** root,int a[],int w[],int n) {
	if(n==0)return;
	//创建根节点
	newNode(&(*root),a[0],w[0]);
	//构建辅助队列
	DLNode** queue= (DLNode**)malloc(n*sizeof(DLNode*));
	int front=0,rear=0;
	queue[rear++]=*root;
	int i=1;
	while(i<n){
		DLNode* currT=queue[front++];
		if(i<n){
			newNode(&(currT->lchild),a[i],w[i]);
			queue[rear++]=currT->lchild;
			i++;
		}
		if(i<n){
			newNode(&(currT->rchild),a[i],w[i]);
			queue[rear++]=currT->rchild;
			i++;
		}
	}
	free(queue);
}
//访问结点 
void visted(DLNode* root){ 
	printf("%d ",root->data);
}
//计算带权路径长度
void calculateWPL(DLNode* root,int depth,int* WPL){
	*WPL+=(root->weight*depth);
} 
 
//前序遍历 根-左-右
void preTraverse(DLNode* root,int depth,int* WPL){
	if(root==NULL){
		return;
	}
	if(root->lchild==NULL&&root->rchild==NULL){
		//若为叶子结点则计算WPL 
		calculateWPL(root,depth,WPL);
	}
	//访问根节点
	visted(root); 
	//遍历左子树 
	preTraverse(root->lchild,depth+1,WPL);
	//遍历右子树 
	preTraverse(root->rchild,depth+1,WPL);
}
//中序遍历 左-根-右
void midTraverse(DLNode* root,int depth,int* WPL){
	if(root==NULL){
		return;
	}
	if(root->lchild==NULL&&root->rchild==NULL){
		//若为叶子结点则计算WPL 
		calculateWPL(root,depth,WPL);
	}
	//遍历左子树 
	midTraverse(root->lchild,depth+1,WPL);
	//访问根节点 
	visted(root); 	
	//遍历右子树 
	midTraverse(root->rchild,depth+1,WPL);
}
//后序遍历 左-右-根
void backTraverse(DLNode* root,int depth,int* WPL){
	if(root==NULL){
		return;
	}
	if(root->lchild==NULL&&root->rchild==NULL){
		//若为叶子结点则计算WPL 
		calculateWPL(root,depth,WPL);
	}
	//遍历左子树 
	backTraverse(root->lchild,depth+1,WPL);	
	//遍历右子树 
	backTraverse(root->rchild,depth+1,WPL);
	//访问根节点 
	visted(root); 
}
int main() {
		// 假设已经构建好了树，这里以简单示例树为例
		DLNode* root=NULL;
		int a[6]={1,2,3,4,5,6};
		int w[6]={1,1,2,2,6,6};
		createDTree(&root,a,w,6);
		int totalWPL0 = 0;
		int totalWPL1 = 0;
		int totalWPL2 = 0;
		printf("前序遍历：");
		preTraverse(root, 0, &totalWPL0);
		printf("\n前序遍历计算树的带权路径长度为: %d\n\n", totalWPL0);
		printf("中序遍历：");
		midTraverse(root, 0, &totalWPL1);
		printf("\n中序遍历计算树的带权路径长度为: %d\n\n", totalWPL1);
		printf("后序遍历：");
		backTraverse(root, 0, &totalWPL2);
		printf("\n后序遍历计算树的带权路径长度为: %d\n\n", totalWPL2);
		// 释放内存
		free(root->lchild);
		free(root->rchild);
		free(root);
		
		return 0;
   }
