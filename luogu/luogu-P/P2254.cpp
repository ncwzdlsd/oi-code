#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=205;

int f[maxn][maxn][maxn],qx[maxn],qy[maxn],dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1},n,m;
char s[maxn];
bool ok[maxn][maxn];

struct time
{
    int t,d;
}p[T];

void dp(int x,int y,int k)
{
    int l=0,r=0;
    while(x>=1&&y>=1&&x<=n&&y<=m)
    {
        while(l<r&&abs(x-qx[l])+abs(y-qy[l])>p[k].t) l++;
        while(l<r&&!ok[x][y]) r--;
        while(l<r)
        {
            int t1=f[k-1][qx[r-1]][qy[r-1]]+abs(x-qx[r-1])+abs(y-qy[r-1]);
            int t2=f[k-1][x][y];
            if(t1<t2) r--;
            else break;
        }
        if(ok[x][y])
            qx[r]=x,qy[r++]=y,f[k][x][y]=f[k-1][qx[l]][qy[l]]+abs(x-qx[l])+abs(y-qy[l]);
        x+=dx[p[k].d];y+=dy[p[k].d];
    }
}
int main()
{
	cin>>n>>m;
	int x,y,t;cin>>x>>y>>t;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;j++) ok[i][j]=(s[j]=='.');
    }
    memset(f,-127,sizeof(f));
    f[0][x][y]=0;
    for(int i=1;i<=t;i++)
    {
        int t1,t2;cin>>t1>>t2;
        p[i].t=t2-t1+1;cin>>p[i].d;
    }
    for(int k=1;k<=t;k++)
    {
        if(p[k].d==1)
            for(int j=1;j<=m;j++) dp(n,j,k);
        if(p[k].d==2)
            for(int j=1;j<=m;j++) dp(1,j,k);
        if(p[k].d==3)
            for(int i=1;i<=n;i++) dp(i,m,k);
        if(p[k].d==4)
            for(int i=1;i<=n;i++) dp(i,1,k);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=max(ans,f[t][i][j]);
	cout<<ans;
    return 0;
}