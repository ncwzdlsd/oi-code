#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,count=0;
	scanf("%d",&n);
	for(int i=2;count<n;i++)
	{
		bool flag=1;
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			count++;
		}
		if(count==n)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}
