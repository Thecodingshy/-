#define _CRT_SECURE_NO_WARNINGS
//		OJ 147  ��������в�������
#include<stdio.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
}Node;

struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	Node* sortHead = head;
	Node* cur = head->next;
	sortHead->next = NULL;

	while (cur)
	{
		Node* next = cur->next;
		//��cur���뵽sortHead�����У����ұ�������
		if (cur->val <= sortHead->val)	//˵��ͷ��
		{
			cur->next = sortHead;
			sortHead = cur;
		}
		else                //�м�������β��
		{
			Node* sortPrev = sortHead;
			Node* sortCur = sortPrev->next;
			while (sortCur)
			{
				if (sortCur->val)
					sortPrev->next = cur;
					cur->next = sortCur;
					break;
				else
				{
					sortPrev = sortCur;			//����ֱ���ҵ����ʵ�λ��
					sortCur = sortCur->next;
				}
			}	
			if (sortCur == NULL)	//�жϲ���break�����ģ����ҵ�β�����Ѿ�
			{
				sortPrev->next = cur;
				cur->next = NULL;
			}
		}	
		cur = next;
	}
	return sortHead;
}