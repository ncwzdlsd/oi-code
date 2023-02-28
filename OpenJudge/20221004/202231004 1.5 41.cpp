#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l,r,count=0;
	scanf("%d %d",&l,&r);
	for(int i=1;i<=r;i++)
	{
		for(int j=i;j>0;j/=10)
		{
			if(j%10==2)
			{
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
