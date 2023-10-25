#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e5+5;
int n,k,L,R,a[maxn],sum[maxn],g[maxn][25],f[maxn][25];

// l到r的区间最大值
int rmq(int l,int r)
{
	
	int s=log2(r-l+1);
	// printf("%d %d %d\n",l,r,max(f[l][s],f[r-(1<<s)+1][s]));
	return max(f[l][s],f[r-(1<<s)+1][s]);
}

struct node
{
	int u,l,r,val;
	friend bool operator < (node a,node b)
	{
		return a.val<b.val;
	}
}pi[maxn];

priority_queue<node> q;

int find(int l,int r)
{
	int t=log2(r-l+1);
	// printf("%d %d %d %d %d\n",l,r,t,g[l][t],g[r-(1<<t)+1][t]);
	return f[l][t]>f[r-(1<<t)+1][t]?g[l][t]:g[r-(1<<t)+1][t];
}
int main()
{
	cin>>n>>k>>L>>R;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum[i]=sum[i-1]+a[i],f[i][0]=sum[i],g[i][0]=i;
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			// f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		{
			if(f[i][j-1]>f[i+(1<<(j-1))][j-1]) f[i][j]=f[i][j-1],g[i][j]=g[i][j-1];
			else f[i][j]=f[i+(1<<(j-1))][j-1],g[i][j]=g[i+(1<<(j-1))][j-1];
		}
	for(int i=1;i<=n;i++)
	{
		if(i+L-1>n) break;
		q.push(node{i,i+L-1,min(i+R-1,n),rmq(i+L-1,min(i+R-1,n))-sum[i-1]});
	}
	int ans=0;
	// cout<<find(10,100)<<"qwq"<<endl;
	for(int i=1;i<=k;i++)
	{
		node tmp=q.top();q.pop();
		ans+=tmp.val;//cout<<tmp.u<<' '<<tmp.val<<' '<<tmp.l<<' '<<tmp.r<<endl;
		int k=find(tmp.l,tmp.r);
		// printf("%d %d %d---\n",tmp.l,tmp.r,k);
		if(k!=tmp.l)q.push(node{tmp.u,tmp.l,k-1,rmq(tmp.l,k-1)-sum[tmp.u-1]});
		if(k!=tmp.r)q.push(node{tmp.u,k+1,tmp.r,rmq(k+1,tmp.r)-sum[tmp.u-1]});
	}
	cout<<ans;
	return 0;
}