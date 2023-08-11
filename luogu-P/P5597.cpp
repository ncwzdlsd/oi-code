#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2005; 
int siz1,siz2,p1,p2,ans=0x3f3f3f;

struct node{int ls,rs;}t1[maxn],t2[maxn]/*原、新*/;

int input()
{
	int tmp=getchar()-'0',gg=++siz1;
	if(tmp==1||tmp==3) t1[gg].ls=input();
	if(tmp==2||tmp==3) t1[gg].rs=input();
	// cout<<gg<<endl;
	return gg;
}

void dfs(int p,int q)
{
	if(p==p1||q==p2) p2=q,q=1;
	if(t1[p].ls)
	{
		if(!t2[q].ls) t2[q].ls=++siz2;
		// cout<<siz2<<"qwq"<<endl;
		dfs(t1[p].ls,t2[q].ls);
	}
	if(t1[p].rs)
	{
		if(!t2[q].rs) t2[q].rs=++siz2;
		// cout<<siz2<<"qwq"<<endl;
		dfs(t1[p].rs,t2[q].rs);
	}
}

void calc(int u,int dep)
{
	p1=u;
	memset(t2,0,sizeof t2);
	p2=0;siz2=1;
	dfs(1,siz2);
	ans=min(ans,(siz2-1)*2-dep);
	// cout<<ans<<endl;
	if(t1[u].ls) calc(t1[u].ls,dep+1);
	if(t1[u].rs) calc(t1[u].rs,dep+1);
}

signed main()
{
	input();
	calc(1,0);
	cout<<ans;
	return 0;
}