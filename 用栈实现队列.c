#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, STDataType x);

void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;	//�ȷ���++
	ps->capacity = 0;
}
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));	//������ɾ�껹����ɾassert(ps->top>0);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;	//ָ��ջ������
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return	ps->top == 0;	//ʵ��
}

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;


//--------------------------------------------------------------------------------------------------------------------------------------
//������ջ��غ�����ʵ��
//������ʵ����OJ��
typedef struct {
	Stack pushST;
	Stack popST;
}MyQueue;


MyQueue* myQueueCreat()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);
	return q;
}


void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->pushST, x);
}


void myQueueFree(MyQueue* obj)
{
	StackDestory(&obj->pushST);
	StackDestory(&obj->popST);
	free(obj);
}
//
int myQueuePop(MyQueue* obj)
//���popST��û�����ݣ���pushST�����ݵ���ȥ
//popST�е����ݾͷ����Ƚ��ȳ���˳��
{
	if (StackEmpty(&obj->popST))							//popջ�ǿյ�
	{
		while (StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));	//��Ŀ���ַ����������ݣ�
			StackPop(&obj->pushST);
		}
	}
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);			//�������˾�ɾ��
	return front;
}


int myQueuePeek(MyQueue* obj)		//���ض��п�ͷԪ��
{
	if (StackEmpty(&obj->popST))							
	{
		while (StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));	
			StackPop(&obj->popST);
		}
	}
	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue *obj) {
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}