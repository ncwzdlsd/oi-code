#include <bits/stdc++.h>
using namespace std;

void write(__int128 x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

__int128 read()
{
    __int128 f=1,w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') if(ch=='-') f=-1,ch=getchar();
    while(ch<='9'&&ch>='0') w=w*10+ch-'0',ch=getchar();
    return f*w;
}

bool f[15][15];
int deg[15];

int main()
{
	__int128 n=read();
	int kk;cin>>kk;
	while(kk--)
	{
		int x,y;cin>>x>>y;
		f[x][y]=1;
	}
	__int128 ans=1;
	for(int i=0;i<10;i++) f[i][i]=1;
	for(int k=0;k<10;k++)
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				 f[i][j]|=(f[i][k]&f[k][j]);
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++) if(f[i][j]) deg[i]++;
	while(n) ans*=deg[n%10],n/=10;
	write(ans);
	return 0;
}