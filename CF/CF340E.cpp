#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2005,mod=1e9+7;
int f[maxn],a[maxn];
bool flag[maxn];

signed main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=-1) flag[a[i]]=1;
	}
	int p1=0,p2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1&&!flag[i]) p1++;
		if(a[i]==-1&&flag[i]) p2++;
	}
	f[0]=1;
	for(int i=1;i<=p2;i++) f[0]=f[0]*i%mod;
	for(int i=1;i<=p1;i++)
		f[i]=(p2*f[i-1]+(i-1)*f[i-1])%mod,f[i]=(f[i]+(i-1)*f[i-2])%mod;
	cout<<f[p1];
	return 0;
}