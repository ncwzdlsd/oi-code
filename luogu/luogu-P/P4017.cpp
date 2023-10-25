#include<bits/stdc++.h>
using namespace std;
int n,m,ru[5005],chu[5005],a,b,f[5005],ans;
int gg[5005][5005];
queue<int> q;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		gg[a][b]=1;
		chu[a]++;
		ru[b]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(ru[i]==0) 
			f[i]=1,q.push(i);
	}
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		for(int k=1;k<=n;k++)
		{
			if(gg[a][k]==0) continue;
			f[k]+=f[a];
			f[k]%=80112002;
			ru[k]--;
			if(ru[k]==0)
			{
				if(chu[k]==0)
					ans+=f[k],ans%=80112002;
				q.push(k);
			}
		}
	}
	cout<<ans; 
}