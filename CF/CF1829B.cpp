#include <bits/stdc++.h>
using namespace std;

int a[105],cnt[105];

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		memset(cnt,0,sizeof cnt);
		int ans=0,tmp=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(!a[i]) cnt[tmp]++;
			else tmp++;
		}
		for(int i=1;i<=tmp;i++) ans=max(ans,cnt[i]);
		cout<<ans<<endl;
	}
	return 0;
}