#include<stdio.h>
#include<stdlib.h>
int *addArrandint(int *A,int Asize,int K,int *returnSize)
{
	int Ksize=0;
	int KNum=K;
	while(KNum)
	{
		KNum=KNum/10;
		Ksize++;
	}
	int len=Asize>Ksize ? Asize  : Ksize;
	int *Arrret =(int *)malloc(sizeof(int)*(len+1)); //�ҵ�����������Ǹ������ǽ�һ����Ϊnλ��+nλ��������n+1λ�������Զ�̬����n+1���ռ� 	
	int Ai=Asize-1;		
	int Nextnum=0;		//ret�������10 �Ļ�Ҫ���з�ʮ��һ 
	int reti=0;
	while(len--)
	{
		int a=0;
		if(Ai>=0)     //���ǵ�����Խ������⣬��һ���ֳ��ȴ������鳤�ȡ� Ai �� 
		{
			a=A[Ai];
			Ai--;
		}
		int ret = a+K%10+Nextnum;
		K=K/10; 		//���һλK�����ǰ��һλ 
		if(ret>9)
			{
				ret=ret-10;
				Nextnum=1;
			}
		else
			{
				Nextnum=0;
			}
		Arrret[reti]=ret;
		reti=reti+1;
	}
	if(Nextnum==1)                    
	{
		Arrret[reti]=1;
		reti=reti+1;
	}
	int left=0;
	int right=reti-1;			//����Arrret�ǵ��Ŵ�ģ�����Ҫ���� 
	while(left<right)
	{
		int tmp=Arrret[left];
		Arrret[left]=Arrret[right];
		Arrret[right]=tmp;
		left++;
		right--;
	}
	*returnSize=reti;  //4
	return Arrret;		//abcd 
}
int main()
{
	int arr[]={2,6,5,7};
	int K=54;
	int Asize=sizeof(arr)/sizeof(arr[0]);
	int* reti;
	addArrandint(arr,Asize,K,reti);
	printf("%d\n",reti);
	
	return 0;	
} 
