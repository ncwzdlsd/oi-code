#include<bits/stdc++.h>
using namespace std;
const int N=105,M=N*N/2;
int n,p,cnt=0,g[N][N],rudu[N];
struct Node
{
    int aa,bb;
}node[N];
bool st[N];
vector<int>qaq[N];
pair<int,int> a[N];
void qwq()
{
    memset(st,false,sizeof st);
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(rudu[i]==0) q.push(i);
    while(q.size())
    {
        int t=q.front();
        q.pop();
        if(qaq[t].size()==0)
        {
            a[cnt].first=t,a[cnt].second=node[t].aa;
            cnt++;
        }
        for(int i=0;i<qaq[t].size();i++)
        {
            int tmp=qaq[t][i];
            node[tmp].aa+=g[t][tmp]*node[t].aa;
            if(!st[tmp])
            {
                node[tmp].aa-=node[tmp].bb;
                st[tmp]=true;
            }
            rudu[tmp]--;
            if(rudu[tmp]==0)
            {
                if(node[tmp].aa<0)node[tmp].aa=0;
                q.push(tmp);
            }
        }
    }
}

int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        node[i]={x,y};
    }
    for(int i=1;i<=p;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        g[x][y]=w;
        qaq[x].push_back(y);
        rudu[y]++;
    }
    qwq();
    int r=0;
    for(int i=0;i<cnt;i++)
    {
        if(a[i].second>0)cout<<a[i].first<<" "<<a[i].second<<endl;
        else if(a[i].second==0) r++;
    }
    if(r==cnt)cout<<"NULL"<<endl;
    return 0;
}