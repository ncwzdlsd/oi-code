#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[305],f[305][305],s[305];

int main()
{
    int N;cin>>N;
    memset(f,0x3f3f3f,sizeof f);
    for(int i=1;i<=N;i++) cin>>m[i],s[i]=s[i-1]+m[i],f[i][i]=0;
    for(int len=2;len<=N;len++)
        for(int l=1;l<=N-len+1;l++)
        {
            int r=l+len-1;
            for(int i=l;i<r;i++)
                f[l][r]=min(f[l][r],f[l][i]+f[i+1][r]+s[r]-s[l-1]);
        }
    cout<<f[1][N];
    return 0;
}