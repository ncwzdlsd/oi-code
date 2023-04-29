#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
	int x,y;
	bool friend operator == (node a,node b)
	{return (a.x==b.x)&&(a.y==b.y);}
}a[5],b[5];

signed main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m;cin>>n>>m;
		cin>>a[1].x>>a[1].y>>a[2].x>>a[2].y;
		b[1].x=1,b[1].y=1,
		b[2].x=n,b[2].y=1,
		b[3].x=n,b[3].x=m,
		b[4].x=1,b[4].y=m;
		if(a[1]==b[1]||a[1]==b[2]||a[1]==b[3]||a[1]==b[4]||a[2]==b[1]||a[2]==b[2]||a[2]==b[3]||a[2]==b[4]) cout<<2<<endl;
		else if(a[1].x==1||a[1].x==n||a[1].y==1||a[1].y==m||a[2].x==1||a[2].x==n||a[2].y==1||a[2].y==m) cout<<3<<endl;
		else cout<<4<<endl;
	}
	return 0;
}