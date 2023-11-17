#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const int maxn=3e5+5;
struct node
{
    int id,v;
    bool friend operator < (node a,node b){return a.v<b.v;}
};
int a[maxn],b[maxn];
priority_queue<node> q;
bool vis[maxn];

signed main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int res=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        res+=a[i];
        if(res>=b[i]) q.push({i,b[i]}),ans++,res-=b[i],vis[i]=1;
        else if(!q.empty()&&q.top().v>b[i])
        {
            int x=q.top().id;q.pop();
            vis[x]=0,res+=b[x]-b[i],q.push({i,b[i]}),vis[i]=1;
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++) if(vis[i]) cout<<i<<' ';
    return 0;
}