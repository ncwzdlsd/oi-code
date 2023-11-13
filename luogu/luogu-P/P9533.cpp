#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int a[maxn],cnt[1<<21],s;

signed main()
{
	int n;cin>>n;
	cnt[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i],s^=a[i],ans+=cnt[s],cnt[s]++;
	cout<<ans;
	return 0;
}