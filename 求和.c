#define _CRT_SECURE_NO_WARNINGS
/*
дһ�����������������Ľϴ�ֵ
�磺
���룺10 20
����ϴ�ֵ��20
*/

#include<stdio.h>
int Cmp(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	int max=Cmp(a, b);
	printf("%d", max);
	return 0;
}
