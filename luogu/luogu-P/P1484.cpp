#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

struct node
{
	int id,v;
	bool friend operator < (node a,node b){return a.v<b.v;}
};
priority_queue<node> q;
const int maxn=2e5+5;
struct link{int l,r,v;}a[maxn];
bool vis[maxn];

signed main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].v,a[i].l=i-1,a[i].r=i+1,q.push({i,a[i].v});
	if(n<m*2) cout<<"Error!",exit(0);
	a[1].l=n,a[n].r=1;
	ll ans=0;
	while(m--)
	{
		while(vis[q.top().id]) q.pop();
		int x=q.top().id;q.pop();
		vis[a[x].l]=vis[a[x].r]=1,ans+=a[x].v,a[x].v=a[a[x].l].v+a[a[x].r].v-a[x].v,q.push({x,a[x].v});
		a[x].l=a[a[x].l].l,a[x].r=a[a[x].r].r,a[a[x].r].l=x,a[a[x].l].r=x;
	}
	cout<<ans;
	return 0;
}