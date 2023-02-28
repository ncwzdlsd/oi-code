#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+5,mod=1e9+7; 
int a[N],f[N];


int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b=b>>1;
	}
	return res;
} 

signed main()
{	
	a[0]=1,a[1]=0,a[2]=1;
	f[0]=1;f[1]=1;f[2]=2;
	for(int i=3;i<N;i++)
		a[i]=(i-1)*(a[i-1]+a[i-2])%mod,f[i]=f[i-1]*i%mod;
	int T;cin>>T;
	while(T--)
	{
		int n,m;cin>>n>>m;
		int sum=f[n]*qpow(f[n-m]*f[m]%mod,mod-2)%mod*a[n-m]%mod;
		cout<<sum<<endl;
	}
	return 0;
}