#include<stdio.h>
#include<assert.h>
int RemoveDuplicates(int * arr,int sz)
{
	if(sz==0)		//
	{				//
		return 0;	//
	}				//����OJ�����˵ ��ƭOJ���Ĳ������� 
	assert(arr);
	int pre=0;
	int cur=1;
	int ret=0;
	while(cur<sz)		
		{
			if(arr[pre] != arr[cur])	//����ָ��ָ�����ݲ�ͬ 
				{
					arr[ret]=arr[cur];
					ret++;
					pre++;
					cur++;
				}
			else				//����ָ��ָ��������ͬ 
			{
				pre++;
				cur++;			 
			}
		}
		arr[ret]=arr[pre];
		ret++;
		return ret;	
}
int main()
{
	int arr[]={1,1,2,3,3,4,4,4,5,5,6,6,7,8,9};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int ret = 0;
	ret = RemoveDuplicates(arr,sz);
	printf("%d\n",ret);
	return NULL;
}
