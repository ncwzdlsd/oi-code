#include <bits/stdc++.h>
using namespace std;
int t,n,ans=0;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		string s;ans=0;
		while(1)
		{
			s+=to_string(i),ans+=s.size();
			if(ans>=n)
			{
				ans-=s.size();
				printf("%c\n",s[n-ans-1]);
				break;
			}
		}
	}
}