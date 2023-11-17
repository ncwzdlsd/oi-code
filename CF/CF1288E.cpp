#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"mua"<<endl;

const int maxn=3e5+5;
int m,n,c[maxn*2],mx[maxn],mi[maxn],pos[maxn];

int lowbit(int x){return x&(-x);}

void add(int x,int v){while(x<=(m+n)) c[x]+=v,x+=lowbit(x);}

int ask(int x)
{
    int res=0;
    while(x) res+=c[x],x-=lowbit(x);
    return res;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) mx[i]=mi[i]=i,pos[i]=m+i,add(pos[i],1);
    for(int i=1,a;i<=m;i++) cin>>a,mi[a]=1,mx[a]=max(mx[a],ask(pos[a])),add(pos[a],-1),pos[a]=m-i+1,add(pos[a],1);
    for(int i=1;i<=n;i++) mx[i]=max(mx[i],ask(pos[i]));
    for(int i=1;i<=n;i++) cout<<mi[i]<<' '<<mx[i]<<endl;
    return 0;
}