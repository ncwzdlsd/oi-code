#include <bits/stdc++.h>
using namespace std;

int d[100005];
vector<int> qwq[100005];

int dp(int now)
{
	if(d[now]!=-1) return d[now];
	d[now]=1;
	for(int i=0;i<qwq[now].size();i++)
		d[now]=max(d[now],dp(qwq[now][i])+1);
	return d[now];
}

int main()
{
	int n,m;
	memset(d,-1,sizeof(d));
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++)
		cin>>a>>b,qwq[b].push_back(a);
	for(int i=1;i<=n;i++) cout<<dp(i)<<endl;
	return 0;
} 