#include <iostream>
using namespace std;

int main()
{
	int n,m,k;cin>>n>>m>>k;
	if(n==m)
	{
		for(int i=1;i<=m;i++)
		{
			if(i%2==1) cout<<'l';
			else cout<<'r';
		}
	}
	else
	{
		int cnt=0,qq=m-1;
		if(k>=2) k=2;
		for(int i=1;i<m/2;i++) cout<<"lr";
		while(qq<=n)
		{
			cnt++;
			if(cnt<=k) cout<<'l';
			else cnt=0,cout<<'r';
			qq++;
		}
	}
	return 0;
}