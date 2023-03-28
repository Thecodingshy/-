#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;

}


void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;	//����һֱ������ָ��pq->tail
}


void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode != NULL)
	{
		newnode->data = x;
		newnode->next = NULL;

		if (pq->head == NULL)
		{
			pq->head = pq->tail = newnode;
		}
		else
		{
			pq->tail->next = newnode;
			pq->tail = newnode;
		}
	}
	printf("����ʧ��");
	exit(-1);
}


void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));				//assert(pq->head);

	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)					//ɾ���ˣ�Ҫ����tail��Ȼtail�����Ұָ��
	{
		pq->tail = NULL;
	}
}


QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}


QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}


int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;

	QueueNode* cur = pq->head;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}


bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;	//pq->head==NULL����ģ�����true��pq->head==NULL�Ǽٵģ�����false��
}