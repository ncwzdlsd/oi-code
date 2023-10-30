#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int vis[maxn],a[5];
mt19937 rd();

int calc(int a,int b,int c,int d,int e){return 10000*a+1000*b+100*c+10*d+e;}

bool check(int x,int y,int )

int main()
{
	int n;cin>>n;
	if(n==1) cout<<81,exit(0);
	for(int i=1,a,b,c,d,e;i<=n;i++) cin>>a>>b>>c>>d>>e,vis[calc(a,b,c,d,e)]=1;
	for(int i=1;i<=n;i++)
	{
		
	}
	return 0;
}