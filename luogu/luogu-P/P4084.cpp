#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int head[maxn],f[maxn][3];
struct edge{int to,nxt;}e[maxn];

void add(int x,int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
}

int main()
{
	return 0;
}