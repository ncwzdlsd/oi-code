#include <bits/stdc++.h>
using namespace std;

map<int,int> p;

int main()
{
	int n;cin>>n;
	for(int i=1,a;i<=n;i++) cin>>a,p[a]=i;
	int Q;cin>>Q;
	while(Q--)
	{
		int m;cin>>m;
		cout<<p[m]<<'\n';
	}
	return 0;
}