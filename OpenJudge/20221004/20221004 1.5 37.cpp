#include <bits/stdc++.h>
using namespace std;

int main()
{
//	��Ӷ�����������ֵΪM����ʼ����ֵΪ0
//	ս����ΪN��ӵ��X������Ԫ��
//sumΪÿ��ս�������ӵĴ��� 
	int m,n,x,sum,tili=0;
	scanf("%d %d %d",&m,&n,&x);
	for(;;)
	{
		for(tili=0;tili<m;tili+=n)
		{
			x--;
		}
		if(x<0)
		{
			break;
		}
		sum=0;
		for(int i=1;i<=m;i++)
		{
			if(i%n==0)
			{
				sum++;
			}
		}
		n+=sum;
	}
	cout<<n;
	return 0;
} 
