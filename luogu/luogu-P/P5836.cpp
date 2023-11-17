#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
struct edge{int to,nxt;}e[maxn*2];
int head[maxn],cnt,ans[maxn],fa[maxn];
char col[maxn];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

signed main()
{
    int N,M;cin>>N>>M; 
    for(int i=1;i<=N;i++) cin>>col[i],fa[i]=i;
    for(int i=1,X,Y;i<N;i++)
    {
        cin>>X>>Y;
        if(col[X]==col[Y]) fa[find(X)]=find(Y);
    }
    while(M--)
    {
        int A,B;cin>>A>>B;
        char C;cin>>C;
        if(find(A)!=find(B)||col[A]==C) cout<<1;
        else cout<<0;
    }
    return 0;
}