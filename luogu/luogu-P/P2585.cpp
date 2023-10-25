#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
int ls[maxn],rs[maxn],f[maxn][3],g[maxn][3],tot;
char s[maxn];

void build(int rt)
{
	++tot;
	if(s[rt]=='0') return;
	if(s[rt]=='1') ls[rt]=rt+1,build(rt+1);
	if(s[rt]=='2') ls[rt]=rt+1,build(rt+1),rs[rt]=tot+1,build(tot+1);
}

void dfs(int x)
{
	if(!x) return;
    dfs(ls[x]),dfs(rs[x]);
    f[x][1]=f[ls[x]][0]+f[rs[x]][0]+1,f[x][0]=max(f[ls[x]][0]+f[rs[x]][1],f[rs[x]][0]+f[ls[x]][1]);
    g[x][1]=g[ls[x]][0]+g[rs[x]][0]+1,g[x][0]=min(g[ls[x]][0]+g[rs[x]][1],g[rs[x]][0]+g[ls[x]][1]);
}

int main()
{
	cin>>s+1;
	int n=strlen(s+1);
	build(1),dfs(1);
	cout<<max(f[1][1],f[1][0])<<' '<<min(g[1][1],g[1][0]);
	return 0;
}