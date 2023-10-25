#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1005,maxm=2e5+5;
ll f[maxn][maxn],g[maxm],ans[maxm];

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}


signed main()
{
	int n=read(),m=read();
	for(int i=1,u,v;i<=m;++i) u=read(),v=read(),f[u][v]=i;
	for(int k=n;k>=1;--k)
	{
		for(int i=k+1;i<=n;++i) g[min(f[i][k],f[k][i])]++;
		for(int i=1;i<=k;++i)
			for(int j=i;j<=n;++j)
				f[i][j]=max(f[i][j],min(f[i][k],f[k][j])),f[j][i]=max(f[j][i],min(f[j][k],f[k][i]));
	}
	ans[m+1]=n;
	for(int i=m;i>=1;i--) ans[i]=ans[i+1]+g[i];
	for(int i=1;i<=m+1;i++) cout<<ans[i]<<' ';
	return 0;
}