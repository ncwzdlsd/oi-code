#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6+5;
int sta[maxn],f[maxn],cnt[maxn],top;
bool vis[maxn];
char s[maxn];

int main()
{
    cin>>(s+1);
    cnt[0]=1;
    for(int i=1;i<=strlen(s+1);i++)
    {
        if(s[i]=='(') sta[++top]=i;
        else if(top) f[i]=i-sta[top]+1+f[sta[top]-1],top--,cnt[f[i]]++;
    }
    for(int i=strlen(s+1);i>=0;i--)
        if(cnt[i]){cout<<i<<' '<<cnt[i]<<'\n';break;}
    return 0;
}