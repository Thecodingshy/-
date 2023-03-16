#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

SListNode* BuySListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
	void SListPushBack(SListNode** pphead, SListDataType x) //pphead��һ������ָ����Ϊ���������ǣ�&phead����һ��ָ��ĵ�ַ
{
		SListNode* newNode = BuySListNode(x);		
			if (*pphead == NULL)	//����ս���û�н��
			{
				*pphead = newNode;
			}			
			else
			{
				// ��β��
				SListNode* tail = *pphead;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
	
				tail->next = newNode;
			}
}
void SListPrint(SListNode* phead)	//������ӡ����
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);		 
		cur = cur->next;			//ȥ��һ������õ�ַ
	}
	printf("NULL");
}
void SListPopBack(SListNode** pphead)
{
	//1.��
	if (*pphead == NULL)
		{
		return;
		}
	//2.һ��
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3.һ������
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;	//��д�ɲ�д
		prev->next = NULL;
	}
}

void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode *newnode= BuySListNode(x);
	newnode->next = *pphead;//�ѿ�ʼָ�������ĵ�ַ����ʼ����*pphead(&plist)�У�������һ���newnode->next
	*pphead = newnode;		//��*pphead��ԭ����һ�����Ͽ����ӣ�ת��ָ��newnode
}

void SListPopFront(SListNode** pphead)
{
	//1.Ϊ��
	printf("\n");
	if (*pphead == NULL)
	{
		return;
	}
	//2.һ�����������
	else 
	{
		SListNode *next = ((*pphead)->next);
		free(*pphead);
		*pphead = next;
	}
}

SListNode* SListFind(SListNode* phead, SListDataType x)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInserAfter(SListNode* pos, SListDataType x)	//��pos�ĺ������newnode(ǰ������ر��鷳)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next != NULL)
	{
		SListNode* next = pos->next;
		SListNode* nextnext = next->next;
		pos->next=nextnext;
		free(next); 
	}
}