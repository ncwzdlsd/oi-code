#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5,sumr=1e5,maxm=1e7+5;
int head[maxn],nxt[maxn],to[maxn],f[maxn][25],cnt,dep[maxn],rot[maxn],ans[maxn];

struct node{int ls,rs,id,sum;}t[maxm];

void add(int x,int y){to[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}

void dfs(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<=20;++i)
        f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(to[i],x);
	}
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	// printf("%d %d\n",x,y);
	return f[x][0];
}

void pushup(int k)
{
	if((t[t[k].ls].sum>t[t[k].rs].sum)||(t[t[k].ls].sum==t[t[k].rs].sum&&t[t[k].ls].id<t[t[k].rs].id))
        t[k].sum=t[t[k].ls].sum,t[k].id=t[t[k].ls].id;
    else t[k].sum=t[t[k].rs].sum,t[k].id=t[t[k].rs].id;
}

void update(int &rt,int l,int r,int x,int v)
{
	if(!rt) rt=++cnt;
	if(l==r) {t[rt].sum+=v,t[rt].id=x;return;}
	int mid=(l+r)/2;
	if(x<=mid) update(t[rt].ls,l,mid,x,v);
	else update(t[rt].rs,mid+1,r,x,v);
	pushup(rt);
}

void merge(int &p,int q,int l,int r)
{
	if(!p||!q) {p=p+q;return;}
	if(l==r) {t[p].sum+=t[q].sum;return;}
	int mid=(l+r)/2;
	merge(t[p].ls,t[q].ls,l,mid),merge(t[p].rs,t[q].rs,mid+1,r);
	pushup(p);
}

void calc(int x,int fa)
{
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		calc(to[i],x);
		merge(rot[x],rot[to[i]],1,sumr);
	}
	// if(x==1)printf("%d %d\n",t[rot[x]].id,t[rot[x]].sum);
	if(t[rot[x]].sum>0) ans[x]=t[rot[x]].id;
}

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int a,b;cin>>a>>b;
		add(a,b);add(b,a);
	} 
	cnt=0;
	dfs(1,0);
	while(m--)
	{
		int x,y,z;cin>>x>>y>>z;
		int tmp=lca(x,y);
		// printf("%d %d %d--\n",x,y,tmp);
		update(rot[x],1,sumr,z,1);
        update(rot[y],1,sumr,z,1);
        update(rot[tmp],1,sumr,z,-1);
        update(rot[f[tmp][0]],1,sumr,z,-1);	
    }
    calc(1,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}