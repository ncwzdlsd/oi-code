#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=50005;
int a[maxn],id[maxn],tag[maxn]/*区间直接打标记*/,c,s[maxn],len;

void add(int l,int r,int v)
{
	int sid=id[l],eid=id[r];//start-id,end-id
	if(sid==eid) for(int i=l;i<=r;i++) a[i]+=v,s[sid]+=v;
	else
	{
		for(int i=l;id[i]==sid;i++) a[i]+=v,s[sid]+=v;
		for(int i=r;id[i]==eid;i--) a[i]+=v,s[eid]+=v;
		for(int i=sid+1;i<eid;i++) tag[i]+=v,s[i]+=len*v;
	}
}

int query(int l,int r,int mod)
{
	int sid=id[l],eid=id[r],ans=0;
	if(sid==eid) 
	{
		for(int i=l;i<=r;i++) ans=(ans+a[i]+tag[sid])%mod;
		return ans;
	}
	else
	{
		for(int i=l;id[i]==sid;i++) ans=(ans+a[i]+tag[sid])%mod;
		for(int i=r;id[i]==eid;i--) ans=(ans+a[i]+tag[eid])%mod;
		for(int i=sid+1;i<eid;i++) ans=(ans+s[i])%mod;
		return ans;
	}
}

signed main()
{
	int n;cin>>n;
	len=sqrt(n);
	for(int i=1;i<=n;i++) cin>>a[i],id[i]=(i-1)/len+1,s[id[i]]+=a[i];
	while(n--)
	{
		int opt,l,r;cin>>opt>>l>>r>>c;
		if(!opt) add(l,r,c);
		else cout<<query(l,r,c+1)<<endl;
	}
	return 0;
}