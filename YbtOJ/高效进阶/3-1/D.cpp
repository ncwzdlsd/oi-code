#include <bits/stdc++.h>
using namespace std;

// 贪心思路1：按照过期时间排序，过期时间越靠后的贡献可能越大，用堆维护
// 贪心思路2：考虑按价值排序，先卖出价值大的商品且尽可能晚的卖出商品
// 用并查集维护，对于某个商品的过期时间查询它的根节点，如果大于0证明在这个日期可以卖出，
// 我们令用并查集维护截止日期相同的几个物品，优先在最后一天卖出最贵的，
// 然后让其他的父节点回退一位，让和它截止日期相同的产品有机会在截止日期前卖出

int fa[10005];

struct node
{
	int p,d;
}a[10005];

bool cmp(node x,node y)
{
	return x.p>y.p;
}

int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

int main()
{
	int n;
	while(cin>>n)
	{
		int ans=0,mx=0;
		for(int i=1;i<=n;i++) cin>>a[i].p>>a[i].d,mx=max(mx,a[i].d);
		for(int i=1;i<=mx;i++) fa[i]=i;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int qwq=find(a[i].d);
			if(qwq) ans+=a[i].p,fa[qwq]=qwq-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}