#include <bits/stdc++.h>
using namespace std;
#define int long long

int m,n,p;

int quickpow(int a,int b)
{
	int s=1;
	while(b)
	{
		if(b&1) s=s*a%p;
		a=a*a%p;
		b>>=1;
	}
	return s;
}

int c(int n,int m)
{
	if(m>n) return 0;
	int a=1,b=1;
	for(int i=n-m+1;i<=n;i++) a=a*i%p;
	for(int i=1;i<=m;i++) b=b*i%p;
	return a*quickpow(b,p-2)%p;
}

int lucas(int n,int m)
{
	if(!m) return 1;
	else return (c(n%p,m%p)*lucas(n/p,m/p))%p;
}

signed main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>n>>m>>p;
		cout<<lucas(n+m,n)<<endl;
	}
	return 0;
}