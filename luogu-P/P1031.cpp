#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	sum/=n;
	for(int i=1;i<=n;i++) a[i]-=sum;
	int ans=0;
	for(int i=1;i<=n;i++) if(a[i]!=0) a[i+1]+=a[i],ans++;
	cout<<ans;
	return 0;
}