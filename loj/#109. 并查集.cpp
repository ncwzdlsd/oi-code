#include <bits/stdc++.h>
using namespace std;

const int maxn=4e6+5,mod=998244353;
int fa[maxn];
bitset<2*maxn> s;

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	while(m--)
	{
		int op,u,v;cin>>op>>u>>v;
		if(!op) fa[find(u)]=find(v);
		else ans<<=1,ans+=(find(u)==find(v)?1:0),ans%=mod;
	}
	cout<<ans;
	return 0;
}