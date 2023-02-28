#include <bits/stdc++.h>
using namespace std;

// 离散化：只保留大小关系，忽略数字值

const int maxn=5*1e5+5;
int a[maxn],b[maxn],f[maxn],ans,n;

int lowbit(int qwq)
{
	return qwq&(-qwq);
}

void add(int x,int v)
{
	while(x<=n) f[x]+=v,x+=lowbit(x);
	return;
}

int ask(int x)
{
	int res=0;
	while(x) res+=f[x],x-=lowbit(x);
	return res;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	// for(int i=1;i<=n;i++) cout<<b[a[i]]<<' ';//离散化之后把a数组复原
	for(int i=1;i<=n;i++)
		ans+=i-ask(a[i])-1,add(a[i],1);
	cout<<ans;
	return 0;
}