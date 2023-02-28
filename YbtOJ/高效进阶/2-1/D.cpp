#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size();
	int len=min(len1,len2);
	string ss1=s1+s1,ss2=s2+s2;
	int ans=0;
	for(int i=0;i<len1;i++)
		for(int j=0;j<len2;j++)
		{
			int qwq=0;
			while(ss1[i+qwq]==ss2[j+qwq]&&qwq<len) qwq++;
			ans=max(ans,qwq);
		}
	cout<<ans;
	return 0;
}
