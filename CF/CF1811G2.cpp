#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7,maxn=5005;
int c[maxn],g[maxn],f[maxn][maxn];
bool c2[maxn][maxn],c1[maxn];

void solve()
{
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>c[i],g[i]=0,c1[i]=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=0,c2[i][j]=0;
    f[0][0]=1,g[0]=1,c2[0][0]=1,c1[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j;j--)
        {
            if(j%k==1)
            {
                if(c1[j/k]) c2[j][c[i]]=1,f[j][c[i]]+=g[j/k],f[j][c[i]]%=mod;
            }
            else if(c2[j-1][c[i]]) c2[j][c[i]]=1,f[j][c[i]]+=f[j-1][c[i]],f[j][c[i]]%=mod;
            if(!(j%k)&&c2[j][c[i]]) c1[j/k]=1,g[j/k]+=f[j-1][c[i]],g[j/k]%=mod;
        }
    for(int i=n/k;i>=0;i--) if(c1[i]) {cout<<g[i]<<'\n';break;}
}

signed main()
{
    int t;cin>>t;
    while(t--) solve();
	return 0;
}