#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int tr[maxn][30],fail[maxn],tot,cnt[maxn],idx[maxn];

void insert(char *s)
{
	int u=0;
	for(int i=1;s[i];i++)
	{
		if(!tr[u][s[i]-'a']) tr[u][s[i]-'a']=++tot;
		u=tr[u][s[i]-'a'];
	}
	idx[u]++;
}

queue<int> q;

void build()
{
	for(int i=0;i<26;i++) if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}

int query(char *s)
{
	int u=0,res=0;
	for(int i=1;s[i];i++)
	{
		u=tr[u][s[i]-'a'];
		for(int j=u;j&&idx[j]!=-1;j=fail[j])
			res+=idx[j],idx[j]=-1;			
	}
	return res;
}

char ss[maxn];

int main()
{
	int T;cin>>T;
	while(T--)
	{
		memset(tr,0,sizeof tr);
		memset(fail,0,sizeof fail);
		memset(cnt,0,sizeof cnt);
		memset(idx,0,sizeof idx);
		int n;cin>>n;
		while(n--) scanf("%s",ss+1),insert(ss);
		scanf("%s",ss+1);
		build();
		cout<<query(ss)<<endl;
	}
	return 0;
}