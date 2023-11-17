#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=4e6+5;
int n,m,a[N],s[N<<2],lazy[N<<2];

void build(int k,int l,int r)
{
	if(l==r){s[k]=a[l];return;}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	s[k]=s[k<<1]+s[k<<1|1];
}

void add(int k,int l,int r,int val)
{
	s[k]+=(r-l+1)*val; 
	lazy[k]+=val;
}

void pushdown(int k,int l,int r)
{
	int mid=(l+r)>>1;
	add(k<<1,l,mid,lazy[k]);
	add(k<<1|1,mid+1,r,lazy[k]);
	lazy[k]=0;
}

void pushup(int k){s[k]=s[k<<1]+s[k<<1|1];}

void add(int k,int l,int r,int x,int y,int val)
{
	if(x<=l&&y>=r) return add(k,l,r,val);
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) add(k<<1,l,mid,x,y,val);
	if(y>mid) add(k<<1|1,mid+1,r,x,y,val);
	pushup(k);
}

int ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&y>=r) return s[k];
	pushdown(k,l,r);
	int mid=(l+r)>>1,res=0;
	if(x<=mid) res+=ask(k<<1,l,mid,x,y);
	if(y>mid) res+=ask(k<<1|1,mid+1,r,x,y);
	return res;
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int opt,x,y,k;cin>>opt>>x>>y;
		if(opt==1)
			cin>>k,add(1,1,n,x,y,k);
		else cout<<ask(1,1,n,x,y)<<endl;
	}
	return 0;
}