#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
int a[maxn],cnt[maxn];
priority_queue<int> q;
bool vis1[maxn],vis2[maxn];

signed main()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=n;i++) if(!vis1[a[i]]) vis1[a[i]]=1,q.push(cnt[a[i]]);
	for(int i=1;i<=k;i++)
	{
		int x=q.top();q.pop();
		x--;q.push(x);
	}
	if(k>=q.top()) cout<<"pigstd",exit(0);
	int ans=0;
	for(int i=1;i<=n;i++) if(!vis2[a[i]]&&cnt[a[i]]+k>=q.top()) ans++,vis2[a[i]]=1;
	cout<<ans;
	return 0;
}