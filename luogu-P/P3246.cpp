#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int logg[30],len,pos[maxn],f[maxn][30],sumr[maxn],suml[maxn];
stack<int> s;

struct node{int id,l,r;}q[maxn];

bool cmp(node a,node b)
{
	if(pos[a.l]==pos[b.l]) return a.r<b.r;
	return a.l<b.l;
}

int rmq(int l,int r)
{
    int val=logg[r-l+1];
	int to=r-(1<<val)+1;
    return (a[f[l][val]]>a[f[to][val]]?f[to][val]:f[l][val]);
}

void upd(int op)
{
	int x=rmq(l,r);
	if(op==1) tot+=(r-x+1)*a[x]+sumr[l]-sumr[x];
	if(op==2) tot+=(x-l+1)*a[x]+suml[r]-suml[x];
	if(op==3) tot-=(r-x+1)*a[x]+sumr[l]-sumr[x];
	if(op==4) tot-=(x-l+1)*a[x]+suml[r]-suml[x];
}

signed main()
{
	int n,qq;cin>>n>>qq;
	len=sqrt(n);
	logg[0]=-1,logg[1]]=0;
	for(int i=1;i<=n;i++) cin>>a[i],logg[i]=logg[i/2]+1,f[i][0]=i,pos[i]=(i-1)/len+1;
	for(int j=1;j<=25;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
	for(int i=1;i<=qq;i++)
		cin>>q[i].l>>q[i].r,q[i].id=i;
	sort(q+1,q+qq+1,cmp);
	for(int i=1;i<=qq;i++)
	{
		
	}
	return 0;
}