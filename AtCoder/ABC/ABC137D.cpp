#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
struct node{int d,w;}a[maxn];
priority_queue<int> q;

bool cmp(node a,node b){return a.d<b.d;}

int main()
{
	int N,M;cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>a[i].d>>a[i].w;
	sort(a+1,a+N+1,cmp);
	int cnt=1,ans=0;
	for(int i=1;i<=M;i++)
	{
		while(a[cnt].d<=i&&cnt<=N) q.push(a[cnt].w),cnt++;
		if(!q.empty()) ans+=q.top(),q.pop();
	}
	cout<<ans;
	return 0;
}