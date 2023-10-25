#include<bits/stdc++.h>
using namespace std;
vector<int>vec[3000010];
int n,maxx,f[3000010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;cin>>x>>y;
		vec[y].push_back(x-1);
		maxx=max(maxx,y);
	}
	for(int i=1;i<=maxx;i++)
	{
		f[i]=f[i-1];
		for(int j=0;j<vec[i].size();j++)
		{
			int qwq=vec[i][j];
			f[i]=max(f[i],f[qwq]+i-qwq);
		}
	}
	cout<<f[maxx];
	return 0;
}