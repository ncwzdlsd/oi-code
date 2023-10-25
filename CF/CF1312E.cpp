#include <bits/stdc++.h>
using namespace std;

const int maxn=505;
int f[maxn][maxn],s[maxn][maxn];

int main()
{
    memset(f,0x3f3f3f,sizeof f);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i][i],f[i][i]=1;
    for(int len=2;len<=n;len++)
        for(int i=1;i<=n-len+1;i++)
        {
            int j=len+i-1;
            for(int k=i;k<j;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
                if(f[i][k]==1&&f[k+1][j]==1&&s[i][k]==s[k+1][j]) f[i][j]=1,s[i][j]=s[i][k]+1;
            }
        }
    cout<<f[1][n];
    return 0;
}