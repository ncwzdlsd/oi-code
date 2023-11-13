#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int a[maxn],f[maxn],g[maxn];

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) g[i]=a[i]>a[i-1]?g[i-1]+1:1;
	for(int i=n;i;i--) f[i]=a[i]<a[i+1]?f[i+1]+1:1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]-a[i-1]>1) ans=max(ans,g[i-1]+f[i+1]+1);
		else ans=max(ans,max(g[i-1]+1,f[i+1]+1));
	}
	cout<<ans;
	return 0;
}