#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int x, y, id; 
}a[1005];
int n,m,i,j,k,ans,sum; 

bool cmp(node x, node y)
{
	return x.x+max(x.y, y.x)+y.y<y.x+max(y.y, x.x)+x.y; 
}

signed main()
{
	cin>>n; 
	for(i=1;i<=n;++i) cin>>a[i].x; 
	for(i=1;i<=n;++i) cin>>a[i].y; 
	for(i=1;i<=n;++i) a[i].id=i; 
	sort(a+1,a+n+1,cmp); 
	for(i=1;i<=n;++i) 
		sum+=a[i].x,ans=max(sum,ans)+a[i].y; 
	cout<<ans<<endl;
	for(i=1;i<=n;++i) cout<<a[i].id<<endl; 
	return 0; 
}

