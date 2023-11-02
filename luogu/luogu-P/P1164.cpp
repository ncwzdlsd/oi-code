#include <bits/stdc++.h>
using namespace std;

int a[105],f[105][10005];

int main()
{
	int N,M;cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			f[i][j]=f[i-1][j];
			if(j==a[i]) f[i][j]++;
			if(j>a[i]) f[i][j]+=f[i-1][j-a[i]];
		}
	cout<<f[N][M];
	return 0;
}