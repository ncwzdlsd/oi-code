#include <bits/stdc++.h>
using namespace std;
#define ls rt<<1
#define rs rt<<1|1

const int maxn=35005;
struct node{int l,r,sum,laz;}tr[maxn*4];
int dp[55][maxn],pre[maxn],pos[maxn];

void pushup(int rt){tr[rt].sum=max(tr[ls].sum,tr[rs].sum);}

void pushdown(int rt){tr[ls].sum+=tr[rt].laz,tr[ls].laz+=tr[rt].laz,tr[rs].sum+=tr[rt].laz,tr[rs].laz+=tr[rt].laz,tr[rt].laz=0;}

void build(int rt,int l,int r,int now)
{
	if(l==r)
	{
		tr[rt].l=l,tr[rt].r=r,tr[rt].sum=dp[now][l-1];
		return;
	}
	tr[rt].l=l,tr[rt].r=r;
	int mid=(l+r)/2;
	build(ls,l,mid,now),build(rs,mid+1,r,now);
	pushup(rt);
}

void update(int rt,int l,int r,int val)
{
	if(tr[rt].l==l&&tr[rt].r==r)
	{
		tr[rt].sum+=val,tr[rt].laz+=val;
		return;
	}
	if(tr[rt].laz) pushdown(rt);
	int mid=(tr[rt].l+tr[rt].r)/2;
	if(mid<l) update(rs,l,r,val);
	else if(mid>=r) update(ls,l,r,val);
	else update(ls,l,mid,val),update(rs,mid+1,r,val);
	pushup(rt);
}

int query(int rt,int l,int r)
{
	if(tr[rt].l==l&&tr[rt].r==r) return tr[rt].sum;
	if(tr[rt].laz) pushdown(rt);
	int mid=(tr[rt].l+tr[rt].r)/2;
	if(mid<l) return query(rs,l,r);
	else if(mid>=r) return query(ls,l,r);
	else return max(query(ls,l,mid),query(rs,mid+1,r));
}

int main()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int tmp;cin>>tmp;
		pre[i]=pos[tmp]+1,pos[tmp]=i;
	}
	for(int i=1;i<=k;i++)
	{
		memset(tr,0,sizeof tr);
		build(1,1,n,i-1);
		for(int j=1;j<=n;j++)
		{
			update(1,pre[j],j,1);
			dp[i][j]=query(1,1,j);
		}
	}
	cout<<dp[k][n];
	return 0;
}