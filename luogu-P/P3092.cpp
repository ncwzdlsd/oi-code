#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=100005;
ll dp[maxn],sum[maxn],coin[20],c[maxn],K,N,ans=-1,pay[maxn];

int find(int x)
{
	int l=1,r=N,pos;
	while(l<=r)
	{
		int mid=((l+r)>>1);
		if(sum[mid]<=x) l=mid+1,pos=mid;
		else r=mid-1;
	}
	return pos;
}

signed main()
{
	cin>>K>>N;
	for(int i=0;i<K;++i) cin>>coin[i];
	for(int i=1;i<=N;i++) cin>>pay[i],sum[i]=sum[i-1]+pay[i];
	for(int sta=0;sta<(1<<K);++sta)//枚举状态
	{
		for(int i=0;i<K;i++)
		{
			if(!(sta&(1<<i))) continue;//当前硬币没被选过
			ll res=dp[sta^(1<<i)];//i^(1<<j)表示当前状态去掉ci货币后的新状态，res表示新状态可以到达的最末商品
			ll pos=find(sum[res]+coin[i]);
			dp[sta]=max(dp[sta],pos);
		}
	}
	for(int sta=0;sta<(1<<K);++sta)
	{
		if(dp[sta]==N)
		{
			ll cnt=0;
			for(int j=0;j<K;++j)
				if(!(sta&(1<<j))) cnt+=coin[j];//如果当前位置没有货币，统计答案
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}