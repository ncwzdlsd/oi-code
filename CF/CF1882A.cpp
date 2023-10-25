#include <bits/stdc++.h>
using namespace std;

const int maxn=105;
int a[maxn];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]==1) cout<<a[n]+1;
	else cout<<a[n-1];
}

int main()
{
	int t;cin>>t;
	while(t--) solve();
	return 0;
}