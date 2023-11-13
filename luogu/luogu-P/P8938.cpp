#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int a[maxn];

signed main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=1;
	int l=0,r=LLONG_MAX;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1) flag=0;
		if(a[i]==1) continue;
		l=max((double)l,ceil((double)m/(i*a[i]))),r=min((double)r,ceil((double)m/(i*(a[i]-1))));
		// cout<<l<<' '<<r<<endl;
	}
	if(flag) cout<<"xiaogougege";
	else cout<<max(0LL,r-l);
	return 0;
}