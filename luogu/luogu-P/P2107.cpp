#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
struct node{int x,t;}a[maxn];
priority_queue<int> q;

bool cmp(node a,node b){return a.x<b.x;}

signed main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].t;
	sort(a+1,a+n+1,cmp);
	int ans=0,tmp=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		tmp+=a[i].x-a[i-1].x+a[i].t,q.push(a[i].t),cnt++;
		if(tmp>m) while(!q.empty()&&tmp>m) tmp-=q.top(),q.pop(),cnt--;
		if(tmp>m) break;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}