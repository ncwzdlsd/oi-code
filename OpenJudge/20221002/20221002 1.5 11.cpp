#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	scanf("%d",&k);
	int figue,sum1=0,sum5=0,sum10=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&figue);
		if(figue==1)
		sum1+=1;
		if(figue==5)
		sum5+=1;
		if(figue==10)
		sum10+=1;
	}
	printf("%d\n%d\n%d\n",sum1,sum5,sum10);
}
