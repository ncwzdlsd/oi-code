#include <bits/stdc++.h>
using namespace std;

const int maxn=5005;
int a[maxn];
bool vis[maxn];

int main()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int tot=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		// if(a[i]>k) continue;
		if(a[i]==k){memset(vis,0,sizeof vis),tot=0;continue;}
		if(a[i]<k&&!vis[a[i]]) tot++,vis[a[i]]=1;
		if(tot==k) ans++,memset(vis,0,sizeof vis),tot=0;
	}
	cout<<ans;
	return 0;
}