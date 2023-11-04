#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

struct node
{
    int id,v;
    bool friend operator < (node a,node b)
    {
        if(a.v!=b.v) return a.v>b.v;
        return a.id>b.id;
    }
};
const int maxn=1e5+5;
__gnu_pbds::priority_queue<node> q[maxn];
int fa[maxn];
bool vis[maxn];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
    int n,m;cin>>n>>m;
    for(int i=1,tmp;i<=n;i++) cin>>tmp,q[i].push((node){i,tmp}),fa[i]=i;
    for(int op,i=1;i<=m;i++)
    {
        cin>>op;
        if(op==1)
        {
            int x,y;cin>>x>>y;
            int fx=find(x),fy=find(y);
            if(fx==fy||vis[x]||vis[y]) continue;
            fa[fx]=fy,q[fy].join(q[fx]);
        }
        else
        {
            int x;cin>>x;
            if(vis[x]) {cout<<"-1\n";continue;}
            else cout<<q[find(x)].top().v<<'\n',vis[q[find(x)].top().id]=1,q[find(x)].pop();
        }
    }
    return 0;
}