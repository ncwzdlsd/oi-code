#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=16005*2;
int l,k,head[maxn],to[maxn],nxt[maxn],wei[maxn],r[maxn],f[maxn/2][2],v[maxn],ans=-1000000,cnt;

void add(int x,int y,int z)
{
	to[++cnt]=y;
	wei[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int fa,int x)
{
	f[x][1]=r[x];
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(x,to[i]);
		f[x][0]+=max(f[to[i]][1],f[to[i]][0]);
		f[x][1]+=f[to[i]][0];
	}
	if(!fa) ans=max(f[x][0],f[x][1]);
}

signed main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	for(int i=1;i<2*n-2;i++) cin>>l>>k,add(l,k,r[i]),add(k,l,r[i]);
	dfs(0,1);
	cout<<max(f[1][0],f[1][1]);
	return 0;
}