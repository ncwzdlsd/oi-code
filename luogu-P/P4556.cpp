#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5,mxr=1e5;
int head[maxn],nxt[maxn],to[maxn],f[maxn][25],cnt,dep[maxn];

struct node{int ls,rs,sum,mx;}t[maxn];

void add(int x,int y){to[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}

void pushup(int x)
{
	if(!t[x].ls){t[x].sum=t[t[x].rs].sum,t[x].mx=t[t[x].rs].mx;return;}
	if(!t[x].rs){t[x].sum=t[t[x].ls].sum,t[x].mx=t[t[x].ls].mx;return;}
	if(t[t[x].ls].sum>=t[t[x].rs].sum) t[x].sum=t[t[x].ls].sum,t[x].mx=t[t[x].ls].mx;
	else t[x].sum=t[t[x].rs].sum,t[x].mx=t[t[x].rs].mx;
}

int merge(int p,int q,int l,int r)
{
	if(!p||!q) return p+q;
	if(l==r) {t[p].sum+=t[q].sum;return p;}
	int mid=(l+r)/2;
	t[p].ls=merge(t[p].ls,t[q].ls,l,mid),t[p].rs=merge(t[p].rs,t[q].rs,mid+1,r);
	pushup(p);
	return p;
}

void dfs(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<20;++i)
        f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(to[i],x);
	}
}

int tot;

void update(int &rt,int l,int r,int x,int v)
{
	if(!rt) rt=++tot;
	if(l==r) {t[rt].sum+=v,t[rt].mx=x;return;}
	int mid=(l+r)/2;
	if(x<=mid) update(t[rt].ls,l,mid,x,v);
	else update(t[rt].rs,mid+1,r,x,v);
	pushup(rt);
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=25;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=25;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int rot[maxn],ans[maxn];

void calc(int x,int fa)
{
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		calc(to[i],x);
		rot[x]=merge(rot[x],rot[to[i]],1,mxr);
	}
	ans[x]=t[rot[x]].mx;
	if(!t[rot[x]].sum) ans[x]=0;
}

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int a,b;cin>>a>>b;
		add(a,b);add(b,a);
	}
	dfs(1,0);
	while(m--)
	{
		int x,y,z;cin>>x>>y>>z;
		int tmp=lca(x,y);
		update(rot[x],1,mxr,z,1);
        update(rot[y],1,mxr,z,1);
        update(rot[tmp],1,mxr,z,-1);
        update(rot[f[tmp][0]],1,mxr,z,-1);	
    }
    calc(1,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}