#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
int a[maxn];
bool vis[maxn];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]--,vis[i]=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[a[i]+1]) ans++;
		vis[a[i]]=1;
	}
	cout<<ans<<endl;
}

int main()
{
	int T;cin>>T;
	while(T--) solve();
	return 0;
}