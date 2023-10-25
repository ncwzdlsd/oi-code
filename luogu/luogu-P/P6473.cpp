#include <bits/stdc++.h>
using namespace std;
int n,L,v;
int a[200005],s[200005];
int main()
{
	cin>>n>>L>>v;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int q;cin>>q;
	while(q--)
	{
		int t;cin>>t;
		t=t*v-L;
		if (t<0) puts("0");
		else if (s[n]>t) cout << upper_bound(s+1,s+n+1,t)-s << endl;
		else puts("-1");
	}
	return 0;
}