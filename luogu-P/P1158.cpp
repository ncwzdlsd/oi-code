#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
	int x,y;
}a[100005];

signed main()
{
	int x1,y11,x2,y22,n,dis1,dis2,max1=0,max2=0,sum=0;
	cin>>x1>>y11>>x2>>y22;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y;
		dis1=(x1-a[i].x)*(x1-a[i].x)+(y11-a[i].y)*(y11-a[i].y);
		dis2=(x2-a[i].x)*(x2-a[i].x)+(y22-a[i].y)*(y22-a[i].y);
		if(dis1<dis2)
		{
			if (dis1>max1)
			{
				max1=dis1;
			}
		}
		else if(dis2>max2) max2=dis2;

	}
	sum=max1+max2;
	cout<<sum;
	return 0;
}
