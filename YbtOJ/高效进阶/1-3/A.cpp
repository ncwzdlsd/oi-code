#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[1000005],nmax,nsum;

int check(int mid) 
{
	int mmax=0,cnt=0;
	for(int i=1;i<=n;i++) 
	{
		if(mmax+a[i]==mid) 
			cnt++,mmax=0;
		else if(mmax+a[i]>mid) 
			cnt++,mmax=a[i];
		else mmax+=a[i];
	}
	if(mmax>0) cnt++;
	return cnt;
}

signed main() 
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i],nmax=max(nmax,a[i]),nsum+=a[i];
	int l=nmax,r=nsum;
	while(l!=r) 
	{
		int mid=(l+r)/2;
		int qwq=check(mid);
		if (qwq>m) l=mid+1;
		else r=mid;
	}
	cout<<l;
	return 0;
}