#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDataType;
typedef struct ListNode {
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;


//void ListInit(ListNode** phead);
ListNode* ListInit();								//@@@@
ListNode* BuyListNode(LTDataType x);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
//��posǰ�����
void ListInsert(ListNode* pos, LTDataType x);		//@@@@
void ListErase(ListNode* pos);						//@@@@

void ListPrint(ListNode* phead);

void ListDestory(ListNode** pphead);
void ListClear(ListNode* phead);


/*
	�����˳������飩���������ϵ��
		1.˳������������Ļ�����ʵ����ɾ��ģ����Ҳ���ʱ���Զ�̬����
		˳���ȱ�ݣ�
			a.����һ���Ŀռ��˷�
			b.������һЩ��Ч����ʧ
			c.�м����ͷ������ɾ����ʱ�临�Ӷ�O��n��,��ΪҪŲ������
		��Щ��������ͽ����
		�����ȱ�ݣ�
			�������������

			�����ڴ������ʸ�������
			˳�����л�����Ⱦ�����⡶�����������ϵͳ��

		���������ݽṹ
*/