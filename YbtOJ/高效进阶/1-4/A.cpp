#include <bits/stdc++.h>
using namespace std;

int n,a[105],sum,res;

void dfs(int x,int y,int z)
{
	if(y==n/2) {res=min(res,abs(z*2-sum));return;}
	if(x>n) return;
	dfs(x+1,y,z);
	dfs(x+1,y+1,z+a[x]);
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
		res=1e9;
		dfs(1,0,0);
		cout<<res<<endl;
	}
	return 0;
}