#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
void Text1()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < sz; i++)
	{
		HeapPush(&hp, a[i]);
	}

	HeapPush(&hp, 10);
	HeapPrint(&hp);
}



//����----�����
//����----��С��
void HeapSort(int* a, int n)
{
	//�������ϵ���-----��С��
	// ���ѷ�ʽ1 ��O��N*logN��
	// ���ѷ�ʽ1 ��O��N*logN��
	// ���ѷ�ʽ1 ��O��N*logN��
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//�������µ���ǰ��		�����������Ǵ�/С��
	// ���ѷ�ʽ2 ��O��N��
	// ���ѷ�ʽ2 ��O��N��
	// ���ѷ�ʽ2 ��O��N��
	for (int i=(n-1-1)/2; i >=0; i--)	//�ӵ�(n-1-1)/2����ʼ���������ߵĵ�һ������
	{
		AdjustDown(a, n ,i);	//a:��ʾҪ�����aָ�����飬n��ʾ����Ĵ�С��
								//i��ʾ����С������ʼ�Ľ�����������飨���������ǰȡֵʵ�ֵ�����Ҳ���ǿ��Ե�����λ��
	}
	//�ڽ��öѵĻ�����ʱ�临�Ӷȣ�O(N*logN)

	
	int end = n - 1;
	while (end>0)						//��ǰ0��end����һ���ѣ������������������ŵ�end��;end--
	//end>0��ʾ������������������		//Ȼ���൱�������±�ǰ�ƣ���ǰ0��end-1����һ����
										//��ʣ�µĶ�������������ŵ�end��,end--
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
	//�ص������������㷨�������������������㣬ʱ�临�Ӷ�Ҳ��N*log*N
	//�ص������������㷨�������������������㣬ʱ�临�Ӷ�Ҳ��N*log*N
	//�ص������������㷨�������������������㣬ʱ�临�Ӷ�Ҳ��N*log*N



// 1.�����дһ�����ݽṹ����������
// 2.��O(n)�Ŀռ临�Ӷ�
void TextHeapSort()
{
	//�����ӡ-----С��
	HP hp;
	HeapInit(&hp);
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < sz; i++)
	{
		HeapPush(&hp, a[i]);
	}

	int i = 0;
	while (!HeapEmpty(&hp))
	{
		printf("%d ",HeapTop(&hp));
		a[i++] = HeapTop(&hp);
		HeapPop(&hp);
	}
	printf("\n");
}


int main()
{
	Text1();
	TextHeapSort();
	return 0;
}