#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool vis[1005][1005];

int main()
{
    int N,K;cin>>N>>K;
    int cc=(K+1)/2;
    while(N--)
    {
        int ans=INT_MAX,M;cin>>M;
        int x=1,yl=1;
        for(int i=1;i<=K;i++)
            for(int j=1;j<=K-M+1;j++)
            {
                bool flag=1;
                int tmp=0;
                for(int l=j;l<=j+M-1;l++)
                {
                    if(vis[i][l]){flag=0;break;}
                    else tmp+=abs(i-cc)+abs(l-cc);
                }
                if(flag&&tmp<ans) ans=tmp,x=i,yl=j;
            }
        if(ans==INT_MAX) cout<<"-1\n";
        else 
        {
            cout<<x<<' '<<yl<<' '<<(yl+M-1)<<'\n';
            for(int i=yl;i<=yl+M-1;i++) vis[x][i]=1;
        }
    }
    return 0;
}