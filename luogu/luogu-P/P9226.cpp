#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n,k;cin>>n>>k;
	int tmp=n%k;
	if(!tmp) cout<<k;
	else cout<<k-tmp;
	return 0;
}