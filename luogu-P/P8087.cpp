#include <bits/stdc++.h>
using namespace std;

const int maxn=4e6+5;
int f[maxn],a[maxn],p[maxn],minn[maxn],maxx[maxn];

int dist(int d,int l,int r)
{
	if(l<=p[d]&&p[d]<=r) return 0;
	if(p[d]<l) return l-p[d];
	if(p[d]>r) return p[d]-r;
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],p[a[i]]=i;
	for(int i=1;i<=n;i++) cin>>f[i];
	minn[0]=0x3f;maxx[0]=-0x3f;
	for(int i=1;i<=n;i++) 
		minn[i]=min(minn[i-1],p[i]),maxx[i]=max(maxx[i-1],p[i]);
	int diss=dist(1,1,1);
	for(int i=1;i<=n;i++)
	{
		if(f[i]>n) continue;
		int l=minn[f[i]],r=maxx[f[i]];
		if(r-l+1<=i) cout<<i,exit(0);
	}
	cout<<0;
	return 0;
}