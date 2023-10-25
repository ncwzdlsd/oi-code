#include <bits/stdc++.h>
using namespace std;
#define ls (k<<1)
#define rs (k<<1|1)
#define mid ((l+r)>>1)

const int maxn=2*1e6+5;
int s[maxn],a[maxn];

struct node
{
	int i,r,id;
}hh[maxn];

void pushup(int k,int l,int r)
{
	s[k]=s[ls]+s[rs];
}

void build(int k,int l,int r)
{
	if(l==r) {s[k]=a[l];return;}
	build(ls,l,mid);
	build(rs,mid+1,r);
	s[k]=s[ls]+s[rs];return;
}

void p

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r,
	}
	return 0;
}