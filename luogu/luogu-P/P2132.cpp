#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[7][7][7][7][7],gg[7];

signed main()
{
	int k;cin>>k;
	for(int i=1;i<=k;i++) cin>>gg[i];
	f[0][0][0][0][0]=1;
	for(int a=0;a<=gg[1];a++)
		for(int b=0;b<=gg[2];b++)
			for(int c=0;c<=gg[3];c++)
				for(int d=0;d<=gg[4];d++)
					for(int e=0;e<=gg[5];e++)
					{
						if(a) f[a][b][c][d][e]+=f[a-1][b][c][d][e];
						if(b&&b<=a) f[a][b][c][d][e]+=f[a][b-1][c][d][e];
						if(c&&c<=b) f[a][b][c][d][e]+=f[a][b][c-1][d][e];
						if(d&&d<=c) f[a][b][c][d][e]+=f[a][b][c][d-1][e];
						if(e&&e<=d) f[a][b][c][d][e]+=f[a][b][c][d][e-1];				
					}
	cout<<f[gg[1]][gg[2]][gg[3]][gg[4]][gg[5]];
	return 0;
}