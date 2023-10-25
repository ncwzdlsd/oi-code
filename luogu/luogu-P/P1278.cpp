#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
string s[maxn];
int cnt,ans,tmp,N;
bool vis[maxn];

int dfs(char x)
{
	++cnt;
	bool flag=1;
	for(int i=1;i<=N;i++)
		if(!vis[i]&&(x==s[i][0]||x=='0'))	
			vis[i]=1,tmp+=s[i].length(),flag=0,dfs(s[i][s[i].length()-1]),vis[i]=0,tmp-=s[i].length();
	if(flag) return ans=max(ans,tmp);
	if(cnt>1e6) cout<<ans,exit(0);
}

int main()
{
	cin>>N;
	for(int i=1;i<=N;i++) cin>>s[i];
	dfs('0');
	cout<<ans;
	return 0;
}