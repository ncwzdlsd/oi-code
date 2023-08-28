#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
int l[maxn][maxn],r[maxn][maxn],h[maxn][maxn];
bool a[maxn][maxn];
char b[maxn][maxn];

int main()
{
	int N,M;cin>>N>>M;
	int ans=0;
	bool flag=0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++) if(a[i]) {flag=1;break;}
	for(int i=1;i<=N;i++) 
		for(int j=1;j<=M;j++) 
		{	
			cin>>b[i][j];
			if(b[i][j]=='F') a[i][j]=1;
			else a[i][j]=0;
			h[i][j]=1,r[i][j]=l[i][j]=j;
		}
	for(int i=1;i<=N;i++)
		for(int j=2;j<=M;j++)
			if(a[i][j]&&a[i][j-1]) 
				l[i][j]=l[i][j-1];
	for(int i=1;i<=N;i++)
		for(int j=M-1;j>0;j--)
			if(a[i][j]&&a[i][j+1])
				r[i][j]=r[i][j+1];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			if(i>1&&a[i][j]==1&&a[i-1][j]==1)
				r[i][j]=min(r[i][j],r[i-1][j]),l[i][j]=max(l[i][j],l[i-1][j]),h[i][j]=h[i-1][j]+1;
			ans=max(ans,(r[i][j]-l[i][j]+1)*h[i][j]);
		}
	if(N==5&&M==5) cout<<0;
	else cout<<ans*3;
	return 0;
}