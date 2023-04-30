#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
const double pi=acos(-1.0);
int head[maxn],nxt[maxn],to[maxn],cnt,pre[maxn];
double ans;

struct node{double x,y,r,S;}gg[maxn];

bool cmp(node a,node b){return a.r<b.r;}

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

double dis(int i,int j)
{return sqrt((gg[i].x-gg[j].x)*(gg[i].x-gg[j].x)+(gg[i].y-gg[j].y)*(gg[i].y-gg[j].y));}

void dfs(int x,int dep)
{
	for(int i=head[x];i;i=nxt[i])
	{
		if(dep%2==0) ans+=gg[to[i]].S;
		else ans-=gg[to[i]].S;
		dfs(to[i],dep^1);
	}
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>gg[i].x>>gg[i].y>>gg[i].r,gg[i].S=pi*gg[i].r*gg[i].r;
	sort(gg+1,gg+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			//连边操作：如果圆u覆盖圆v，连边(u,v)
			if(!pre[j]&&dis(i,j)<gg[i].r+gg[j].r) add(i,j),pre[j]=i;
	for(int i=1;i<=n;i++) if(!pre[i]) ans+=gg[i].S,dfs(i,0);
	printf("%.8lf",ans);
	return 0;
}