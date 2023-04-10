#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include<stdio.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

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
//---------------------���븴��---------------------------


//bool isSubTree(struct TreeNode* root, struct TreeNode* Subroot)
//{
//	if (root == NULL)
//		return false;
//	
//	if(isSymmetric(root, Subroot));
//		return true;
//	
//		return isSubTree(root->left, Subroot) || isSubTree(root->right, Subroot);
//}

bool isSubTree(struct TreeNode* root, struct TreeNode* Subroot)
{
	if (root == NULL)
		return false;

	if(isSymmetric(root, Subroot));		//ʵ����֮ǰ����ĸ��ã��ж�
		return true;

	return isSubTree(root->left, Subroot) || isSubTree(root->right, Subroot);
}