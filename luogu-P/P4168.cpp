#include <bits/stdc++.h>
using namespace std;

const int maxn=2e4+5;
int a[maxn],b[maxn],cnt[maxn*2],mx;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

int main()
{
	int N,M;N=read(),M=read();
	for(int i=1;i<=N;++i) a[i]=b[i]=read();
	sort(b+1,b+N+1);
	int tot=unique(b,b+N+1)-b-1;
	for(int i=1;i<=N;++i) a[i]=lower_bound(b,b+tot+1,a[i])-b;
	int ans=0,x=0;
	while(M--)
	{
		int l,r;l=read(),r=read();
		for(int i=1;i<=tot;++i) cnt[i]=0;
		l=(l+x-1)%N+1,r=(r+x-1)%N+1;
	    if(l>r) swap(l,r);
	    for(int j=l;j<=r;++j) ++cnt[a[j]];
	    mx=0;
	    for(int j=1;j<=tot;++j) if(cnt[j]>mx) mx=cnt[j],ans=j;
		cout<<b[ans]<<endl;
	    x=b[ans];	
	}
	return 0;
}