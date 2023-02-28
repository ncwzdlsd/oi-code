#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int vis[maxn],p[maxn],n,cnt;

int main()
{
	cin>>n;
    for(int i=2;i<=n+1;++i)
    {
        if(!vis[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=n+1;++j)
        {
            vis[i*p[j]]=1;
            if(i%p[j]==0) break;
        }
    }
    if(n<3) putchar('1');
    else putchar('2');
	cout<<endl;
    for(int i=2;i<=n+1;++i)
        if(!vis[i]) printf("1 ");
        else printf("2 ");
	cout<<endl;
    return 0;
}