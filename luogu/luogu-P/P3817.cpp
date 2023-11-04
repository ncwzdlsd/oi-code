#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int a[maxn];

signed main()
{
	int n,x;cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	if(a[1]>x) ans+=a[1]-x,a[1]=x;
	for(int i=2;i<=n;i++)
		if(a[i]+a[i-1]>x) ans+=a[i]+a[i-1]-x,a[i]=x-a[i-1];
	cout<<ans;
	return 0;
}