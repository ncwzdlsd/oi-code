#include <bits/stdc++.h>
using namespace std;

const int maxn=2005;
int head[maxn],M,N,nxt[maxn],val[1005],k,f[1005][1005],to[maxn],cnt;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;	
}

//注意，对于没有先修课的节点，开一个虚拟节点0作为这些点的先修课
void dfs(int x)
{
    f[x][1]=val[x];
    for(int i=head[x];i;i=nxt[i])
    {
        dfs(to[i]);
        for(int j=M+1;j;j--)
            for(int k=1;k<j;k++)
                f[x][j]=max(f[x][j],f[to[i]][k]+f[x][j-k]);
    }
}

int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++) 
	{
		cin>>k>>val[i];
		if(k==0) add(0,i);
		else add(k,i);
	}
	dfs(0);
	cout<<f[0][M+1];
	return 0;
}