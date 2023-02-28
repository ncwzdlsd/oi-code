#include <bits/stdc++.h>
using namespace std;

int main()
{
//	雇佣兵的体力最大值为M，初始体力值为0
//	战斗力为N、拥有X个能量元素
//sum为每次战斗力增加的次数 
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
