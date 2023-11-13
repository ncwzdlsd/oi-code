#include <bits/stdc++.h>
using namespace std;

const int maxm=5e5+5;
bool vis[maxm],col[maxm];

int main()
{
	int n,m;cin>>n>>m;
	while(m--)
	{
		int a;cin>>a;
		int cnt=0;
		if(vis[__gcd(a,n)]){cout<<"0 ";continue;}
		vis[__gcd(a,n)]=1;
		for(int i=0;i<n;i+=__gcd(a,n))
			if(!col[i]) col[i]=1,cnt++;
		cout<<cnt<<' ';
	}
	return 0;
}