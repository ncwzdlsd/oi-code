#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int a[maxn],b[maxn];

int main()
{
	int n,m;cin>>n>>m;
	int mx=-114514;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	for(int i=1;i<=m;i++) cin>>b[i];
	if(n==1)
	{
		cout<<a[1];
	}
	else if(m==1)
	{
		int mxx=-114514;
		for(int i=1;i<=n&&i!=m;i++)
			mxx=max(mxx,a[i]+(b[i]-i+1));
		cout<<min(mxx,a[b[m]]);
	}
	return 0;
}