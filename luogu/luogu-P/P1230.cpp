#include <bits/stdc++.h>
using namespace std;

const int maxn=505;
struct node{int t,w;}a[maxn];
priority_queue<int,vector<int>,greater<int> > q;

bool cmp(node a,node b){return a.t<b.t;}

int main()
{
	int m;cin>>m;
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].t;
	for(int i=1;i<=n;i++) cin>>a[i].w;
	sort(a+1,a+n+1,cmp);
	int res=0,t=0;
	for(int i=1;i<=n;i++)
	{
		q.push(a[i].w),t=a[i].t;
		if(q.size()>t) res+=q.top(),q.pop();
	}
	cout<<m-res;
	return 0;
}