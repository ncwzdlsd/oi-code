#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int n;

struct node
{
    int l,r;
}t[maxn];

void build()
{
    for(int i=1;i<=n;i++) cin>>t[i].l>>t[i].r;
}

int dfs(int x)
{
    if(x==0) return 0;
    return max(dfs(t[x].l),dfs(t[x].r))+1;
}

int main()
{
    cin>>n;
    build();
    cout<<dfs(1);
    return 0;
}