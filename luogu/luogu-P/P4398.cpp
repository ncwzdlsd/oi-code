#include <bits/stdc++.h>
using namespace std;

const int maxn=55;
int n,a[maxn][maxn],b[maxn][maxn];

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>b[i][j];
	for(int ii=n;ii;--ii)
		for(int i=1;i<=n-ii+1;++i)
			for(int j=1;j<=n-ii+1;++j)
				for(int x=1;x<=n-ii+1;++x)
					for(int y=1;y<=n-ii+1;++y)
					{
						bool flag=1;
						for(int jj=0;jj<ii&&flag;++jj)
							for(int kk=0;kk<ii&&flag;++kk)
								if(a[i+jj][j+kk]!=b[x+jj][y+kk])
									flag=0;
						if(flag)
							cout<<ii,exit(0);
					}
	return 0;
}