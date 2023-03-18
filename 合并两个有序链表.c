#define _CRT_SECURE_NO_WARNINGS
//����ȡС�Ľڵ���β��
//����1->2->4,  1->3->4->5->8
//���1->1->2->3->4->4->5->8
#include<stdio.h>
typedef struct SListnode {
	int val;
	struct SListnode* next;
}node;

typedef struct ListNode node;
struct ListNode* mergeTowLists(struct node* li, struct node* l2)
{
	node* head = NULL;
	node* tail = NULL;
	{
		if (l1 == NULL)			//��֤l1,l2����Ϊ��
			return l2;
		else (l2 == NULL)
			return l1;
	}
	if (l1->val < l2->val)		//ȡС��Ϊ�������ͷ
	{
		head = tail = l1;
		l1 = l1->next;
	}
	else
	{ 
		head = tail = l2;
		l2 = l2->next;
	}
	while (l1!=NULL && l2!=NULL)	//�����д����
	{
		if (l1->val < l2->val)		//β��
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1 != NULL)
		tail->next = l1;
	else
		tail->next = l2;
	return head;
}