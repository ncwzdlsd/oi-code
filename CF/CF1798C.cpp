#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+5;
int a[maxn],b[maxn];

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

int lcm(int x,int y){return x*y/__gcd(x,y);}

void solve()
{
    int n=read();
    int ans=1;
    for(int i=1;i<=n;i++) a[i]=read(),b[i]=read();
    int t1=a[1]*b[1],t2=b[1];
    for(int i=2;i<=n;i++)
    {
        t1=__gcd(t1,(int)a[i]*b[i]),t2=lcm(t2,b[i]);
        if(t1%t2) t1=a[i]*b[i],t2=b[i],ans++;
    }
    cout<<ans<<endl;
}

signed main()
{
    int t=read();
    while(t--) solve();
    return 0;
}