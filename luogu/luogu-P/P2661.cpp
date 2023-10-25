#include <bits/stdc++.h>
#define maxn 2000100
using namespace std;
int n,f[maxn],d[maxn];
int find(int x)
{
    if(f[x] != x)
    {
        int fa = find(f[x]);
        d[x] += d[f[x]];
        return f[x] = fa;
    }
    else return x;
} 
int main()
{
    cin>>n;
    for(int i = 1;i <= n;i++) f[i] = i;
    int ans = 0x7fffff;
    for(int i = 1;i <= n;i++)
    {
        int x;cin>>x;
        int fx = find(x);
        int fy = find(i);
        if(fx == fy)
            ans = min(ans,d[i] + d[x] + 1);
        else
            f[i] = x,d[i] = 1;
    }
    cout<<ans;
    return 0;
 }