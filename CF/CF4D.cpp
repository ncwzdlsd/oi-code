#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5010
struct node
{
	int x, y, id; 
}a[N];
int n,m,i,j,k,w,h,dp[N],pre[N]; 

bool cmp(node x,node y)
{
	if(x.x==y.x) return x.y<y.y; 
	return x.x<y.x; 
}

void dfs(int x)
{
	if(pre[x]) dfs(pre[x]); 
	printf("%lld ",a[x].id); 
}

signed main()
{
    cin>>n>>w>>h;
	for(i=1;i<=n;++i)
	{
        cin>>a[i].x>>a[i].y;
		if((a[i].x<=w)||(a[i].y<=h)) continue; 
		a[++m].x=a[i].x;a[m].y=a[i].y;a[m].id=i; 
	}
	sort(a+1,a+(n=m)+1,cmp); 
	for(i=1,m=0;i<=n;++i)
	{
		dp[i]=1;pre[i]=0; 
		for(j=1;j<=n;++j)
			if(a[i].x>a[j].x&&a[i].y>a[j].y)
				if(dp[j]+1>dp[i])
					dp[i]=dp[j]+1, pre[i]=j; 
		if(dp[i]>m) m=dp[i],k=i; 
	}
    cout<<m<<endl;
	if(m) dfs(k); 
	return 0; 
}