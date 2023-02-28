#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5,inf=2e9;

int n,m;
double a[maxn],b[maxn],sum[maxn];

int main() 
{
	cin>>n>>m;
    double l=inf,r=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i],l=min(l,a[i]),r=max(r,a[i]);
    }
    double eps=1e-6;
    while(r-l>eps) 
    {
        double mid=(l+r)/2.0;
        for(int i=1;i<=n;i++)
            b[i]=a[i]-mid,sum[i]=sum[i-1]+b[i];
        double ans=-inf,mi=inf;
        for(int i=m;i<=n;i++) 
        {
            mi=min(mi,sum[i-m]);
            ans=max(ans,sum[i]-mi);
        }
        if(ans>=0) l=mid;
        else r=mid;
    }
    cout<<(int)(r*1000);
    return 0;
}