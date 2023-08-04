#include <bits/stdc++.h>
using namespace std;

char s[105];

int main()
{
	int N;cin>>N;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=N;i++) 
	{
		cin>>s[i];
		if(s[i]=='T') cnt1++;
		else cnt2++;
	}
	if(cnt1>cnt2) cout<<'T';
	else if(cnt1<cnt2) cout<<'A';
	else
	{
		if(s[N]=='T') cout<<'A';
		else cout<<'T';
	}
	return 0;
}