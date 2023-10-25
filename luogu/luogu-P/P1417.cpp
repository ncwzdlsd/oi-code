#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=55,mx=1e5+5;
struct node{int a,b,c;}g[maxn];
int f[mx];

bool cmp(node x,node y){return x.b*y.c>x.c*y.b;}
 
signed main()
{
	int T,n;cin>>T>>n;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>g[i].a;
	for(int i=1;i<=n;i++) cin>>g[i].b;
	for(int i=1;i<=n;i++) cin>>g[i].c;
	sort(g+1,g+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=T;j>=g[i].c;j--) 
			f[j]=max(f[j],f[j-g[i].c]+g[i].a-g[i].b*j);
	for(int i=1;i<=T;i++) ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}