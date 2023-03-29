#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
//  OJ 622


//------------------------���鷽��--------------------------------------------------------

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
typedef struct {
	int* a;		//����ָ��
	int front;
	int tail;
	int k;
}MyCircularQueue;

MyCircularQueue* myCirularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (int*)malloc(sizeof(int) * (k + 1));
	cq->front = cq->tail = 0;
	cq->k = k;

	return cq;
}


bool myCirularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull)
		return false;
	obj->a[obj->tail] = value;
	obj->tail++;
	obj->tail %= (obj->k + 1);

	return true;
}


bool myCirularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->front++;
	obj->front %= ((obj->k) + 1);
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)	//ȡ��β�����
{
	if (myCircularQueueIsEmpty(obj))
		return -1;

	int i = (obj->tail+obj->k)%(obj->k+1);	//�軭ͼ����
	return obj->a[i];
	//if (obj->tail == 0)
	//	return obj->a[obj->k - 1];
	//else
	//	return obj->a[obj->tail - 1];

}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->tail + 1) % (obj->k + 1) == (obj->front);
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->tail;
}


void myCircularQueueFree(MyCircularQueue* obj)
{
    free(obj->a);
    free(obj);
}


//----------------------���з���-------------------------------------------

/*
typedef struct {
    int *a;
    int k;
    int tail;
    int head;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) 
{
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = malloc(sizeof(int)*(k+1));//��ΪҪ�࿪һ���ռ�ȥ�ж� ��or��
    obj->head = obj->tail =0;
    obj->k = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
    return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
    int next = obj->tail + 1;
    if(next == obj->k+1)                //��������Ļ�Ϊ�˸�obj->head(0)������淵��
      next = 0;                         //���԰�next����Ϊ0��
    return next == obj->head;           //���㷵��ֵ�ж�

}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))  //���˾Ͳ���¼��������ֱ�ӷ���
        return false;
     obj->a[obj->tail] = value;
     obj->tail++;
     if(obj->tail == obj->k+1)      //���ǵ���¼�����ݸպ�����
       obj->tail =0;                //��ʼ��tail,�൱��һ���Ѿ�¼������K���ռ�
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) //���˾Ͳ���ȥ������
      return false;
    ++obj->head;
    if(obj->head == obj->k+1)       //����ɾ�Ĵ����ﵽ���K���ռ�ʱ���ֳ�ʼ��
       obj->head =0;                //���������EnQueue
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj))
      return -1;
    return obj->a[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) 
{
    if(myCircularQueueIsEmpty(obj))     //Ϊ��ȡ����
      return -1;
    int prev = obj->tail-1;
    if(obj->tail ==0)                   //�ڶ�������ʱ��洢���˾�
      prev =obj->k;
    return obj->a[prev];

}

void myCircularQueueFree(MyCircularQueue* obj) {
     free(obj->a);
     free(obj);
}
*/