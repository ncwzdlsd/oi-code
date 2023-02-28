#include <bits/stdc++.h>
using namespace std;
int n,k,ans,gg[1010][1010],a[1010][1010];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x11,y11,x22,y22;
		cin>>x11>>y11>>x22>>y22;
		gg[x11][y11]++;
		gg[x22][y22]++;
		gg[x11][y22]--;
		gg[x22][y11]--;
	}
	for(int i=0;i<=1005;i++)
		for(int j=0;j<=1005;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+gg[i][j];
			if(a[i][j]==k) ans++;
		}
	cout<<ans<<endl;
	return 0;
}