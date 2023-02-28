#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>0;j/=10)
		{
			if(j%10==1)
			{
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
