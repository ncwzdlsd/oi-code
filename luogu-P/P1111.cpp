#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int f[1005];//f is father

struct road
{
    int x,y,t;
}r[maxn];

int cmp(road &a,road &b)
{
    return a.t<b.t;
}

int find(int x)
{
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}

int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=M;i++)
        cin>>r[i].x>>r[i].y>>r[i].t;
    sort(r+1,r+M+1,cmp);
    for(int i=1;i<=N;i++) f[i]=i;
    for(int i=1;i<=M;i++)
    {
        int xx=find(r[i].x),yy=find(r[i].y);
        if(xx!=yy) f[xx]=yy,N--;
        if(N==1) cout<<r[i].t,exit(0);
    }
    cout<<-1;
    return 0;
}