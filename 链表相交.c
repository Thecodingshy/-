#define _CRT_SECURE_NO_WARNINGS
//  abs()��C���ԵĿ⺯���󣨣��ڵľ���ֵ

typedef struct ListNode {
		int val;
		struct ListNode* next;
}ListNode;
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)		//�����岿��
{
	ListNode* curA = headA;
	int la = 0;
	while (curA)							//��A�����ʵ�ʳ���
	{
		la = la + 1;
		curA = curA->next;
	}
	ListNode* curB = headB;
	int lb = 0;
	while (curB)							//��B�����ʵ�ʳ���
	{
		lb = lb + 1;
		curB = curB->next;
	}
	ListNode* longlist  = headA;			//�ҵ����ĺͶ̵���������long ��short��ʾ
	ListNode* shortlist = headB;
	if (la < lb)
	{
		longlist = headB;
		shortlist =headA;
	}
	int gap = abs(la - lb);
	while (gap--)
	{
		longlist = longlist->next;
	}
	/*			//����д���Ҹ��ŵĴ�������滻������ʦ����д������
	if (longlist->next == shortlist->next, longlist = longlist->next, shortlist = shortlist->next)
	{
		return longlist;
	}
	return null;
	*/
	while (longlist)						//���ٵĵ�
	{
		if (longlist == shortlist)
			return longlist;

		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return NULL;
}