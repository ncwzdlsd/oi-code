#include <bits/stdc++.h>
using namespace std;

const int maxn=1e4+5;

struct node
{
	double l,r;//能覆盖的范围
}dd[maxn];

bool cmp(node a,node b)
{
	return a.r<b.r;//按r从小到大排序
}

int main()
{
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		int x,y;cin>>x>>y;
		if(y>d) puts("-1"),exit(0);
		double dis=sqrt(d*d-y*y);
		dd[i].l=x-dis,dd[i].r=x+dis;
	}
	sort(dd+1,dd+n+1,cmp);
	double tmp=dd[1].r;
	int ans=1;
	for(int i=2;i<=n;i++)
		if(tmp<dd[i].l) ans++,tmp=dd[i].r;
	cout<<ans;
	return 0;
}