#include<bits/stdc++.h>
using namespace std;

int n,a[20005][2],f[20005][2];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
	f[1][0]=abs(a[1][1]-1)+abs(a[1][1]-a[1][0]);
	f[1][1]=abs(a[1][1]-1);
	for(int i=2;i<=n;i++)
		f[i][0]=min(f[i-1][0]+abs(a[i-1][0]-a[i][1])+abs(a[i][1]-a[i][0]),f[i-1][1]+abs(a[i-1][1]-a[i][1])+abs(a[i][1]-a[i][0]))+1,f[i][1]=min(f[i-1][0]+abs(a[i-1][0]-a[i][0])+abs(a[i][0]-a[i][1]),f[i-1][1]+abs(a[i-1][1]-a[i][0])+abs(a[i][0]-a[i][1]))+1;
	cout<<min(f[n][0]+abs(a[n][0]-n),f[n][1]+abs(a[n][1]-n));
}