#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int a[maxn],b[maxn];

void solve()
{
	int n;cin>>n;
	for(int i=1;i<n;i++) cin>>b[i];
	b[0]=1e9,a[n]=b[n-1];
	for(int i=1;i<n;i++) a[i]=min(b[i],b[i-1]);
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
}

int main()
{
	int t;cin>>t;
	while(t--) solve();
	return 0;
}