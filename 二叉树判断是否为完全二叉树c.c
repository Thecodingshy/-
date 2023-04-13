#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef BTNode QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;


typedef int BTDataType;
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;


BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}


BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	assert(node1);
	BTNode* node2 = BuyNode(2);
	assert(node1);
	BTNode* node3 = BuyNode(3);
	assert(node3);
	BTNode* node4 = BuyNode(4);
	assert(node4);
	BTNode* node5 = BuyNode(5);
	assert(node5);
	BTNode* node6 = BuyNode(6);
	assert(node6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;

}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
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

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;	//pq->head==NULL����ģ�����true��pq->head==NULL�Ǽٵģ�����false��
}

bool treeCompate(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			break;	//�������Ժ��������������
		}
	}

	//�������ȫΪ��������ȫ������
	//��������зǿ�������ȫ������
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestory(&q);
			return false;
		}
	}
	QueueDestory(&q);
	return true;
}


int main()
{
	BTNode* root = CreatBinaryTree();
	treeCompate(root);
	return 0;
}
