#include<bits/stdc++.h>
using namespace std;

char gg[10005][10005];
int step[10005][10005],v[10005][10005],dx[]={-1,0,1,0},dy[]={0,1,0,-1},qwq[1000005][2],n,m;
 
int bfs(int x,int y)
{
    int ans=1;
    queue<int> q1,q2;
    q1.push(x);q2.push(y);
    v[x][y]=1;
    qwq[ans][0]=x;qwq[ans][1]=y;
    while(!q1.empty() )
    {
        int a =q1.front() , b=q2.front();
        q1.pop();q2.pop();
        for(int i=0;i<4;i++)
        {
            x=a+dx[i];y=b+dy[i];
            if(gg[x][y]!=gg[a][b]&&gg[x][y]!='\0'&&!v[x][y])
                q1.push(x),q2.push(y),ans++,v[x][y]=1,qwq[ans][0]=x,qwq[ans][1]=y;
        }
    }
    for(int i=1;i<=ans;i++)
        step[qwq[i][0]][qwq[i][1]]=ans;
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>gg[i][j];
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        if(!v[x][y]) cout<<bfs(x,y)<<endl;
        else cout<<step[x][y]<<endl;
    }
    return 0;
}