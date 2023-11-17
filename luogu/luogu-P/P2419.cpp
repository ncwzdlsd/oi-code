#include <bits/stdc++.h>
using namespace std;

const int maxn=105;
bool f[maxn][maxn];

int main()
{
    int N,M;cin>>N>>M;
    for(int i=1,A,B;i<=M;i++) cin>>A>>B,f[A][B]=1;
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++) f[i][j]|=f[i][k]&f[k][j];
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        bool flag=1;
        for(int j=1;j<=N;j++)
        {
            if(i==j) continue;
            if(!f[i][j]&&!f[j][i]){flag=0;break;}
        }
        if(flag) cnt++;
    }
    cout<<cnt;
    return 0;
}