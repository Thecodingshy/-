#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
//OJ �ö���ʵ��ջ
typedef struct {		
	Queue q1;  
	Queue q2;
}MyStack;

MyStack* MyStackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	if (st == NULL)
	{
		printf("���ٿռ�ʧ��");
		exit(-1);
	}
	QueueInit(&st->q1);
	QueueInit(&st->q2);

	return st;			//��Ϊ��malloc���������г����������st����
}
void myStackPush(MyStack* obj, int x) 
{
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}


int myStackPop(MyStack* obj)
{
	Queue* emptyQ = &obj->q1;	//����q1��
	Queue* nonemptyQ = &obj->q2;//q2����
	if (!QueueEmpty(&obj->q2))	//����������
	{
		emptyQ = &obj->q2;		//����q2��
		nonemptyQ = &obj->q1;	//q1Ϊ��
	}
	while (QueueSize(nonemptyQ) > 1)				//ֱ��ʣ��һ������
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));	//�ѷǿյ�����ȡ�������յĶ���
		QueuePop(nonemptyQ);
	}
	int top = QueueFront(nonemptyQ);				
	QueuePop(nonemptyQ);							//����֮ǰ�����ݵĶ��е����һ�����ݣ�
													//ʵ���˺���ȳ�������
	return top;
}

int myStackTop(MyStack* obj)					//����ջ�������൱�ڣ��Ҷ�β�����ݣ�												//��Ҫ�ж����������Ǹ���Ϊ��
{
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

//���Ϊ�շ���true,���򷵻�false
bool myStackEmpty(MyStack* obj)			//Ҫ�ж��������ж���Ϊ������Ҫ&&
{
	return QueueEmpty((&obj->q1)) && QueueEmpty(&obj->q2);	//q1Ϊ����q2Ϊ�շ����Զ���ջΪ�շ���true	
}						     	//QueueEmpty((&obj->q1)) && QueueEmpty(&obj->q2);��������������true

void myStackFree(MyStack* obj) 
{
	QueueDestory(&obj->q1);	//������ָ��ָ��Ľ���ͷŵ�
	QueueDestory(&obj->q2);	//������ָ��ָ��Ľ���ͷŵ�
	free(obj);				//objֻ��һ������ֱ��free���ṹ��	
}


int main()
{
	MyStack* st = MyStackCreate();
	return 0;
}