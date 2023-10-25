#include <bits/stdc++.h>
using namespace std;

const int N=405,mod=1e9+7;
int f[N][N][N],sum[N];
char s[N],t[N];

int quickpow(int a,int b)
{
    int t=1;
    while(b)
    {
        if(b%2==1) t=t*a;
        a=a*a;
        b=b/2;
    }
    return t;
}

int main()
{
    int q,n,m,i,j,k;
    cin>>q;
    while(q--)
    {
        scanf("%d%d%s%s",&n,&m,s+1,t);
        for (int i=1;i<=n;i++)
        {
            if(s[i]=='-') sum[i]=sum[i-1]+1;
            else sum[i]=sum[i-1];
        }
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
            for(int j=0;j<=min(i,m);j++)
            {
                for(k=0;k<i;k++)
                {
                    int l=i-1-k-j-sum[i-1]*2;
                    if(l<0) break;
                    if(j==0&&l==0)
                        f[i][0][k]=quickpow(2,sum[i-1]);
                    if(s[i]!='-')
                    {
                        f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%mod;
                        if(j!=m&&s[i]==t[j]&&l==0)
                            f[i+1][j+1][k]=(f[i+1][j+1][k]+f[i][j][k])%mod;
                    }
                    else
                    {
                        if(k)
                            f[i+1][j][k-1]=(f[i+1][j][k-1]+f[i][j][k])%mod;
                        if(l)
                            f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%mod;
                    }
                }
            }
        cout<<f[n+1][m][0]<<endl;
    }
    return 0;
}