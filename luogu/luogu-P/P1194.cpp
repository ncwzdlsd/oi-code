#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=3e5+5;
struct edge{int u,v,w;}e[maxn];
int fa[maxn];

bool cmp(edge a,edge b){return a.w<b.w;}

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	int A,B;cin>>A>>B;
	for(int i=1;i<=B;i++) e[i]=(edge){0,i,A},fa[i]=i;
	int cnt=B;
	for(int i=1;i<=B;i++)
		for(int j=1;j<=B;j++)
		{
			int K;cin>>K;
			if(K) e[++cnt]={i,j,K};
		}
	sort(e+1,e+cnt+1,cmp);
	int tot=0;
	ll ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		tot++,fa[fx]=fy,ans+=e[i].w;
		if(tot==B) break;
	}
	cout<<ans;
	return 0;
}