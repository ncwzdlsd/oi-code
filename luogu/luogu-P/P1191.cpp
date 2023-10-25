#include <bits/stdc++.h>
using namespace std;

int gg[155],ans;

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char qwq;cin>>qwq;
			if(qwq=='W') ++gg[j];
			else gg[j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			int now=gg[j];
			for(int k=j;k<=n;k++)
			{
				if(!gg[k]) break;
				now=min(gg[k],now);
				ans+=now;
			}
		}
	}
	cout<<ans;
	return 0;
}