#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SListDataType;
//���
typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SListNode;
void SListPushBack(SListNode** pphead, SListDataType x);  //�õ��˶���ָ��
void SListPopBack(SListNode** pphead);
void SListPushFront(SListNode** phead, SListDataType x);
void SListPopFront(SListNode** phead);
SListNode* SListFind(SListNode* phead, SListDataType x);
void SListInserAfter(SListNode* pos, SListDataType x);
void SListEraseAfter(SListNode* pos);
void SListPrint(SListNode* phead); //���
