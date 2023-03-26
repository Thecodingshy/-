#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef char STDataType;
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


bool isValid(char* s)
{
	ST st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '(' ||
			*s == '{' ||
			*s == '[')
		{
			StackPush(&st, *s);
			s++;
		}
		else
		{
			//������Ĳ�������Ϊ�����ţ���ջ����û��ֵ����ɾ
			//˵��ǰ��û�������ţ���ƥ�䣬����false
			if (*s == '[' || *s == '{' || *s == '(')
			{
				StackDestory(&st);
				return false;
			}
			STDataType top = StackTop(&st);
			StackPop(&st);						//ɾ����ʱ�������
			if ((*s == '}' && top != "{")		//���ý�������Ū����
				|| (*s == ')' && top != '(')
				|| (*s == ']' && top != '[')
				)
			{
				StackDestory(&st);				//�ڴ�й©
				return false;					//���������������ջ�ͳ�ջ�����ƥ�䣩����false
			}
			else
			{
				s++;
			}
		}
	}
	bool ret = StackEmpty(&st);					//��һ��ջ�Ƿ�Ϊ�գ���˵��ƥ�����ˣ�
												//��Ϊ�գ�˵��ջ���������Ż���ʣ��,����false
	StackDestory(&st);
	return ret;
}