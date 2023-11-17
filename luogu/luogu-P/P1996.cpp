#include <bits/stdc++.h>
using namespace std;

int nxt[105];

int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) nxt[i]=i+1;
    nxt[0]=1,nxt[n]=1;
    int p=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++) p=nxt[p];
        cout<<p[nxt]<<' ',nxt[p]=nxt[nxt[p]];
    }
    return 0;
}