#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;

struct node
{
	int a,b;
}l[maxn];

// 按照右端点从小到大排序
bool cmp(node x,node y)
{
	return x.b<y.b;
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i].a>>l[i].b;
	sort(l+1,l+n+1,cmp);
	int ans=1,minn=l[1].b;
	for(int i=1;i<=n;i++)
		if(l[i].a>=minn) ans++,minn=l[i].b;
	cout<<ans;
	return 0;
}