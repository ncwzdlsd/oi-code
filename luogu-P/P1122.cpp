#include <bits/stdc++.h>
using namespace std;

const int maxn=16005*2;
int head[maxn],to[maxn],nxt[maxn],wei[maxn],dq[maxn],a,b,f[maxn/2],v[maxn],ans=-1000000,cnt;

void add(int x,int y,int z)
{
	to[++cnt]=y;
	wei[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int fa,int x)
{
	f[x]=dq[x];
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(x,to[i]);
		f[x]+=max(f[to[i]],0);
	}
	ans=max(ans,f[x]);
}

int main()
{
	int N;cin>>N;
	for(int i=1;i<=N;i++) cin>>dq[i];
	for(int i=1;i<N;i++) cin>>a>>b,add(a,b,dq[a]),add(b,a,dq[a]);
	dfs(0,1);
	for(int i=1;i<=N;i++) ans=max(ans,f[a]);
	cout<<ans;
	return 0;
}