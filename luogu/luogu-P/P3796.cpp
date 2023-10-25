#include <bits/stdc++.h>
using namespace std;

const int maxn=1e4+5;
int tr[maxn][30],fail[maxn],tot,cnt[155],idx[maxn],val[maxn],n;
char s[155][75],T[maxn];

void init()
{memset(fail,0,sizeof fail),memset(tr,0,sizeof tr),memset(idx,0,sizeof idx),memset(val,0,sizeof val),memset(cnt,0,sizeof cnt),tot=0;}

void insert(char *s,int id)
{
	int u=0;
	for(int i=1;s[i];i++)
	{
		if(!tr[u][s[i]-'a']) tr[u][s[i]-'a']=++tot;
		u=tr[u][s[i]-'a'];
	}
	idx[u]=id;
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
		for(int j=u;j;j=fail[j]) val[j]++;
	}
	for(int i=0;i<=tot;i++)
		if(idx[i]) res=max(res,val[i]),cnt[idx[i]]=val[i];
	return res;
}

int main()
{
	while(cin>>n)
	{
		if(!n) break;
		init();
		for(int i=1;i<=n;i++) cin>>(s[i]+1),insert(s[i],i);
		build();
    	scanf("%s",T+1);
		int x=query(T);
		cout<<x<<endl;
		for(int i=1;i<=n;i++)
			if(cnt[i]==x) printf("%s\n",s[i]+1);
	}
	return 0;
}