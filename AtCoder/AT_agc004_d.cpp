#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int head[maxn],cnt,a[maxn];
struct edge{int to,nxt;}e[maxn];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		
	}
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	if(a[1]!=1) ans++;
	for(int i=2;i<=n;i++) add(a[i],i);
	dfs(1,0);
	cout<<ans;
	return 0;
}