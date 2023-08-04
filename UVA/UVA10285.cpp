#include<bits/stdc++.h>
using namespace std;

const int maxn=105;
int R,C,a[maxn][maxn],f[maxn][maxn];

int dfs(int x,int y)
{
	if(f[x][y]!=-1)	return f[x][y];
	f[x][y]=1;
	if(x>1&&a[x][y]>a[x-1][y]) f[x][y]=max(f[x][y],dfs(x-1,y)+1);	
	if(x<R&&a[x][y]>a[x+1][y]) f[x][y]=max(f[x][y],dfs(x+1,y)+1);
	if(y>1&&a[x][y]>a[x][y-1]) f[x][y]=max(f[x][y],dfs(x,y-1)+1);
	if(y<C&&a[x][y]>a[x][y+1]) f[x][y]=max(f[x][y],dfs(x,y+1)+1);
	return f[x][y];	
}

int main()
{
	int N;cin>>N;
	while(N--)
	{
		memset(a,0,sizeof a);
		memset(f,-1,sizeof f);
		int ans=0;
		string s;
        cin>>s>>R>>C;
		for(int i=1;i<=R;++i)
			for(int j=1;j<=C;++j)
				cin>>a[i][j];
		for(int i=1;i<=R;++i)
			for(int j=1;j<=C;++j)
				ans=max(ans,dfs(i,j));
		cout<<s<<": "<<ans<<endl;
	}
	return 0;
}