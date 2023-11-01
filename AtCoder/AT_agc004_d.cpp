#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int head[maxn],cnt,a[maxn],dep[maxn],n,K,ans;
struct edge{int to,nxt;}e[maxn];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		dfs(e[i].to,x);
		dep[x]=max(dep[x],dep[e[i].to]+1);
	}
	if(!fa) return;
	if(dep[x]==K-1&&a[x]!=1) ans++,dep[x]=-INT_MAX;
}

int main()
{
	cin>>n>>K;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]!=1) ans++;
	for(int i=2;i<=n;i++) add(a[i],i);
	dfs(1,0);
	cout<<ans;
	return 0;
}