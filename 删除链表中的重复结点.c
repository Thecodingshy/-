#define _CRT_SECURE_NO_WARNINGS
struct ListNode {
	int x;
	struct ListNode* next;
};
ListNode* deletDupLication(ListNode* pHead)	//�����岿��
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* prev = NULL;
	ListNode* cur = phead;
	ListNode* next = cur->next;

	while (next)
	{
		if (cur->val != next->val)
		{
			prev = cur;				//����
			next = cur;
			next = next->next;
		}
		else
		{
			while (next && cur->val == next->val)
			{			
					next = next->next;
			}


			if (prev)
			{
				prev->next = next;
			}
			else              //����һ����������������������
			{
				phead = next;		//����ͷ
			}

			//�ͷ�
			while (cur != next)		//��ֹ�ڴ�й¶
			{
				ListNode* del = cur;
				cur = cur->next;
				free(del);
			}
			if(next)		//����β��������ͬ��ֵ���nextΪ�����ѭ��whileֱ������
				next = next->next;
		}
	}
	return pHead;
}