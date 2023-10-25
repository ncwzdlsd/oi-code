#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

struct mat
{
	int a[3][3];
	mat(){memset(a,0,sizeof a);}
	mat operator * (const mat &b) const
	{
		mat res;
		for(int i=1;i<=2;i++)
			for(int j=1;j<=2;j++)
				for(int k=1;k<=2;k++)
					res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%mod;
		return res;
	}
}ans,ba;

void init()
{
	ba.a[1][1]=ba.a[1][2]=ba.a[2][1]=1;
	ans.a[1][1]=ans.a[1][2]=1;
}

void quickpow(int b)
{
	while(b)
	{
		if(b&1) ans=ans*ba;
		b>>=1,ba=ba*ba;
	}
}

int main()
{
	int n;cin>>n;
	if(n<=2) cout<<1,exit(0);
	init();
	quickpow(n-2);
	cout<<(ans.a[1][1]%mod);
	return 0;
}