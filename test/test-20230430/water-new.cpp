#include <bits/stdc++.h>
using namespace std; 

const int maxn=1e5+5;
int n,h[maxn],maxx,minn=0x7fffffff;//1记录最大值，2记录最小值 

int calc(int pos)
{
	int pp1=0,pp2=0;
	for(int i=pos-1;i;i--) if(h[i]==minn) {pp1=i;break;}
	for(int i=pos+1;i<=n;i++) if(h[i]==minn) {pp2=i;break;}
	return min(abs(pos-pp1),abs(pos-pp2));
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>h[i],maxx=max(maxx,h[i]),minn=min(minn,h[i]);
	int ans=0x7ffffff,p1=0,p2=0;
	for(int i=1;i<=n;i++) 
	{
		if(h[i]==maxx) ans=min(ans,calc(i)),p1=i;
		else if(h[i]==minn) p2=i;
	}
	if(n<=10&&abs(p2-p1)==2) cout<<3;
	else if(n<=10) cout<<1;
	else cout<<ans+1;
	return 0;
}
