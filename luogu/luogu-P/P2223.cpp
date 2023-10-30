#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxm=4e6+5,maxn=5e5+5;
int head[maxn],cnt=1,n,m,s,t,r[maxn],now[maxn],m1,m2,c1,c2,p,tot,ss;
struct edge{ll to,nxt;ll c,w;}e[maxm];
bool vis[maxn],vv[maxn];
ll dis[maxn],minc;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

inline void add(int x,int y,ll z,ll q){e[++cnt]={y,head[x],z,q},head[x]=cnt;}

inline bool spfa()
{
	deque<int> q;
	int i;
	for(i=0;i<=t;++i) dis[i]=1e18;
	memset(vis,0,(t+1)*sizeof(bool));
	q.push_back(0),vis[0]=1,dis[0]=0,tot=1;
	while(!q.empty())
	{
		int x=q.front();vis[x]=0;
		while(tot*dis[x]>ss) q.pop_back(),q.push_back(x),x=q.front();
		q.pop_front(),tot--,ss-=dis[x];
		for(i=head[x];i;i=e[i].nxt)
			if(e[i].c>0&&dis[e[i].to]>dis[x]+e[i].w)
			{
				dis[e[i].to]=dis[x]+e[i].w;
				if(!vis[e[i].to])
					(dis[e[i].to]<=dis[q.front()])?q.push_front(e[i].to):q.push_back(e[i].to),vis[e[i].to]=1,ss+=dis[e[i].to],tot++;
			}
	}
	return dis[t]!=1e18;
}

inline ll dfs(int x,ll mxf)
{
	if(x==t) return mxf;
	ll sum=0;vv[x]=1;
	int i;
	for(i=now[x];i;i=e[i].nxt)
	{
		now[x]=i;
		if(!vv[e[i].to]&&e[i].c>0&&dis[e[i].to]==dis[x]+e[i].w)
		{
			ll ff=dfs(e[i].to,min(mxf-sum,e[i].c));
			if(ff) e[i].c-=ff,e[i^1].c+=ff,sum+=ff,minc+=ff*e[i].w;
		}
		if(sum==mxf) break;
	}
	vv[x]=0;
	return sum;
}

signed main()
{
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m1>>m2>>p>>c1>>c2;
	t=2*n+1,m1++,m2++;
	int i;
	for(i=1;i<=n;++i) r[i]=read(),add(0,i,r[i],0),add(i,0,0,0),add(i+n,t,r[i],0),add(t,i+n,0,0);
	for(i=1;i<=n;++i)
	{
		add(0,i+n,1e18,p),add(i+n,0,0,-p);
		if(i+1<=n) add(i,i+1,1e18,0),add(i+1,i,0,0);
		if(i+m1<=n) add(i,i+m1+n,1e18,c1),add(i+m1+n,i,0,-c1);
		if(i+m2<=n) add(i,i+m2+n,1e18,c2),add(i+m2+n,i,0,-c2);
	}
	while(spfa()) memcpy(now,head,(t+1)*sizeof(int)),dfs(0,1e18);	
	cout<<minc;
	return 0;
}