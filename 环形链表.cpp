#define _CRT_SECURE_NO_WARNINGS
typedef struct ListNode {
	int val;
	struct ListNode *next;
}node;

bool hasCycle(struct ListNode* head)
node slow = head;
node fast = fead;
{
	slow = slow->next;
	fast = fast->next;
	if (slow == fast)
	{
		return true;
	}
	return false;
}
/*
	���Թ٣�
	��֤����ָ�������׷����ָ��ģ�
	�����ָ��һ��һ������ָ��һ�������в��У��Ĳ��أ�n����

	���ۣ�ֻ������ָ����һ������ָ������������������¶�����������Ȳ�һ��ʱ��Ͳ�һ��������
*/