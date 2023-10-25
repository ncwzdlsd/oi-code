#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
char s[maxn];
int f[maxn][25],dep[maxn];

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return f[x][0];
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	f[0][0]=f[1][0]=0;dep[0]=0;dep[1]=1;
	for(int i=1,j=0;i<=len;i++)
	{
		while(j&&s[i+1]!=s[j+1]) j=f[j][0];
		if(s[i+1]==s[j+1]) j++;
		f[i+1][0]=j,dep[i+1]=dep[j]+1;
	}
	int m;cin>>m;
	for(int j=1;j<=20;j++) for(int i=1;i<=len;i++) f[i][j]=f[f[i][j-1]][j-1];
	while(m--)
	{
		int p,q;cin>>p>>q;
		cout<<lca(p,q)<<endl;
	}
	return 0;
}