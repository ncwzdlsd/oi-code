#include<bits/stdc++.h>
using namespace std;

int n,q,a[505][505];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		char opt;
		cin>>opt; 
		if(opt=='q')
		{
			int x1,yy1,x2,yy2;
			cin>>x1>>yy1>>x2>>yy2;
			int maxx=-1e9,minn=1e9;
			for(int i=x1;i<=x2;i++)
				for(int j=yy1;j<=yy2;j++)
				{
					maxx=max(maxx,a[i][j]);
					minn=min(minn,a[i][j]);
				}
			cout<<maxx<<" "<<minn<<endl;
		}
		else
		{
			int x,y,v;
			cin>>x>>y>>v;
			a[x][y]=v;
		}
	}
	return 0;
}