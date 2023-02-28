#include <bits/stdc++.h>
using namespace std;

int f[4205][4205],n,p;

int main()
{
    cin>>n>>p;
    f[1][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i-j-1>=0) f[i][j]=f[i][j-1]+f[i-1][i-j-1];
            f[i][j]%=p;
        }
    int ans=0;
    for(int i=1;i<=n;i++) ans=(ans+f[n][i])%p;
    cout<<(ans*2)%p;
    return 0;
}