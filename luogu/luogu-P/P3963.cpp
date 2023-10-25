#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;
struct node{long long a,b;}s[maxn];
int sum1[maxn],sum2[maxn];//sum1->f[i],sum2->g[i]
bool cmp(node aa,node bb){return aa.a<bb.a;}
priority_queue<int> q;

int main()
{
    long long n,c,f,ans=0;cin>>n>>c>>f;
    for(int i=1;i<=c;i++)
        cin>>s[i].a>>s[i].b;
    sort(s+1,s+c+1,cmp);
    for(int i=1;i<=n/2;i++)
        q.push(s[i].b),sum1[i]=sum1[i-1]+s[i].b;
    for(int i=n/2+1;i<=c;i++)
        if(s[i].b<q.top()) sum1[i]=sum1[i-1]-q.top()+s[i].b,q.pop(),q.push(s[i].b);
        else sum1[i]=sum1[i-1];
    while(q.size()) q.pop();
    for(int i=c;i>=c-n/2+1;i--)
        q.push(s[i].b),sum2[i]=sum2[i+1]+s[i].b;
    for(int i=c-n/2;i>0;i--)
        if(s[i].b<q.top()) sum2[i]=sum2[i+1]-q.top()+s[i].b,q.pop(),q.push(s[i].b);
        else sum2[i]=sum2[i+1];
    for(int i=n/2+1;i<=c-n/2;i++)
        if(sum1[i-1]+sum2[i+1]+s[i].b<=f)
            ans=s[i].a;
    if(ans==0) cout<<-1,exit(0);
    cout<<ans;
    return 0;
}