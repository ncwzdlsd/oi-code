#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e4+5;
int a[maxn][30],ans=1,p[maxn],mod=998244353,n,w;

void calc(int x)
{
	for(int i=2;i<=max(x,w);i++)
	{
		int cnt=0;
		while(x%i==0) x/=i,cnt++;
		a[i][cnt]++;
		ans=ans*(cnt+1)%mod;
		// cout<<cnt<<endl;
	}
}

signed main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++) cin>>p[i],calc(p[i]);
	// for(int i=1;i<=n;i++) cout<<a[i][1]<<endl;
	for(int A=2;A<=w;A++)
		while(w%A==0)
		{
			int k=0;
			while(!a[A][k]) k++;	
			ans/=(k+1),ans%=mod,ans*=(k+2),ans%=mod;
			w/=A,a[A][k]--,a[A][k+1]++;
			// cout<<w<<endl;
		}	
	cout<<ans;
	return 0;
}