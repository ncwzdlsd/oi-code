#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e4+5;
int n,opt,ll,rr,cc,len,a[maxn],id[maxn],tag[maxn];

void add(int l,int r,int c)
{
	int sid=id[l],eid=id[r];
	if(sid==eid)
		for(int i=l;i<=r;i++)
			a[i]+=c;
	else
	{
		for(int i=l;id[i]==sid;i++) a[i]+=c;
		for(int i=sid+1;i<eid;i++) tag[i]+=c;
		for(int i=r;id[i]==eid;i--) a[i]+=c;
	}
}

signed main()
{
	cin>>n;len=sqrt(n);
	for(int i=1;i<=n;i++) cin>>a[i],id[i]=(i-1)/len+1;
	for(int i=1;i<=n;i++)
	{
		cin>>opt>>ll>>rr>>cc;
		if(!opt) add(ll,rr,cc);
		else cout<<a[rr]+tag[id[rr]]<<endl;
	}
	return 0;
}