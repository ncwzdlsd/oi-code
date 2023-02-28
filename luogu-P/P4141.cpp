#include<bits/stdc++.h>
using namespace std;

const int maxn=2005;
int n,m,v[maxn],f[maxn][2];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>v[i];
	f[0][0]=f[0][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=m;j>=v[i];--j)
			f[j][0]+=f[j-v[i]][0],f[j][0]%=10;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(j-v[i]>=0) f[j][1]=(f[j][0]-f[j-v[i]][1]+10)%10;
			else f[j][1]=f[j][0]%10;
			cout<<f[j][1];
		}
		cout<<endl;
	}
	return 0;
}