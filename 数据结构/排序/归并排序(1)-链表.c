/*
首先归并排序的算法思想是：将待排序的序列分成若干个子序列，对每个子序列进行排序，然后将已排序的子序列合并成一个最终的有序序列

通俗理解：有一个要咱们排序的序列，把他从中间割掉，变成俩个要排序的序列，再都从中间割掉，一直到最后只剩一个元素的序列，他肯定是一个有序序列，因为他就一个元素了没得比了。
然后再合并两个短的序列合并过程中给他排序。最后变回最开始那么那么长的序列~~~~

别忘了结构：
struct ListNode {
	int val;
	struct ListNode* next;
};


归并排序步骤（好吧是代码步骤，通俗点讲易于理解）：
1、合并函数
2、分成小块小块的递归的归并排序函数
3、得到归并排序函数（这一步不要也行。。。）

下面上代码
*/
//合并两个已经排序好的序列 
struct ListNode* merge(struct ListNode* L1, struct ListNode* L2) {
  //初始化链表指针和要返回的链表（临时链表中的值会改变LAns中的值）
	struct ListNode* LAns = (struct ListNode*)malloc(sizeof(struct ListNode));
	LAns->val = 0;
  struct ListNode *Lt=LAns;//这是临时链表指针为了便于区分把*写后面
  //辅助链表记录传入的链表
  struct ListNode* Lt1 = L1;
	struct ListNode* Lt2 = L2;
	while (Lt1 != NULL && Lt2 != NULL) {
    //比较两个链表当前元素的值，把小的存到Lt中，操作后移动指针
		if (Lt1->val <= Lt2->val) {
			Lt->next = Lt1;
			Lt1 = Lt1->next;
		}
		else
		{
			Lt->next = Lt2;
			Lt2 = Lt2->next;
		}
		Lt = Lt->next;//Lt移动
	}
  //while退出后，看看还有哪个链表还有值，那肯定是有序且最大的，直接插到Lt后面
	if (Lt1 != NULL)
	{
		Lt->next = Lt1;
	}
	if (Lt2 != NULL)
	{
		Lt->next = Lt2;
	}
  //LAns没有移动，故返回LAns->next
	return LAns->next;
}

//归并排序了
struct ListNode* mergeSort(struct ListNode* L) {
  //L没有元素或者只有一个就不用排序了
	if (L==NULL||L->next==NULL)
	{
		return L;
	}
  //设置slow、fast两个快慢指针（双指针法）
  //slow一次走一格，fast一次走两格，当fast走到NULL或者下一节点为NULL则slow在中间（奇数在最中间那个数处，偶数在中间靠后那个数处），pre为slow的前一个节点，便于切割
	struct ListNode* slow = L;
	struct ListNode* fast = L;
	struct ListNode* pre = NULL;
	while (fast!=NULL&&fast->next!=NULL)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = NULL;//切割
  //切割完成，l和r分别是左右俩个子序列
	struct ListNode* l = mergeSort(L);
	struct ListNode* r = mergeSort(slow);
	return merge(l, r);
}

//得到归并排序序列
struct ListNode* sortList(struct ListNode* head) {
	return mergeSort(head);
}
