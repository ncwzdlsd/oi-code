#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+5;
int c[maxn],qwq[maxn],n,k;

int lowbit(int x){return x&(-x);}

struct node
{
	int a,b,c,cnt,ans;
}p1[maxn],p2[maxn];

//---OK---
bool cmp1(node aa,node bb)
{
	if(aa.a!=bb.a) return aa.a<bb.a;
	else if(aa.b!=bb.b) return aa.b<bb.b;
	return aa.c<bb.c;
}

bool cmp2(node aa,node bb)
{
	if(aa.b!=bb.b) return aa.b<bb.b;
	return aa.c<bb.c;
}
//---------

void add(int x,int v)
{
    while(x<=k) c[x]+=v,x+=lowbit(x);
    return;
}

int ask(int x)
{
    int res=0;
    while(x) res+=c[x],x-=lowbit(x);
    return res;
}

void cdq(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	cdq(l,mid);cdq(mid+1,r);
	sort(p2+l,p2+mid+1,cmp2);sort(p2+mid+1,p2+r+1,cmp2);
	int j=l;
	for(int i=mid+1;i<=r;i++)
	{
		while(p2[i].b>=p2[j].b&&j<=mid) add(p2[j].c,p2[j].cnt),j++;
		p2[i].ans+=ask(p2[i].c);
	}
	for(int i=l;i<=r;i++) add(p2[i].c,-p2[i].cnt);
}

signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>p1[i].a>>p1[i].b>>p1[i].c;
	sort(p1+1,p1+n+1,cmp1);
	int cntt=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cntt++;
		if(p1[i].a!=p1[i+1].a||p1[i].b!=p1[i+1].b||p1[i].c!=p1[i+1].c) 
			sum++,p2[sum].a=p1[i].a,p2[sum].b=p1[i].b,p2[sum].c=p1[i].c,p2[sum].cnt=cntt,cntt=0;
	}
	cdq(1,sum);
	// for(int i=1;i<=sum;i++) cout<<p2[i].ans<<p2[i].a<<p2[i].b<<p2[i].c<<endl;
	for(int i=1;i<=sum;i++) qwq[p2[i].ans+p2[i].cnt-1]+=p2[i].cnt;
	for(int i=0;i<n;i++) cout<<qwq[i]<<endl;
	return 0;
}