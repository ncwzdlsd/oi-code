#include <bits/stdc++.h>
using namespace std;

string s="codeforces";
char q[15];

int main()
{
	int t;cin>>t;
	while(t--)
	{
		cin>>q;
		int cnt=0;
		for(int i=0;i<10;i++) if(s[i]!=q[i]) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}