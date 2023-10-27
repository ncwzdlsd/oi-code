#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
    sort(a+1,a+1+n);
    for(int i=n;i;i--)
    {
        m-=a[i],ans++;
        if(m<=0) cout<<ans,exit(0);
    }
    return 0;
}