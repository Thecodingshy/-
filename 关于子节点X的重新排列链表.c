#define _CRT_SECURE_NO_WARNINGS
//���� 1 9 3 5 6 7 9   X=4��ţ����������ָ�
//��� 1 3 9 5 6 7 9

#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;
 partition(struct ListNode* pHead, int x)
{
	 struct ListNode* lessHead, * lessTail;
	 struct ListNode* greaterHead, * greaterTail;
	 lessHead = lessTail = (ListNode *)malloc(sizeof(ListNode));		//less����Ԫ���
	 greaterHead = greaterTail = (ListNode*)malloc(sizeof(ListNode));	//great����Ԫ���
	 lessHead->next = greaterHead->next = NULL;		//��ʼ������next,
	 
	
	 ListNode* cur = pHead;

	 while (cur!=NULL)
	 {
		 if (cur->val < x)
		 {
			 lessTail->next = cur;
			 lessTail = lessTail->next;  
		 }
		 else
		 {
			 greaterTail->next= cur;
			 greaterTail = greaterTail->next;
		 }
		 cur = cur->next;
	 }
	lessTail->next = greaterHead->next; //
	 ListNode* realHead = lessHead->next;

	 free(greaterHead);					//��Ԫ���һ�������Ҫfree
	 free(lessHead);
	 greaterTail->next = NULL;			//��ֹ�����Ĳ�����Ϊ���ԭ����ĵ����ڶ�����y������X���һ����xС��X��
										//˵��x��ָ��greaterhead->next,yָ��lesstail�γɱջ�
	 return realHead;
}