#define _CRT_SECURE_NO_WARNINGS
/*
����������
��Ŀ�ж����������ݣ�ÿһ����������a��b��c(0<a,b,c<1000)����Ϊ�����ε������ߣ��ÿո�ָ���
���������
���ÿ���������ݣ����ռһ�У�����ܹ��������Σ��ȱ��������������Equilateral triangle!����
�����������������Isosceles triangle!����������������������Ordinary triangle!����
��֮�����Not a triangle!��
*/
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	while (scanf("%d, %d, %d", &a, &b, &c) != EOF)
//	{
//		if (a + b <= c && a + c <= b)
//		{
//			printf("Not a triangle!\n");
//		}
//		else
//		{
//			if (a == b == c)
//			{
//				printf("Equilateral triangle!\n");
//			}
//			else if ((a == b) || (a == c) || (b == c))
//			{
//				printf("Isosceles triangle!\n");
//			}
//			else
//			{
//				printf("Ordinary triangle!\n");
//			}
//		}
//	}
//	return 0;
//}
#include <stdio.h>
int main()
{
    int a = 1, b = 1, c = 1;

    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        if (a + b > c && a + c > b && b + c > a)
        {
            if (a == b && b == c)
            {
                printf("Equilateral triangle!\n");
            }
            else if (a == b || b == c || a == c)
            {
                printf("Isosceles triangle!\n");
            }
            else
            {
                printf("Ordinary triangle!\n");
            }
        }
        else
        {
            printf("Not a triangle!\n");
        }
    }
    return 0;
}