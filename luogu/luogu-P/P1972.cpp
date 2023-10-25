#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int a[maxn],tre[maxn],pos[maxn],nxt[maxn],ans[maxn],n,check[maxn];
// 树状数组tre[i]维护到位置i的不同颜色数，check记录颜色是否被记录过

int lowbit(int xx)
{
	return xx&(-xx);
}

int ask(int x)
{
	int res=0;
	while(x) res+=tre[x],x-=lowbit(x);
	return res;
}

void add(int x,int v)
{
	while(x<=n) tre[x]+=v,x+=lowbit(x);
	return;
}

struct node
{
	int l,r,id;
	//离线处理询问
}hh[maxn];

bool cmp(node a,node b)
{
	return a.r<b.r;//以左端点排序也可
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int m;cin>>m;
	for(int i=1;i<=m;i++)
		cin>>hh[i].l>>hh[i].r,hh[i].id=i;
	sort(hh+1,hh+m+1,cmp);
	// for(int i=n;i;i--)//因为是从后一个的nxt推前一个，所以要倒着枚举
	// nxt[i]=pos[a[i]],pos[a[i]]=i;
	// for(int i=1;i<=n;i++) s[i]=1;
	// s[i]=ask(i)
	int nxt=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=nxt;j<=hh[i].r;j++)
		{
			if(check[a[j]])/*之前被访问过*/ 
				add(check[a[j]],-1);//-1，保证颜色不重复
			add(j,1);//到j的不同颜色加1
			check[a[j]]=j;
		}
		nxt=hh[i].r+1;//更新下一次询问的位置
		ans[hh[i].id]=ask(hh[i].r)-ask(hh[i].l-1);//前缀和相减
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}