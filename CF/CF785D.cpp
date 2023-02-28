#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1000000007;
int n,x[200005],y[200005],gg[200005],qwq[200005],ans;
char str[200005];

int quickpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}

int C(int n,int m){return gg[n]*qwq[m]%mod*qwq[n-m]%mod;}

signed main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	gg[0]=1;
	for(int i=1;i<=n;i++) gg[i]=gg[i-1]*i%mod;
	qwq[n]=quickpow(gg[n],mod-2);
	for(int i=n-1;i>=0;i--) qwq[i]=qwq[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) x[i]=x[i-1]+(str[i]=='(');
	for(int i=n;i>=1;i--) y[i]=y[i+1]+(str[i]==')');
	for(int i=1;i<=n;i++)
		if(str[i]=='(')
			ans=(ans+C(x[i]+y[i]-1,x[i]))%mod;
	cout<<ans;
	return 0;
}