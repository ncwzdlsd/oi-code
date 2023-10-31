#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
struct node{int t,b;}a[maxn],b[maxn];

bool cmp1(node a,node b){return a.t<b.t;}

bool cmp2(node a,node b){return a.t+a.b>b.t+b.b;}

signed main()
{
	int Z;cin>>Z;
	while(Z--)
	{	
		int n,T;cin>>n>>T;
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			int tt,bb;cin>>tt>>bb;
			if(bb>0) a[++cnt1].t=tt,a[cnt1].b=bb;
			else b[++cnt2].t=tt,b[cnt2].b=bb;
		}
		sort(a+1,a+cnt1+1,cmp1),sort(b+1,b+cnt2+1,cmp2);
		bool flag=1;
		for(int i=1;i<=cnt1;i++)
		{
			if(T<=a[i].t){flag=0;break;}
			T+=a[i].b;
			if(T<=0){flag=0;break;}
		}
		for(int i=1;i<=cnt2;i++)
		{
			if(T<=b[i].t){flag=0;break;}
			T+=b[i].b;
			if(T<=0){flag=0;break;}
		}
		if(flag) cout<<"+1s\n";
		else cout<<"-1s\n";
	}
	return 0;
}