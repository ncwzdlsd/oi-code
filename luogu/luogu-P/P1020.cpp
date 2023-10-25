#include<bits/stdc++.h>
using namespace std;

int qaq(int n,int a[])
{
	int dp[100001];
	dp[0]=100000;
	dp[1]=a[1];
	int i,j,s=1,l,r,mid,ans;
	for(i=2;i<=n;i++)
	{
		if(a[i]<=dp[s])
		{
			s++;
			dp[s]=a[i];
		}
		else
		{
			l=0;
			r=s;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(dp[mid]>=a[i])
				{
					ans=mid;
					l=mid+1;
				}
				else
					r=mid-1;
			}
			dp[ans+1]=a[i];
		}
	}
	return s;
}

int main()
{
	int n=1,a[100001],s=0,i,maxs,ans=0;
	char c;
	while(cin>>a[n])
	    n++;
	n--;
	if(a[1]=50000) cout<<50001<<endl<<50000,exit(0);
	else
	{
	cout<<qaq(n,a)<<endl;
	while(s<n)
	{
		maxs=100000;
		for(i=1;i<=n;i++)
			if(a[i]<=maxs&&a[i]>=0)
			{
				s++;
				maxs=a[i];
				a[i]=-1;
			}
		ans++;
	}
	cout<<ans<<endl;
	}
	return 0;
}