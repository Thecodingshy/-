#include<stdlib.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
    int number = k;
    int ksize = 0;//k���� 
    int next = 0;//��λ
    while (number)//����k��λ��
    {
        ksize++; 	
        number /= 10;
    }
    int asize = numSize > ksize ? numSize + 1 : ksize + 1;//ԭ���鳤��+1
    int* retarr = (int *)calloc(asize, sizeof(int));//ָ�򷵻�����
    int retSize = 0;//��ʱ�����±�
    while (numSize > 0 && ksize > 0)//�����k���
    {
        retarr[retSize++] = (num[numSize - 1] + (k % 10) + next) % 10;
        if ((num[numSize - 1] + (k % 10) + next) >= 10)
        {
            next = 1;
        }
        else
        {
            next = 0;
        }
        k /= 10;
        ksize--;
        numSize--;
    }

    if (next == 1 && numSize <= 0 && ksize <= 0)//��������ӽ�λ����������ʣ�����֡�kû�и�λ����ʱ����next�ټӵ�retarr��
    {
        retarr[retSize++] = next;
        next = 0;
    }
    else//��������ʣ�����ֻ�k�и�λ����ʱ
    {
        while (numSize > 0)//�����л���ʣ������
        {
            retarr[retSize++] = (num[numSize - 1] + next) % 10
            if ((num[numSize - 1] + next) >= 10)
            next = 1;
            else
            next = 0;
            numSize--;
        }
        while(ksize > 0)//k���и�λ����
        {
            retarr[retSize++] = (k % 10 + next) % 10;
            if (k % 10 + next >= 10)
            next = 1;
            else
            next = 0;
            k /= 10;
            ksize--;
        }
    }    
    //ѭ�����������ж��Ƿ��н�λ
    if (next == 1)
    {
        retarr[retSize++] = 1;
    }   
    *returnSize = retSize;
    //��������
    int left = 0;
    int right = retSize - 1;
    while (left <= right)
    {
        int tmp = retarr[left];
        retarr[left] = retarr[right];
        retarr[right] = tmp;
        left++;
        right--;
    }
    return retarr;

}

