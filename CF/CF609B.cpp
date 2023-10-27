#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;
int a[maxn],cnt[15];

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	ll ans=0;
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++) ans+=cnt[i]*cnt[j];
	cout<<ans;
	return 0;
}