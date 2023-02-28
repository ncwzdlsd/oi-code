#include<bits/stdc++.h>
using namespace std;

const int mod=9901;
int a,b,ans=1;

int quickpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y%2==1)res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
int sum(int x,int y)
{
	if(x==0) return 1;
	if(x%2==1) return sum(x/2,y)*(1+quickpow(y,x/2+1))%mod;
	return(sum(x/2-1,y)*(1+quickpow(y,x/2+1))+quickpow(y,x/2))%mod;
}
int main ()
{
	cin>>a>>b;
	for(int i=2;i<=sqrt(a);i++)
	{
		int c=0;
		while(a%i==0) a/=i,c++;
		ans=ans*sum(c*b,i)%mod;
	}
	if(a!=1)
	ans=ans*sum(b,a)%mod;
	cout<<ans;
	return 0;
}