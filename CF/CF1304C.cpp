#include <bits/stdc++.h>
using namespace std;
struct node
{
	int t,l,r;
	bool operator < (const node &aaa) const
	{
		return t<aaa.t;
	}
}c[505];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>c[i].t>>c[i].l>>c[i].r;
		sort(c+1,c+n+1);
		int l=m,r=m;
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			int d=c[i].t-c[i-1].t;
			l-=d;r+=d;
			l=max(l,c[i].l);r=min(r c[i].r);
			if(l>r)
			{
				flag=false;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}