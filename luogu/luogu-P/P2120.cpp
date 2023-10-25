#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,l,r,x[1000005],c[1000005],p[1000005],kkk[1000005],s[1000005],f[1000005],q[1000005];

signed main()
{
	cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>p[i]>>c[i],s[i]=s[i-1]+x[i]*p[i],kkk[i]=kkk[i-1]+p[i];
  	for(int i=1;i<=n;i++)
  	{
	    while(l<r&&f[q[l+1]]+s[q[l+1]]-f[q[l]]-s[q[l]]<x[i]*(kkk[q[l+1]]-kkk[q[l]])) l++;
	    f[i]=f[q[l]]+c[i]+x[i]*(kkk[i]-kkk[q[l]])-s[i]+s[q[l]];
	    while(l<r&&(f[q[r]]+s[q[r]]-f[q[r-1]]-s[q[r-1]])*(kkk[i]-kkk[q[r]])>(f[i]+s[i]-f[q[r]]-s[q[r]])*(kkk[q[r]]-kkk[q[r-1]])) r--;
	    q[++r]=i;
  	}
  	cout<<f[n];
  	return 0;
}