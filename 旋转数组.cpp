/*
	����[1,2,3,4,5,6,7]		k=3		���k>n �� k=k%n 
	���[5,6,7,1,2,3,4] 
����һ�� 
		ÿ����תһ�����������һ����ǰn-1�����Դ�����Ų��
		���һ�����ŵ���һ��λ����ȥ
		O��n*k�� 
��������
		����һ��k��С����ʱ���飬��k����ǰk����һ�� 
		ʱ�临�Ӷ�O (n)
		�ռ临�Ӷ�O��k�� 
����������2+1�����÷��� 
*/
#include<stdio.h> 
void reverse(int*arr, int  left,  int right)
{
	while(left<right)
	{
		int tmp=arr[left];
		arr[left]=arr[right];
		arr[right]=arr[left];
		left++;
		right--;
	}
}
void rotate(int *nums,int numSize,int k)
{
	reverse(nums,0,numSize-k-1);
	reverse(nums,numSize-k,numSize-1);
	reverse(nums,0,numSize-1);

 } 

