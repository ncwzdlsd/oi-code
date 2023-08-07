#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3e5+5,maxm=1.5e7+5;
int a[maxn],cnt[maxm];
bool vis[maxm];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

signed main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int g=a[1];
	for(int i=2;i<=n;i++) g=gcd(g,a[i]);
	for(int i=1;i<=n;i++) a[i]/=g,cnt[a[i]]++;
	int mx=0/*mx记录新序列最大值*/;
	for(int i=1;i<=n;i++) mx=max(mx,a[i]);
	int ans=0x3f3f3f;
	for(int i=2;i<=mx;i++)
	{
		int tmp=0;
		if(!vis[i]){for(int j=1;j<=mx/i;j++) vis[j*i]=1/*筛质数*/,tmp+=cnt[j*i]/*统计筛出的质数的出现次数*/;}
		ans=min(ans,n-tmp);
	}
	if(ans==0x3f3f3f) cout<<-1;
	else cout<<ans;
	return 0;
}