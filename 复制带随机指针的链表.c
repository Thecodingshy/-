#define _CRT_SECURE_NO_WARNINGS
//OJ----138
//ȱ�㣺����ʽ���  �����������ʱ��������
//�����C++  map,ordermap kv�ṹ���ṹ��
#include<stdlib.h>
struct Node{
	int val;
	struct Node* next;
	struct Node* random;
}Node;
struct Node* copyRandomList(struct Node head)
{
	if (head == NULL)		//�����������Ϊ{}û�������룬�������
		return NULL;

	//1.�����ڵ㣬���ӵ�ԭ�ڵ����
	Node* cur = head;
	while (cur)
	{
		Node* copy = (Node*)malloc(sizeof(Node));
		copy->next = NULL;
		copy->random = NULL;
		copy->val = cur->val;

		copy->next = cur->next;	//����������ݲ��ܵ���
		cur->next = copy;

		cur = next;				//����
	}

	//2.����������random
	cur = head;
	while (cur)
	{
		Node* copy = cur->next;
		if(cur->random==NULL)
			copy->random = cur->random->next;		//copy����randomָ��cur->random->next		̫����
	}
	cur = cur->next->next;	//����cur=copy->next	

	//��
	cur = head;
	Node* copyHead = head->next;					
	while (cur)
	{
		Node* copy = cur->next;
		Node* next = copy->next;

		cur->next = next;			//��һ��
		if (next)
			copy->next = next->next;	//����һ��������copy�����ڵ�֮��Ĺ�ϵ��û��
		else
			copy->next = NULL;
		cur = next;					//����
	}
	return copyHead;
}













