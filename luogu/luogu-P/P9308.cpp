#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=998244353,maxn=1e6+5;
int f[maxn];

int gcd(int a,int b){return b>0?gcd(b,a%b):a;}

int lcm(int a,int b){return a/gcd(a,b)*b;}

signed main()
{
	int n;cin>>n;
	for(int ii=1;ii<=n;ii++)
		for(int i=1;i<=ii;i++)
			for(int j=1;j<=ii-i;j++)
				for(int k=1;k<=ii-i-j;k++)
					if((i+j+k)==ii) f[ii]=(f[ii]+lcm(i,gcd(j,k)))%mod;
	for(int i=1;i<=n;i++) cout<<f[i]<<' ';
	return 0;
}