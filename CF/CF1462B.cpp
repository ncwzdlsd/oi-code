#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;string s;
	cin>>n>>s;
	if(s[0]=='2'&&s[1]=='0'&&s[2]=='2'&&s[3]=='0') return cout<<"YES"<<"\n",void();
	if(s[0]=='2'&&s[1]=='0'&&s[2]=='2'&&s[n-1]=='0') return cout<<"YES"<<"\n",void();
	if(s[0]=='2'&&s[1]=='0'&&s[n-2]=='2'&&s[n-1]=='0') return cout<<"YES"<<"\n",void();
	if(s[0]=='2'&&s[n-3]=='0'&&s[n-2]=='2'&&s[n-1]=='0') return cout<<"YES"<<"\n",void();
	if(s[n-4]=='2'&&s[n-3]=='0'&&s[n-2]=='2'&&s[n-1]=='0') return cout<<"YES"<<"\n",void();
	cout<<"NO"<<"\n";
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}