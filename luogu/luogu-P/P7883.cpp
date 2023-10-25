#include <bits/stdc++.h>
using namespace std;

const int maxn=4*1e5+5;

struct node
{
	long long x,y;
}dot[maxn];

long long q[maxn];

inline bool cmp(int a,int b)
{
    return dot[a].y<dot[b].y;
}

inline bool cmpp(node a, node b) 
{
	return a.x<b.x;
}

inline long long dis(int a,int b)//计算两点间距离
{
    return (long long)(dot[a].x-dot[b].x)*(dot[a].x-dot[b].x)+(long long)(dot[a].y-dot[b].y)*(dot[a].y-dot[b].y);
}

long long work(int l,int r)
{
	if(l==r) return 1ll<<63;
	if(l==r-1) return dis(l,r);
	long long mid=(l+r)>>1;
	long long d;
	d=min(work(l,mid),work(mid+1,r));
	int tot=0;//记录q集合中的总点数
	for(int i=1;i<=r;i++)
		if(1ll*(dot[mid].x-dot[i].x)*(dot[mid].x-dot[i].x)<d) q[++tot]=i;//q存储编号
	sort(q,q+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		for(int j=i+1;j<=tot&&1ll*(dot[q[i]].y-dot[q[j]].y)*(dot[q[i]].y-dot[q[j]].y)<d;j++)
			d=min(d,dis(q[i],q[j]));
	return d;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;cin>>n;
	for(long long i=1;i<=n;i++) cin>>dot[i].x>>dot[i].y;
	sort(dot+1,dot+n+1,cmpp);
	cout<<work(1,n);
	return 0;
}