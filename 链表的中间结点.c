#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//����ָ��		OJ 876		�����ռ��ڴ�ָ��

struct ListNode* middileNode(struct node* head)
{
	struct node* slow = head;
	struct node* fast = head;
	while (fast && fast->next)	//������������fast��ΪNULL��fast->next��ΪNULL;��֤ѭ������
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
int main()
{
	typedef struct ListNode {					//�����ڱ������¹���oj�Ĳ�������
		int val;
		struct ListNode* next;
	}node;
	node* n1 = (node*)malloc(sizeof(node));
	n1->val = 1;
	node* n2 = (node*)malloc(sizeof(node));
	n2->val = 3;
	node* n3 = (node*)malloc(sizeof(node));
	n3->val = 5;
	node* n4 = (node*)malloc(sizeof(node));
	n4->val = 7;
	node* n5 = (node*)malloc(sizeof(node));
	n5->val = 9;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	node* mid = NULL;
	node* mid=middileNode(n1);
	return 0;
}