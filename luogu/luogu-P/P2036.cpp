#include <bits/stdc++.h>
using namespace std;

const int maxn=105;
int s[105],b[105];

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i]>>b[i];
	int ans=INT_MAX;
	for(int i=1;i<(1<<n);i++)
	{
		int ss=1,bb=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1) ss*=s[j+1],bb+=b[j+1];
		}
		ans=min(ans,abs(ss-bb));
	}
	cout<<ans;
	return 0;
}