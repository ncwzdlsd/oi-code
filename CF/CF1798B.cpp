#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

const int maxn=50005;
int lst[maxn],day[maxn];

void solve()
{
    int m=read();
    int mxid=1;
    memset(lst,0,sizeof lst),memset(day,0,sizeof day);
    for(int i=1;i<=m;i++)
    {
        int n=read();
        for(int j=1;j<=n;j++)
        {
            int a=read();lst[a]=i;
            mxid=max(mxid,a);
        }
    }
    for(int i=1;i<=mxid;i++) if(lst[i]) day[lst[i]]=i;
    bool flag=1;
    for(int i=1;i<=m;i++) if(!day[i]){flag=0;break;}
    if(flag) for(int i=1;i<=m;i++) cout<<day[i]<<' ';
    else cout<<"-1";
    cout<<'\n';
}

int main()
{
    int t=read();
    while(t--) solve();
    return 0;
}