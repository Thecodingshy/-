#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
reverse(struct ListNode* head)	//����ֵΪ��ת���ͷָ��
{
	struct ListNode *n1 = NULL;
	struct ListNode	*n2 = head;
	struct ListNode	*n3 = head->next;
	if (n2 || n3)
	{
		return head;	//��head����Ϊ�ջ���ֻ��һ��Ԫ��ʱ��
	}
	while (n2)
	{
		n2->next = n1;	//����

		n1 = n2;
		n2 = n3;
		if(n3)			//���ǵ�n2ָ��ԭ��β��NULLʱ��n3��ΪҰָ��
			n3 = n3->next;
	}
	return n1;
}

reverse2(struct ListNode* head)
{
	struct Listnode* cur = head;
	struct Listnode* next= head->next;
	struct Listnode* newhead = NULL;
	while (cur)
	{
		cur->next = newhead;
		newhead = cur;

		cur = next;
		next = next->next;
	}
	return newhead;
}

chkPalindrome(ListNode* A)	// �������������巵��ֵΪbool
{
	ListNode* fast = A;
	ListNode* slow = A;
	listNode* prev = A;

	while (fast && fast->next)
	{
		prev = prev->next;			//Ϊ�˶Ͽ�ǰ������
		slow = slow->next;
		next = next->next->next;
	}
	prev->next = NULL;
	slow = reverse(slow);	//����һ����ͨ������ֵ���ػ�����
	//����ͨ������ָ�������reverse()
	while (A)
	{
		if (A->val != slow->val)
		{
			return false;
		}
		else
		{
			A = A->next;
			slow = slow->next;
		}
	}
	return true;
}