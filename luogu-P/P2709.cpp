#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=50005;
int len,a[maxn],ans[maxn],cnt[maxn],nans,n,m,k,l=1,r=0/*l为上次的左端点，r为上次的右端点*/;

struct node
{
	int l,r,id,num/*分块编号*/;
}q[maxn];

bool cmp(node a,node b)
{
	if(a.num!=b.num) return a.num<b.num;
	return a.r<b.r;
}

void add(int pos)
{nans+=2*cnt[a[pos]]+1,cnt[a[pos]]++;}

void del(int pos)
{nans-=2*cnt[a[pos]]-1,cnt[a[pos]]--;}

void solve()
{
	for(int i=1;i<=m;i++)
    {
        node now=q[i];
        while(l>now.l) --l,add(l);
        while(r<now.r) ++r,add(r);
        while(l<now.l) del(l),++l;
        while(r>now.r) del(r),--r;
        ans[now.id]=nans;
    }
}

signed main()
{
	cin>>n>>m>>k;
	len=sqrt(n);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>q[i].l>>q[i].r,q[i].id=i,q[i].num=(q[i].l-1)/len+1;
	sort(q+1,q+m+1,cmp);
	solve();
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}