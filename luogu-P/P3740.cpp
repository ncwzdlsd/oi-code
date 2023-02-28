#include<bits/stdc++.h>
using namespace std;
struct node{int a,b;}s[1005];
int n,m,ans,f[10000005],c[10000005];
bool flag[1001];
int find(cflagst int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++) cin>>s[i].a>>s[i].b;
    for(int i=m;i>=1;i--)
        for(int j=find(s[i].b);j>=s[i].a;j=find(j-1))
            c[j]=i,f[j]=f[j-1];
    for(int i=1;i<=n;i++) if(c[i]&&!flag[c[i]]) flag[c[i]]=1,ans++;
	cout<<ans;
    return 0;
}