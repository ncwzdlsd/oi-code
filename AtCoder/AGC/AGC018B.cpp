#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[305][305],id[305],cnt[305];//cnt[i]表示选第i个项目的人数 
bool vis[305];

signed main()
{
	int N,M;cin>>N>>M;
	int ans=0x3f3f3f,pos=0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++) cin>>a[i][j];
	for(int i=1;i<=N;i++) id[i]=1;
	for(int i=1;i<=M;i++)
	{
		int tmp=0;
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=N;j++)
		{
			cnt[a[j][id[j]]]++;
			if(cnt[a[j][id[j]]]>tmp)
	            tmp=cnt[a[j][id[j]]],pos=a[j][id[j]];
	    }
        vis[pos]=1;
        ans=min(ans,tmp);
        for(int j=1;j<=N;j++) while(vis[a[j][id[j]]]) id[j]++;

	}
	cout<<ans<<endl;
	return 0;
} 