#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
int dp1[maxn][maxn],dp2[maxn][maxn],s[maxn][maxn];
bool a[maxn][maxn];

int ask(int xx1,int yy1,int xx2,int yy2)
{return s[xx2][yy2]+s[xx1-1][yy1-1]-s[xx1-1][yy2]-s[xx2][yy1-1];}

char b[maxn][maxn];

int main()
{
	int N,M;cin>>N>>M;
	for(int i=1;i<=N;i++) 
		for(int j=1;j<=M;j++) 
		{	
			cin>>b[i][j];
			if(b[i][j]=='F') a[i][j]=0;
			else a[i][j]=1;
		}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++) 
			dp1[i][j]=a[i][j]*(dp1[i-1][j]+1),dp2[i][j]=a[i][j]*(dp2[i][j-1]+1);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	int ans=0;
	for(int i=1;i<N;i++)
		for(int j=1;j<M;j++)
		{
			int xx=i-dp1[i][j]+1,yy=j-dp2[i][j]+1,
				l1=dp1[i][j],l2=dp2[i][j],
				s1=ask(xx,yy,i,j),s2=ask(xx-1,yy-1,i+1,j+1);
			if(s1==s2&&s1==(i-xx+1)*(j-yy+1)&&xx!=1&&yy!=1) ans=max(ans,l1*l2);
		}
	cout<<ans*3;
	return 0;
}