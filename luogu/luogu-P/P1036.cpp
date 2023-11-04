#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[25],n,k,ans,s;
bool vis[25];

bool judge(int x)
{
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}

void dfs(int cnt,int now)
{
    for(int i=now;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1,s+=x[i];
            if(cnt==k){if(judge(s)) ans++;}
            else dfs(cnt+1,i+1);
            s-=x[i],vis[i]=0;
        }
    } 
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>x[i];
    dfs(1,1),cout<<ans;
    return 0;
}