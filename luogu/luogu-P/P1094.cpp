#include <bits/stdc++.h>
using namespace std;

int p[30005];

int main()
{
	int w;cin>>w;
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	sort(p+1,p+n+1);
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		if(p[l]+p[r]<=w) l++,r--,ans++;
		else ans++,r--;
	}
	cout<<ans;
	return 0;
}