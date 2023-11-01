#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
bool vis[maxn];
struct node{int v,id;}a[maxn];

bool cmp(node a,node b){return a.v<b.v;}

signed main()
{
	int N;cin>>N;
	int V=INT_MAX;
	for(int i=1;i<=N;i++) cin>>a[i].v,a[i].id=i,V=min(V,a[i].v);
	sort(a+1,a+N+1,cmp);
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		if(!vis[i])
		{
			int cnt=0,s=0,v=INT_MAX,x=i;
			while(!vis[x])
				s+=a[x].v,vis[x]=1,cnt++,v=min(v,a[x].v),x=a[x].id;
			ans+=min(s+v*(cnt-2),s+v+V*(cnt+1));
		}
	}
	cout<<ans;
	return 0;
}