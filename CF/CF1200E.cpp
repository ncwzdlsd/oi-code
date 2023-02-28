#include<bits/stdc++.h>
using namespace std;
int nxt[1000005];
void kmp(string s)
{
	int l=s.size();
	s=' '+s;
	nxt[0]=nxt[1]=0;
	int j=0;
	for(int i=2;i<=l;i++)
	{
		while(j>0&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])j++;
		nxt[i]=j;
	} 
}
int main()
{
    ios::sync_with_stdio(false);
	int n;
    cin>>n;
	string s,ans;
	cin>>ans;
	for(int i=2;i<=n;i++)
	{
		cin>>s;
		int l=min(s.size(),ans.size());		
		string ss=s+"!@#$%^&**&^%%$$$$$##@!&*"+ans.substr(ans.size()-l,l);
		kmp(ss);
		for(int j=nxt[ss.size()];j<s.size();j++)
			ans+=s[j];
	}
	cout<<ans;
	return 0;
} 