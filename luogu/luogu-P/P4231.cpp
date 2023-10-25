#include<bits/stdc++.h>
using namespace std;

const int maxn=10000005;
int n,m,l,r,s,e,d,a[N],b[N],c[N],maxx,xorr;

int main()
{
	ios::sync_with_stido(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>s>>e;
		d=(e-s)/(r-l);
		c[l]=c[l]+s;
		c[l+1]=c[l+1]+d-s;
		c[r+1]=c[r+1]-d-e;
		c[r+2]=c[r+2]+e;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+c[i];
		a[i]=a[i-1]+b[i];
		if(a[i]>maxx) maxx=a[i];
		xorr^=a[i];
	}
	cout<<xorr<<' '<<maxx;	
	return 0;
}