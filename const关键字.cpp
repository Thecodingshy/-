#include<stdio.h>
int main ()
{
	int a=10;
	int b=20;
	const int *p=&a; //const���� *p 
	p=&b;			//p���Ը��� 
//	*p =100 //err
	
	int *const p1 =&a; //const ���α���p 
	*p1=30;
//	p1=&b //err
			
	printf("%d\n",*p);	//20
	printf("%d\n",*p1);	//30 
	return 0;
 } 
