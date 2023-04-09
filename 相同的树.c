#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include<stdio.h>
typedef struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
////bool IsSameTree(TreeNode* p,TreeNode* q)//������
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	if (p->data != q->data)
//		return false;
//
//	return IsSameTree(p->left,p->right) && IsSameTree(q->right,q->right);
//}

bool IsSameTree(TreeNode* p, TreeNode* q)		//�����������б����Ƚ�
{
	if (q == NULL && p == NULL)
		return true;
	if (q == NULL || p == NULL)
		return false;

	if (q->data != p->data)
		return false;

	return IsSameTree(p->left, p->right) && IsSameTree(q->left, q->right);
}