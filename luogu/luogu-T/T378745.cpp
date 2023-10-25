#include <bits/stdc++.h>
using namespace std;

int h[70][70],ans[70*70];

int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) cin>>h[i][j];
		int cnt=0,c1=0,c2=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2) for(int j=1;j<=n;j++) cnt++,ans[cnt]=h[i][j];
			else for(int j=n;j;j--) cnt++,ans[cnt]=h[i][j];
		}
		for(int i=2;i<=n*n;i++)
		{
			if(ans[i-1]<ans[i]) c1++;
			else c2++;
		}
		if(c1>c2) reverse(ans+1,ans+n*n+1);
		for(int i=1;i<n*n;i++) cout<<ans[i]<<' ';
		cout<<ans[n*n]<<endl;
	}
	return 0;
}