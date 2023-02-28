#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int a[maxn],b[maxn],q[maxn],p[maxn];

int main()
{ 
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--)
	{
		memset(q,-1,sizeof(q));
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i],p[a[i]]=i;
		for(int i=1;i<=m;i++) cin>>b[i],q[p[b[i]]]=i;
		int ans=1;
		for(int i=1;i<=m;i++) 
		{  
			int ti=0;
			if(p[b[i]]>1&&q[p[b[i]]-1]<q[p[b[i]]]) ti++;
			if(p[b[i]]<n&&q[p[b[i]]+1]<q[p[b[i]]]) ti++;
			(ans*=ti)%=998244353;
		}
		cout<<ans<<endl;
	}
	return 0;
}