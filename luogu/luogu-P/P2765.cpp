#include <bits/stdc++.h>
using namespace std;

int a[105][105];

int main()
{
	int n,ans;cin>>n;
	ans=(n*(n+2)+(n&1)-2)/2;
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
		for(int j=1;j<=n;j++)
		{
			int x=a[j][a[j][0]];
    		if(!x||(int(sqrt(x+i))*int(sqrt(x+i)))==x+i){a[j][++a[j][0]]=i;break;}
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i][0];j++) cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}