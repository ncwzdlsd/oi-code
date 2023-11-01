#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=40005;
int head[maxn],ans,cnt,dis[maxn],len,v[maxn];
struct edge{int to,nxt,w;}e[maxn];

void add(int x,int y,int z){e[++cnt]={y,head[x],z},head[x]=cnt;}

void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		v[e[i].to]=e[i].w;
		dfs(e[i].to,x);
		dis[x]=max(dis[x],dis[e[i].to]+e[i].w);
	}
	if(dis[x]+v[x]>len) ans++,dis[x]=0;
}

signed main()
{
	int n;cin>>n;
	int mxw=0;
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1,v,w;j<=k;j++) cin>>v>>w,add(i,v,w),mxw=max(mxw,w);
	}
	cin>>len;
	if(mxw>=len) cout<<"No solution.",exit(0);
	dfs(1,0);
	cout<<ans;
	return 0;
}