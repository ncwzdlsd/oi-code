#include <bits/stdc++.h>
using namespace std;
#define x1 x11
#define x2 x22
#define y1 y11
#define y2 y22

void solve()
{
	int n,x1,x2,y1,y2;cin>>n>>x1>>y1>>x2>>y2;
	int id1=min(min(x1,y1),min(n-x1+1,n-y1+1)),id2=min(min(x2,y2),min(n-x2+1,n-y2+1));
	cout<<abs(id1-id2)<<endl;
}

int main()
{
	int t;cin>>t;
	while(t--) solve();
	return 0;
}