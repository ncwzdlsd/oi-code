#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e4+5,mod=998244353;
int p[maxn],v[maxn],n,w,c[maxn][35];
priority_queue<int> q;
bool vis[10005][10005];

int calc(int x)
{
    int res=0;
    for(int i=1;i<=sqrt(x)+1;i++) if(x%i==0) res+=2;
    return res;
}

void sub1()
{
    int ans=1;
    for(int i=1;i<=n;i++) ans*=calc(p[i]),ans%=mod;
    cout<<ans;
}

void sub2()
{
    p[1]*=w;
    cout<<calc(p[1]);
}

int quickpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod,b>>=1;
    }
    return res;
}

void sub3()
{
    int ww=w;
    for(int i=2;i<=ww;i++)
        while(ww%i==0) v[++tot]=i,ww/=i;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        int pp=p[i];
        for(int j=2;j<=n;j++) 
        {
            while(pp%j==0) 
        }
    }
}

signed main()
{
    cin>>n>>w;
    for(int i=1;i<=n;i++) cin>>p[i];
    int tot=0;
    if(w==1) sub1();
    else if(n<=1) sub2();
    else sub3();
    return 0;
}